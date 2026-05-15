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
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int>vec;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            bool x=true;
            ListNode* temp1=temp->next;
            if(temp1==NULL)
            {
                vec.push_back(0);
                x=false;
            }
            while(x)
            {
                if(temp->val<temp1->val)
                {
                    vec.push_back(temp1->val);
                    x=false;
                }
               else if(temp1->next==NULL)
                {
                    vec.push_back(0);
                    x=false;
                }
                else
                temp1=temp1->next;
            }
            temp=temp->next;
        }
        return vec;
        
    }
};