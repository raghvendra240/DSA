https://www.interviewbit.com/problems/sort-binary-linked-list/

ListNode* Solution::solve(ListNode* A) {
    
    ListNode *temp=A;
    ListNode *zero=A;
    
    while(temp!=NULL)
    {
        if(temp->val==0)
            {
                swap(zero->val,temp->val);
                zero=zero->next;
                temp=temp->next;
            }
            else
            {
                temp=temp->next;
            }
    }
    
    return A;
}
