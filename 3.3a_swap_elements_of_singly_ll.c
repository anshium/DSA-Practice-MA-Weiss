//3.3 (a) Swap elements of a singly linkedlist using change of pointers

#include <stdio.h>
#include <stdlib.h>
#define NULLA ((void*)0)
typedef struct Node{
	int data;
	struct Node* next;
} Node;

typedef Node* linkedlist;
typedef Node* position;

typedef int* array;

position createNode(int data){
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;
	return new;
}

linkedlist createRandomLinkedList(int size, int seed){
	srand(seed);
	
	linkedlist l = NULL;
	position p;
	p = createNode(rand());
	l = p;
	position q = l;
	//size - 1 as one of the elements has been already added above
	for(int i = 0; i < size - 1; i++){
		p = createNode(rand());
		q->next = p;
		q = p;
	}
	return l;
}

void printElements(linkedlist l){
	position p = l;
	while(p != NULL){
		printf("%d\n", p->data);
		p = p->next;
	}
}

/// @brief it swaps the element at positional 1-indexed element with the one to the next to it
/// @param pi : positional_index
/// @param l : the linkedlist
void swap_elements(int pi, linkedlist l){
	int iter = 0;
	position p = l;
	
	if(p == NULL) return;
	if(p -> next == NULL) return;
	while(p -> next != NULL){
		if(iter == pi) break;
		p = p->next;
		iter++;
	}
	p->next = 
	
}

int main(){
	linkedlist l = createRandomLinkedList(10, 100);
	printElements(l);
	
	
	return 0;
}