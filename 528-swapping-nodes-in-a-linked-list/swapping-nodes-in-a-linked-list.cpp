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
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        int start=k;
        int last=size-k+1;
        ListNode* temp1=head;
        ListNode* temp2=head;
        while(start>1)
        {
            temp1=temp1->next;
            start--;
        }
        while(last>1)
        {
            temp2=temp2->next;
            last--;
        }
        int x=temp1->val;
        temp1->val=temp2->val;
        temp2->val=x;
        return head;
    }
};