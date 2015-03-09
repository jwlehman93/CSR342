#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bonds.h"


int main() {
	LinkedList mainList;
	char *names[10] = {"Face Value", "Yield Interest","Coupon Interest","n","m","P0","PVA","PV", "CF","PVFA"};
	for(int i = 0; i < 10; i++) {
		llist_add(mainList,names[i]);
		if(i < 5) {
			printf("Input value of %s and press <enter>. If value is unknown enter value as -1\n",names[i]);
			scanf("%f",&value);
			llist_add_value(mainList,value);
		}
		llist_print(list);
	}
	LinkedList unknowns;
	llist_int(unknowns);
	llist_findUnknownValues(mainList);
	bondPricing();
	
	

}



double bondPricing(LinkedList *unknowns, LinkedList *totalList) {
	ListNode *e = unknowns->head;
	ListNode *f = totalList->head;
	int ans;
	double ret;
	printf("What are you looking for?\n Choices:\n");
	for(int i = 6; i < 10; i++) 
		printf("{%d} %s\n",i-5,names[i]);
		if(i == 9) {
			while(e->next!=NULL) 
				printf("{%d} %s\n",++i-5,e->name);
	}	
	sscanf("%d",&ans);
	double pvfa = findPVFA(llist_exists(f,"Yield Interest"),llist_exists(f,"m"),llist_exists(f,"n"));
	double pva = findPVA (llist_exists(f, "CF"),llist_exists(f,"PVFA"));
	double pv = findPV(llist_exists(f,"Face Value"),llist_exists(f,"Yield Interest"),llist_exists(f,"m"),llist_exists(f,"n"));
	switch(ans) {
		case 1:
			
}	
//returns current value or -1 if a value is unknown
double findP0(double pva, double pv) {
	if(pva == -1 || pv==-1)
		return -1;
	return pva + pv;	

//returns CF or -1 if a value is unknown
double findCF(double face, double couponInterest, double m) {
	if(face==-1 || couponInterest==-1||m==-1)
		return -1;
	cf = face*couponInterest/m;
	return cf;
}
// returns PVFA or -1 if a value is unknown
double findPVFA(double yieldInterest, double m, double n) {
	if(yieldInterest==-1 || m==-1 || n==-1)
		return -1;
	pvfa = (1 - (1/pow(1+(yieldInterest/m),n*m)))/(yieldInterest/m);
}	
// returns PV or -1 if a value is unknown
double findPV(double face, double yieldInterest, double m, double n){
	if(face==-1 || yieldInterest==-1 || m==-1 || n==-1)
		return -1;	
	pv = face/pow(1+(yieldInterest/m),n*m);
	return pv;
}
// returns PVA or -1 if a value is unknown
double findPVA(double cf, double pvfa) {
	if(cf==-1 || pvfa==-1)
		return -1;
	return cf*pvfa;
}
