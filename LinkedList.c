
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

//
// Initialize a linked list
//
void llist_init(LinkedList * list)
{
	list->head = NULL;
}

//
// It prints the elements in the list in the form:
// <Type of Value>= <Value>
// <Type of Value2>= <Value2>
void llist_print(LinkedList * list) {

	ListNode * e;

	if (list->head == NULL) {
		printf("{EMPTY}\n");
		return;
	}

	printf("{");

	e = list->head;
	while (e != NULL) {
		printf("%s = ",e->name);
		printf("%f", e->value);
		e = e->next;
		if (e!=NULL) {
			printf("\n");
		}
	}
	printf("}\n");
}

//
// Appends a new node with this value at the beginning of the list
//
void llist_add(LinkedList * list, int value, char *name) {
	// Create new node
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = value;
	n->name = name;
	// Add at the beginning of the list
	n->next = list->head;
	list->head = n;
}
//adds value to existing node specified by its name
// returns 1 if successful 0 if not

int llist_add_value(LinkedList * list, char name, int value) {
	ListNode * e = list->head;
	while(e != NULL) {
		if(strcmp(e->name,name)==0) {
			e->value = value;
			return 1;
		}
	}
	return 0;
}
	while(
//
// Returns value if the name exists in the list. Otherwise returns NULL
//
int llist_exists(LinkedList * list, char *name) {
	ListNode *n;
	n = list -> head;
	while( n!= NULL) {
		if(strcmp(name,n->name)
			return n->value;
		n = n -> next;
	}

	return NULL;
}

//
// It removes the entry with that value in the list.
//
int llist_remove(LinkedList * list, int value) {
	ListNode *n;
	n = list -> head;
	ListNode *prev = NULL;
	while( n != NULL) {
		if( n->value == value)
			break;
		prev = n;
		n = n -> next;
	}
	if(n == NULL)
		return 0;
	if(prev == NULL)
		list -> head = n -> next;
	else
		prev -> next = n -> next;

	free(n);
	return 1;


}

//
// It stores in *value the value that correspond to the ith entry.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_get_ith(LinkedList * list, int ith, int * value) {
	ListNode *n;
	n = list->head;


	for(int i = 0; n!=NULL;i++){
		if(i == ith){
			*value = n->value;
			return 1;
		}
		n = n->next;
	}

	return 0;
}


//
// It removes the ith entry from the list.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_remove_ith(LinkedList * list, int ith) {
	ListNode *n;
	n = list->head;
	ListNode *prev = NULL;
	for(int i = 0; n!= NULL;i++){
		if(i == ith){
			if(n == NULL) {
				list->head = n->next;
			}
			else{
				prev->next = n->next;
				free(n);
				return 1;
			}
		}
		prev = n;
		n = n->next;
	}
	return 0;
}

//
// It returns the number of elements in the list.
//
int llist_number_elements(LinkedList * list) {
	ListNode *n = list->head;
	int count = 0;
	while(n != NULL) {
		count++;
		n = n->next;

	}
	return count;
}


//
// It saves the list in a file called file_name. The format of the
// file is as follows:
//
// value1\n
// value2\n
// ...
//
int llist_save(LinkedList * list, char * file_name) {
	ListNode *n = list->head;
	FILE *f;
	f = fopen(file_name,"w+");
	if(f == NULL)
		return 0;
	while(n != NULL) {
		fprintf(f,"%d\n",n->value);
		n = n->next;
	}
	fclose(f);
	return 0;
}

//
// It reads the list from the file_name indicated. If the list already has entries, 
// it will clear the entries.
//
int llist_read(LinkedList * list, char * file_name) {
	FILE *f;
	char buff[20];
	f = fopen(file_name,"r");
	if (f == NULL)
		return 0;
	ListNode *n = list->head;
	if(n != NULL){
		for( int i =llist_number_elements(list);i != 0;i--) {
			llist_remove_ith(list,i);
		}
	}
	while(fgets(buff,sizeof buff,f) != NULL) {
		llist_add(list,atoi(buff));
	}
	return 1;
}


//
// It sorts the list. The parameter ascending determines if the
// order si ascending (1) or descending(0).
//
void llist_sort(LinkedList * list, int ascending) {
	ListNode *n = list->head;
	ListNode *prev = NULL;
	int holder;
	if(n != NULL)
		prev = n;
	for(int i = 0; n!=NULL;i++){
		if(i ==0)
			n = n->next;
		for(int j = i + 1; n!=NULL;j++) {
			if(ascending) {
				if(prev->value > n->value) {
					holder = prev->value;
					prev->value = n->value;
					n->value = holder;
				}
			}
			else {
				if(prev->value < n->value) {
					holder = prev->value;
					prev->value = n->value;
					n->value = holder;
				}
			}
			n = n->next;
		}
		n = prev->next;
		prev = n;
		n = n->next;

	}
}


//
// It removes the first entry in the list and puts value in *value.
// It also frees memory allocated for the node
//
int llist_remove_first(LinkedList * list, int * value) {
	ListNode *n = list->head;
	if(n!= NULL) {
		*value = n->value;
		list->head = n->next;
		free(n);
		n = NULL;
	}
	else
		return 0;
	return 1;
}

//
// It removes the last entry in the list and puts value in *value/
// It also frees memory allocated for node.
//
int llist_remove_last(LinkedList * list, int *value, char *name) {
	ListNode *n = list->head;
	ListNode *prev;
	ListNode *temp;
	if( n != NULL) {
		if(n->next == NULL) {
			*value = n->value;	
			*name = n->name;
			free(n);
			n = NULL;
			list->head = NULL;
		}
		else{
			while(n->next != NULL) {
				prev = n;
				n = n->next;
			}
			if(n != NULL) {
				*value = n->value;
				prev->next = NULL;
				free(n);
			}
		}
	}
	else
		return 0;
	return 1;
}

//
// Insert a value at the beginning of the list.
// There is no check if the value exists. The entry is added
// at the beginning of the list.
//
void llist_insert_first(LinkedList * list, int value) {
	llist_add(list,value);
	
}

//
// Insert a value at the end of the list.
// There is no check if the name already exists. The entry is added
// at the end of the list.
//
void llist_insert_last(LinkedList * list, int value) {
	ListNode *n = list->head;
	ListNode *new = (ListNode *) malloc(sizeof(ListNode));
	if(n == NULL) 
		llist_add(list,value);
	else{
	while(n->next != NULL)
		n = n->next;
	n->next = new;
	new->value = value;
	}
}

//
// Clear all elements in the list and free the nodes
//
void llist_clear(LinkedList *list){
	ListNode *n = list->head;
	ListNode *prev = n;
	int value;
	while(list->head!=NULL) {
		llist_remove_last(list,&value);
	}
		
}

