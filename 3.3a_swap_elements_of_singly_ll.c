//3.3 (a) Swap elements of a singly linkedlist using change of pointers

#include <stdio.h>
#include <stdlib.h>
#define NULLA ((void*)0) //replacement to NULL (corresponding to the Hindi slang)
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

linkedlist createRandomLinkedList(int size, unsigned int seed){
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

position findPrevious(position p, linkedlist l){
	position q = l;
	if(q == NULL){
		return NULL;
	}
	while(q -> next != p){
		q = q -> next;
	}
	return q;
}

/// @brief it swaps the element at positional 0-indexed element with the one to the next to it
/// @param pi : positional_index
/// @param l : the linkedlist
linkedlist swap_elements(int pi, linkedlist l){
	int iter = 0;
	position p = l;
	
	//if the list is empty, do nothing
	if(p == NULLA) return l;
	//if the list has only one element, do nothing
	if(p -> next == NULLA) return l;
	//else find the pointer corresponding to the positional index pi
	while(p -> next != NULLA){
		if(iter == pi) {
			//printf("Got till %d\n", p->data); //Debug print
			break;
		}
		p = p->next;
		// printf("iter = %d\n", iter); //Debug print

		iter++;
	}
	//Again check if the element to the next of p is not null, which means that p is not the last element
	if(p->next == NULLA) return l;
	//p is the box that is to be swapped with its successor
	position q = findPrevious(p, l);
	//printf("Previous to %d is %d\n", p->data, q->data); //Debug print
	position r = p->next;
	position s = r->next;
	//so we have q p r s and we have to convert it to q r p s
	q->next = r;
	r->next = p;
	p->next = s;
	return l;
}

int main(){
	linkedlist l = createRandomLinkedList(10, 100);
	printf("Before Swapping: \n");
	printElements(l);

	l = swap_elements(2, l); //3rd element will be swapped with the 4th (0-indexed)

	printf("\nAfter Swapping: \n");
	printElements(l);

	printf("Woohoo!! :)\n");
	return 0;
}
