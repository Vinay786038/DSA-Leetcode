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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        ListNode* temp1=list1;;
        ListNode* temp2;
        for(int i=0;i<a;i++)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        ListNode* temp3;
        for(int i=a;i<b+1;i++)
        {
            temp3=temp1;
            temp1=temp1->next;
        }
        temp2->next=list2;
        while(temp2->next)
        {
            temp2=temp2->next;
        }
        temp2->next=temp1;
        return list1;
        
    }
};