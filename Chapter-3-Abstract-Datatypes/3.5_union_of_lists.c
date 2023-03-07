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

position findElement(int element, linkedlist l){
    position p = l;
    while(p != NULL){
        if(p->data == element){ //I was using = instead of == here which was causing a logical error.
            break;
        }
        p = p->next;
    }
    return p; //automatically returns NULL if element does not exist in linked list
}

linkedlist calculateUnion(linkedlist l1, linkedlist l2){
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

    /*building l3 separately, so that its nodes occupy different spaces even though being similar for the entire instance of one of the linkedlists*/
    
    //copying l1 into l3
    while(p != NULL){
        r = createNode(p->data);
        if(l3 == NULLA){
            l3 = r;
            s = l3;
        }
        else{
            s->next = r;
            s = s->next;
        }
        p = p->next;
    }

    //now going through l2 and adding elements only when it is not present already in l1
    while(q != NULL){
        if(findElement(q->data, l3) == NULL){
            r = createNode(q->data);
            if(l3 == NULLA){
                l3 = r;
                s = l3;
            }
            else{
                s->next = r;
                s = s->next;
            }
        }
        q = q->next;
    }
    return l3;
}

//driver code
int main(){
    int array1[6] = {1, 2, 3, 4, 5, 6};
    int array2[6] = {1, 3, 6, 10, 23, 150};
    linkedlist l1, l2, l3;
    l1 = createLinkedListFromArray(array1, 6);
    l2 = createLinkedListFromArray(array2, 6);
    
    l3 = calculateUnion(l1, l2);

    printlist(l3);
    return 0;
}