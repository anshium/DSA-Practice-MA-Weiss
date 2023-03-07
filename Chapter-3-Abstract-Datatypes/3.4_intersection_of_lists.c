//3.4 Find intersection of two lists using only basic list operations
//I'm gonna use the linkedlist implementation of lists

#include <stdio.h>
#include <stdlib.h>
#define NULLA ((void*)0)
typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef Node* linkedlist;
typedef Node* position;

typedef int* Array;

position createNode(int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;

    return new;
}

linkedlist createLinkedListFromArray(Array a, int size){
    linkedlist l = createNode(a[0]);
    int element;
    position p;
    position q = l;
    for(int i = 1; i < size; i++){
        element = a[i];
        p = createNode(element);
        q->next = p;
        q = q->next;
    }
    return l;
}

void printlist(linkedlist l){
	position p = l;
	while(p != NULLA){
		printf("%d\n", p->data);
		p = p->next;
	}
}

linkedlist calculateIntersection(linkedlist l1, linkedlist l2){
    //So there would be two positions p and q. The former would hold the position of elements in linkedlist l1 and the latter likewise.
    position p, q;
    p = l1;
    q = l2;

    //useful temp position holders
    position r;
    position s;

    //here comes the intersection linkedlist
    linkedlist l3 = NULL;
    s = l3;

    //iterate through all of linkedlist l1
    while(p != NULL){
        while(q != NULL){
            
            if(p->data == q->data){
                //printf("%d\n", p->data);
                r = createNode(p->data);
                if(l3 == NULL){
                    //If instead of doing the two lines below, I would have done s = r and moved ahead, then that would have been a problem sor some reason.
                    l3 = r;
                    s = l3;
                    //printf("Here\n");
                }
                else{
                    s->next = r;
                    s = s->next;
                }
            }
            q = q->next;
        }
        q = l2;
        p = p->next;
    }
    return l3;
}

//driver code
int main(){
    int array1[6] = {1, 2, 3, 4, 5, 6};
    int array2[6] = {1, 3, 6, 10, 23, 100};
    linkedlist l1, l2, l3;
    l1 = createLinkedListFromArray(array1, 6);
    l2 = createLinkedListFromArray(array2, 6);
    
    l3 = calculateIntersection(l1, l2);

    printlist(l3);
    printf("It's Working!\n");
    return 0;
}
