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
    ListNode* oddEvenList(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* temp1=head;
        ListNode* temp2=NULL;
        while(temp1&&temp1->next)
        {
            ListNode* Next=temp1->next;
            temp1->next=temp1->next->next;
            temp1=temp1->next;
            if(temp2==NULL)
            {
                temp2=Next;
                temp2->next=NULL;
            }
            else
            {
                Next->next=NULL;
                ListNode* x=temp2;
                while(x->next)
                {
                    x=x->next;
                }
                x->next=Next;
                
            }
        }
        temp1=head;
        while(temp1->next)
        {
            temp1=temp1->next;
        }
        temp1->next=temp2;
        return head;
    }
};