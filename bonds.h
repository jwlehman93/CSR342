#include "LinkedList.h"
typedef struct List {
	int value;
	char *name;
	struct List *next;
}List;

List *head = NULL;

List *createList(List *list, char *names);
double bondPricing();
double findCF(double face, double couponInterest, double m);
double findPVFA(double yieldInterest, double m, double n);
double findPV(double face, double yieldInterest, double m, double n);
double findyieldInterest(double face, double yieldInterest, double m, double n);

double annuities();

double stockPricing();

double interest();
