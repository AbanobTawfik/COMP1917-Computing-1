//list.c file that implements all functions declared in list.h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
typedef struct _node {
    int value;
    Node next;
} node;
 

Node new_node(int value){
  Node newNode = malloc(sizeof(node));
  assert(newNode != NULL);
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}


//frees everything malloced for the list
void destroy(Node head) {
   Node curNode = head;
   Node prevNode = NULL;

   while (curNode != NULL) {
     prevNode = curNode;
     curNode = prevNode->next;
     free(prevNode);
   }

}

//appends a node of value to the end of the list
Node append(Node head, int value) {

   Node newNode = new_node(value);
   Node curNode = head;
   
   if ( curNode == NULL ) {
      head = newNode;
   } else {
      while ( curNode->next!=NULL ) {
         curNode = curNode->next;
      }
      curNode->next = newNode;
   }
   return head;
}

void printList(Node head){
  Node cur = head;
    while(cur != NULL){
        printf("[%d]->",cur->value);
        cur = cur->next;
    }
    printf("X\n");
}

// returns the length of a linked list
int length(Node head){
  int size = 0;
  Node cur = head;
  while(cur!=NULL){
    size++;
    cur = cur->next;
  }
  return size;
}

// Given a sorted list, insert a node into the list
// preserving sorted order
//given a list 0->1->2->5->7->X
//then sorted_insert(l, 4)
//now the list will be 0->1->2->4->5->7->X

Node sorted_insert(Node head, int val){
  //inserts a new node value for the val inputted at end 
  //sorting list
  //the head is being defined as the entry point cur
  Node newNode=new_node(val); 
  Node current=head;
  //creating a new node for the inserted value
  if(current==NULL){
    head=newNode;
  }else if(head->value > newNode->value){
   newNode->next=head;
   head=newNode;
  }else{
    //loops through the list
    while(current->next != NULL&&current->next->value < newNode->value){
      current = current->next;
    }
    newNode->next=current->next;
    current->next=newNode;
  }

  return head;
}

//inserts a node of value AFTER specified index
//given a list 0->1->2-X
//then insertAt(l, 1, 9);
//now the list will be 0->1->9->2-X
//if specified index is greater than the length of the list 
//append it to the end
Node insertAt(Node head, int index, int value){
  int i = 0;
  int size = length(head);
  Node newNode = new_node(value);
  Node current = head;
  if(size==0){
    head=newNode;
  }
  else if(index>size+1){
    append(head,value);
  }
  else if(index==0){
    newNode->next=head;
    head=newNode;
  }else{
	while(current->next!=NULL&&i!=index-1){
	    current=current->next;
	    i++;
	}
	newNode->next=current->next;
	current->next=newNode;
  }
  return head;
}
