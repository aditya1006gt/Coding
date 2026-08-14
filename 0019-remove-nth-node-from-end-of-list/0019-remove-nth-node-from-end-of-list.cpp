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
        if(head==nullptr || head->next==NULL)
        return NULL;

        ListNode* fast=head;
        for(int i=0;i<n;i++)
        fast=fast->next;
        ListNode* slow=head;
        ListNode* t;
        if(fast==NULL)
        {
            t=head->next;
            delete head;
            return t;
        }
        while(fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
        t=slow->next;
        slow->next=slow->next->next;
        delete t;

        return head;
    }
};