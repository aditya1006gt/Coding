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
        ListNode *ptr = head, *temp = head;
        for (int i = 0; i < n; i++) ptr = ptr->next;
        
        if (!ptr) return head->next;
        
        while (ptr->next) {
            ptr = ptr->next;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode* trav=head;
    //     int c=0;
    //     while(trav) {
    //         c++;
    //         trav=trav->next;
    //     }
    //     if(n==c) {
    //         ListNode* temp=head->next;
    //         delete(head);
    //         return temp;
    //     }
    //     int k=c-n,a=1;
    //     trav=head;
    //     while(a!=k) {
    //         trav=trav->next;
    //         a++;
    //     }
    //     ListNode* temp=trav->next;
    //     trav->next=trav->next->next;
    //     delete(temp);
    //     return head;
    // }
};