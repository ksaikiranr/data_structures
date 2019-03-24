struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL)
        return NULL;
    struct ListNode* temp = head;
    while(temp->next){
        if(temp->next->val == val)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }
    if(head->val==val)
        head = head->next;
    return head;
}
