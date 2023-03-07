//3.2 WAP to print_lots

#include <stdio.h>
#include <stdlib.h>

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

//assumes that the linkedlist is sufficiently large
//I had to take the length parameter, I was not able to solve without that. For some reson, passing the pointer did not work and doing like int p[], threw a warning that I'll get the size of the pointer p if I used sizeof with that.
void print_lots(linkedlist l, array p, int length){
	/**PSEUDO CODE**/
	/**
	get next/first element of p
	then go to that particular position from already acieved position in the linkedlist and print the data value
	Also keep track of which position has been achieved.
	goto line 1
	**/
	int i = 0;
	int array_length = length;
	//printf("Array length = %d\n", array_length);
	int ith_element;
	int steps;
	position q = l;
	int current_element = 1;
	while(i < array_length){
		//pick the ith element
		ith_element = p[i];
		//printf("%d\n", p[i]);
		//goto the obtained ith_element in the linkedlist
		steps = ith_element - current_element;
		for(int i = 1; i <= steps; i++){
			q = q->next;
		}
		printf("%d\n", q->data);
		current_element = ith_element;
		i++;
	}
}

void printElements(linkedlist l){
	position p = l;
	while(p != NULL){
		printf("%d\n", p->data);
		p = p->next;
	}
}

//driver code
int main(){
	//creation of a linkedlist
	linkedlist l = NULL;
	position p;
	p = createNode(rand());
	l = p;
	position q = l;
	for(int i = 0; i < 10; i++){
		p = createNode(rand());
		q->next = p;
		q = p;
	}
	int arr[4] = {1, 3, 5, 9};
	int sizeofarray = sizeof(arr) / sizeof(int);
	print_lots(l, arr, sizeofarray);
	return 0;
}