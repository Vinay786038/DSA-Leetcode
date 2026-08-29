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
    void reorderList(ListNode* head)
    {
        ListNode* temp1=head;
        while(temp1!=NULL&&temp1->next!=NULL)
        {
            ListNode* temp2=temp1->next;
            ListNode* prev=temp1;
            while(temp2->next)
            {
                prev=temp2;
                temp2=temp2->next;
            }
            prev->next=NULL;
            temp2->next=temp1->next;
            temp1->next=temp2;
            temp1=temp1->next->next;

        }
        return;

        
    }
};