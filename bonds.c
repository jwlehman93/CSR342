#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bonds.h"


int main() {
	LinkedList list;
	llist_init(list);
	int *value;	
	char names[10] = {"Face Value", "Yield Interest","Coupon Interest","n","m","P0","PVA","PV", "CF","PVFA"};
	for(int i = 0; i < 5; i++) {
		printf("Input value of %s and press <enter>\n");
		scanf("%f",&value);
		llist_add(list,value,names[i]);
		llist_print(list);
	}
	llist_add(list,findPVA,"PVA");
	llist_add(list,findPV()


}



double bondPricing() {
	double interest,m,n,cinterest,face,presentValue,cf,pvfa,pva,pv;
	printf("What are you looking for?\n Choices:\n");
	for(int i = 0; i < 6; i++) 
		printf("{%d} %s\n",i+1,names[i]);
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

