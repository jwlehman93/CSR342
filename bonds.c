#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bonds.h"


int main() {
	LinkedList mainList;
	llist_init(mainList);
	int *value;	
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
	printf("What are you looking for?\n Choices:\n");
	for(int i = 6; i < 10; i++) 
		printf("{%d} %s\n",i-5,names[i]);
		if(i == 9) {
			while(e->next!=NULL) 
				printf("{%d} %s\n",++i-5,e->name);
	}	
	sscanf("%d",&ans);
	pva = findPVFA(interest,m,n)*findCF(face,cinterest,m);
	switch(ans){
		case 1:
			finalAns = pva + findPV(face,interest,m,n);
		case 2:
			finalAns = 
		
	}			
	for(int i = 0; i <= 5;i++) {
		printf("Enter %s\n",names[i]);
		sscanf("%f\n",&values[i]);
	}
	printf("Present Value = %f, CF = %f",presentValue,cf);
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

