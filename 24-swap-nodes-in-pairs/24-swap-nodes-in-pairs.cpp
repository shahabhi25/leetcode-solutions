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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* ans=new ListNode(0, head);
        ListNode* a=ans;
        ListNode* b=head;
        
        
        while(b!=NULL && b->next!=NULL)
        {
            ListNode* t=b->next->next;
            a->next=b->next;
            a->next->next=b;
            b->next=t;
            
            b=b->next;
            a=a->next->next;
        }
        
        return ans->next;
    }
};