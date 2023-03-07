//3.1 WAP to print out the elements of a singly linkedlist
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

typedef Node* linkedlist;
typedef Node* position;

linkedlist append(int data, linkedlist l){
	//first step would be to create space for a Node
	//malloc provides the space as a pointer. As it's a node pointer and it has to store a node, i'll write the following:
	Node* new = (Node*)malloc(sizeof(Node));
	//then would add the data to the node and make its next pointer as NULL since that should be the case:
	new->data = data;
	new->next = NULL;
	//then I'll check if the linkedlist is empty. If it is, then I'll assign l as new, otherwise, I'll iterate to the end of the list till the last mnode is achieved and then set the next pointer of the last node to be NULL
	if(l == NULL){
		return new;
	} else{ 
		//not required explicitly, but writing for more clarity
		position p = l;
		while(p -> next != NULL){
			p = p->next;
		}
		p->next = new;
		return l;
	}
}

void printElements(linkedlist l){
	position p = l;
	while(p != NULL){
		printf("%d\n", p->data);
		p = p->next;
	}
}

int main(){
	linkedlist l = NULL;
	l = append(3, l);
	l = append(4, l);
	l = append(5, l);
	l = append(50, l);
	l = append(1, l);
	//printf("%d", l->data);
	printElements(l);
	return 0;
}
