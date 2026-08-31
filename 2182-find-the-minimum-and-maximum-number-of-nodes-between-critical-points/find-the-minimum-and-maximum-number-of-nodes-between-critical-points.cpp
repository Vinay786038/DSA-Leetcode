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
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        int pos=1;
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        {
            return {-1,-1};
        }
        ListNode* temp=head->next;
        ListNode* prev=head;
        int first=-1;
        int last=-1;
        int minDist=INT_MAX;
        while(temp->next)
        {
            int nextval=temp->next->val;
            if((temp->val>prev->val&&temp->val>nextval)||(temp->val<prev->val&&temp->val<nextval))
            {
                if(first==-1)
                {
                    first=pos;
                }
                else
                {
                    minDist=min(minDist,pos-last);
                }
                last=pos;
            }
            prev=temp;
            temp=temp->next;
            pos++;
        }
        if(first==-1||first==last)
        {
            return {-1,-1};
        }
        return {minDist,last-first};
    }
};