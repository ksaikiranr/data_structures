
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void construct_ll(struct node **head, int seed){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	(*head) = temp;
	temp->data = 1;
	temp->next = NULL;
	for(int i=seed;i<=seed+12;i++){
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

struct node* merge_sorted_ll(struct node *head1, struct node *head2){
	struct node *head, *prev = NULL, *curr = NULL;
	int initial = 0;
	while(head1 && head2){
		if(head1->data < head2->data){
			curr = (struct node*)malloc(sizeof(struct node));
			curr->data = head1->data;
			curr->next = NULL;
			if(prev)
				prev->next = curr;
			prev = curr;
			head1 = head1->next;
			if(!initial){
				head = curr;	initial++;
			}
		}
		else{
			curr = (struct node*)malloc(sizeof(struct node));
			curr->data = head2->data;
			curr->next = NULL;
			if(prev)
				prev->next = curr;
			prev = curr;
			head2 = head2->next;
			if(!initial){
				head = curr;	initial++;
			}
		}
	}
	while(head1){
		curr = (struct node*)malloc(sizeof(struct node));
			curr->data = head1->data;
			curr->next = NULL;
			if(prev)
				prev->next = curr;
			prev = curr;
			head1 = head1->next;
			if(!initial){
				head = curr;	initial++;
			}
	}
	while(head2){
		curr = (struct node*)malloc(sizeof(struct node));
			curr->data = head2->data;
			curr->next = NULL;
			if(prev)
				prev->next = curr;
			prev = curr;
			head2 = head2->next;
			if(!initial){
				head = curr;	initial++;
			}
	}
	return head;
}

int main(){
	struct node *head1 = (struct node*)malloc(sizeof(struct node));
	construct_ll(&head1,2);
	struct node *head2 = (struct node*)malloc(sizeof(struct node));
	construct_ll(&head2,3);
	print_ll(head1);
	print_ll(head2);
	struct node *result = (struct node*)malloc(sizeof(struct node));
	result = merge_sorted_ll(head1, head2);
	print_ll(result);
	return 0;
}	


