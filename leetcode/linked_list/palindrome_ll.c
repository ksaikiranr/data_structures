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
	for(int i=2;i<=2;i++){
		struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
		new_node->val = i;
		temp->next = new_node;
		temp = new_node;
	}
	/*for(int i=5;i>=1;i--){
		struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
		new_node->val = i;
		temp->next = new_node;
		temp = new_node;
	}*/
	temp->next = NULL;
	return;
}

void print_ll(struct ListNode* head){
	int i=0;
	while(head!= NULL && i<=20){
		printf("%d ",head->val);
		head = head->next;
		i++;
	}
	printf("\n");
	return;
}

int palindrome(struct ListNode *head){
	int len_ll = 0;
	struct ListNode *temp = head;
	while(temp){
		len_ll++;	temp = temp->next;
	}
	int mid = len_ll/2,i=0;
	struct ListNode *curr, *prev;
	prev = NULL;	curr = head;
	while(curr){
		temp = curr->next;
		if(i>=mid)
			curr->next = prev;
		prev = curr;
		curr = temp;
		i++;
	}
	curr = head;	i=0; 
	while(i<len_ll){
		i++;
		if(curr->val != prev->val)
			return 0;
		curr = curr->next;
		prev = prev->next;
	}
	return 1;
}

int main(){
	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	construct_ll(&head);
	print_ll(head);
	int s = palindrome(head);
	printf("%d ",s);
	//print_ll(head);
	return 0;
}	



