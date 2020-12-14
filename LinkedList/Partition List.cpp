https://www.interviewbit.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    
   ListNode*less=NULL,*lessHead=NULL;
   ListNode*great=NULL,*greatHead=NULL;
   
   ListNode*head=A;
   
   while(head)
   {
       if(head->val<B)
       {
           if(lessHead==NULL)
           {
               lessHead=head;
               less=head;
           }
           else
             {
                 less->next=head;
                 less=less->next;
             }
       }
       else
       {
            if(greatHead==NULL)
           {
               greatHead=head;
               great=head;
           }
           else
             {
                 great->next=head;
                 great=great->next;
             }
           
       }
       
       head=head->next;
   }
   
   if(great!=NULL)
     great->next=NULL;
   
  if(less!=NULL && greatHead!=NULL)
      less->next=greatHead;
   
   if(lessHead!=NULL)
     return lessHead;
     
     return greatHead;
}
