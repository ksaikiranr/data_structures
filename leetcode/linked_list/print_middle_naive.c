#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void construct_ll(struct node **head){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	(*head) = temp;
	temp->data = 1;
	temp->next = NULL;
	for(int i=2;i<=10;i++){
		struct node *new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = i;
		temp->next = new_node;
		temp = new_node;
	}
	temp->next = NULL;
	return;
}

void print_ll(struct node* head){
	while(head!= NULL){
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
	return;
}

void print_middle(struct node *head){
	struct node* temp = head;
	//Get the length of ll
	int len = 0;
	while(temp!=NULL){
		len++; temp=temp->next;
	}
	printf("len %d\n", len);
	//Compute middle loc
	int middle = len/2;
	//Goto middle loc
	temp = head;
	for(int i = 1; i<=middle; i++){
		temp = temp->next;
	}
	printf("%d\n", temp->data);
	return;
}

int main(){
	struct node *head = (struct node*)malloc(sizeof(struct node));
	construct_ll(&head);
	print_ll(head);
	print_middle(head);
	print_ll(head);
	return 0;
}	
