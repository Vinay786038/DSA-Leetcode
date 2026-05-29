/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int>mp;
        if(head==NULL||head->next==NULL)
        return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        slow=slow->next;
        fast=fast->next->next;
        while(slow!=fast&&fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *p=head;
        while(p!=NULL)
        {
            if(mp.find(p)!=mp.end())
            return p;
            else
            mp[p]=1;
            p=p->next;
        }
        
        return p;
    }
};