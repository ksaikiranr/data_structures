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
	for(int i=2;i<=12;i++){
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

void reverse_ll(struct node **head){
	struct node *curr_node, *next_node, *prev_node;
	prev_node = NULL;
	curr_node = (*head);
	while(curr_node!=NULL){
		next_node = curr_node->next;
		curr_node->next = prev_node;
		prev_node = curr_node;
		curr_node = next_node;
	}
	*head = prev_node;
	return;
}

int main(){
	struct node *head = (struct node*)malloc(sizeof(struct node));
	construct_ll(&head);
	print_ll(head);
	reverse_ll(&head);
	print_ll(head);
	return 0;
}	


