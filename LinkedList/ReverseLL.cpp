

======Iterative method

Node* reverseList(Node *head)
{
   Node *curr=head,*prev=NULL ,*next;
   
   while(curr)
   {
       next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
   }
   
   return prev;
 
}

=======================================

Node *help(Node *head,Node *prev)
{
    if(head==NULL)
      return prev;
      
      Node *next=head->next;
      head->next=prev;
      
      help(next,head);
}

Node* reverseList(Node *head)
{
   
   
   return help(head,NULL);
 
}

====================================Recursive I==========

Node *help(Node *head,Node *prev)
{
    if(head==NULL)
      return prev;
      
      Node *next=head->next;
      head->next=prev;
      
      help(next,head);
}

Node* reverseList(Node *head)
{
   
   
   return help(head,NULL);
 }
 
 ============================================Recursive II==========================
 
 Node *help(Node *head,Node **root)
{
    if(head==NULL)
      return NULL;
      
    Node *temp=help(head->next,root);
    
    if(temp==NULL)
    {
       *root=head;
    }
    
    if(temp!=NULL)
      temp->next=head;
      
     return head;
}

Node* reverseList(Node *head)
{
   Node *root;
   
  Node *temp= help(head,&root);
  temp->next=NULL;
   
   return root;
 
}
