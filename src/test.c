#include <stdio.h>
#include <stdlib.h>
#include "test.h"

ele_t* create(const int value){
	ele_t* element = malloc(sizeof(ele_t));
	element->val = value;
	return element;
}

void append(ele_t* appendTo, ele_t* toAppend){
	appendTo->next = toAppend;
}

void printAndFree(ele_t* head){
    if ( head == NULL )
        return;
	ele_t* tmp = head;
	while ( tmp ) {
		printf("%d\n", tmp->val);
		ele_t* freeTmp = tmp;
		tmp = tmp->next;
		free(freeTmp);
	}
}

ele_t* makeN(int len){
    if ( len == 0 )
        return NULL;
	ele_t* head = create(1);
	ele_t* tmp = head;
	for ( int i = 1; i < len; i++ ) {
		tmp->next = create(i+1);
		tmp = tmp->next;
	}
	return head;
}

int main(int argc, char *argv[]) {
    ele_t* head = NULL;
    if ( argc == 2 ){
	    head = makeN(atoi(argv[1]));
	}
	else{
	    head = makeN(5);
	}
	printAndFree(head);
}