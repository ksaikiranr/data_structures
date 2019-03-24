#include <stdio.h>
#include <stdlib.h>

struct ListNode{
	int val;
	struct ListNode *next;
};

void construct_ll(struct ListNode **head){
	struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
	(*head) = temp;
	temp->val = 1;
	temp->next = NULL;
	for(int i=2;i<=12;i++){
		struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
		new_node->val = i;
		temp->next = new_node;
		temp = new_node;
	}
	temp->next = NULL;
	return;
}

void print_ll(struct ListNode* head){
	while(head!= NULL){
		printf("%d ",head->val);
		head = head->next;
	}
	printf("\n");
	return;
}

struct ListNode* deleteDuplicates(struct ListNode *head){
	if(!head)
		return NULL;
	struct ListNode *curr;
	curr = head;
	while(curr->next){
		if(curr->val==curr->next->val)
			curr->next=curr->next->next;
		else
			curr=curr->next;
	} 
	return head;
}

int main(){
	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	construct_ll(&head);
	print_ll(head);
	struct ListNode *head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	head2 = deleteDuplicates(head);
	print_ll(head2);
	return 0;
}	



