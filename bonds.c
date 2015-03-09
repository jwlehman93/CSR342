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
	double pva = findPVA (llist_exists(f, "CF"),llist_exists(f,"PVFA")
	switch(ans) {
		case 1:
}	


double findCF(double face, double couponInterest, double m) {
	cf = face*couponInterest/m;
	return cf;
}

double findPVFA(double yieldInterest, double m, double n) {
	pvfa = (1 - (1/pow(1+(yieldInterest/m),n*m)))/(yieldInterest/m);
	
}	

double findPV(double face, double yieldInterest, double m, double n){
	pv = face/pow(1+(yieldInterest/m),n*m);
	return pv;
}

double findPVA(double cf, double pvfa) {
	return cf*pvfa;
}
