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
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        unordered_map<int,bool>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=true;
        }
        ListNode* head2=NULL;
        ListNode* temp=head;
        ListNode* tail=head2;
        while(temp)
        {
            if(mp[temp->val]==false)
            {
                if(head2==NULL)
                {
                    head2=new ListNode(temp->val);
                    tail=head2;
                }
                else
                {
                    tail->next=new ListNode(temp->val);
                    tail=tail->next;
                }
            }
            temp=temp->next;
        }
        return head2;
        
    }
};