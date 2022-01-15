/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *first=head,*last=head;
        while(n--){
            last=last->next;
        }
        if(!last)
        {
            return head->next;
        }
        while(last->next){
            last=last->next;
            first=first->next;
        }
        first->next=first->next->next;
        return head;
    }
};