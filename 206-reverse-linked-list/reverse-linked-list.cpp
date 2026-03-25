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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *temp=head;
        ListNode *temp2=temp;
        ListNode *temp3=temp;
        int n=0;
        while(temp2)
        {
            n++;
            temp2=temp2->next;
        }
        temp2=temp;
        ListNode *head2=NULL;
        ListNode *temp4=NULL;
        while(n>0)
        {
            while(temp2->next)
            {
                temp3=temp2;
                temp2=temp2->next;
            }
            temp3->next=NULL;
            if(head2==NULL)
            {
                head2=temp2;
                temp2->next=NULL;
                temp4=temp2;
            }
            else
            {
                temp4->next=temp2;
                temp4=temp4->next;
            }
            temp2=temp;
            n--;
        }
        head=head2;
        return head;
    }
};