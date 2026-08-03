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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* dmmy=new ListNode(-1);
        ListNode* temp=dmmy;
        int c=0;

        while(t1!=NULL || t2!=NULL)
        {
            int s=c;
            if(t1!=NULL)
            {
                s+=t1->val;
            }
            if(t2!=NULL)
            {
                s+=t2->val;
            }
            c=s/10;
            ListNode* x=new ListNode(s%10);
            temp->next=x;
            temp=temp->next;

            if(t1!=NULL)
            {
                t1=t1->next;
            }
            if(t2!=NULL)
            {
                t2=t2->next;
            }
        }
        
        if(c==1)
        {
            ListNode* y=new ListNode(1);
            temp->next=y;
        }
        return dmmy->next;
    }
};