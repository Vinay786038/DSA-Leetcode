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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int>st1;
        stack<int>st2;
        stack<int>st3;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        while(temp1!=NULL)
        {
            st1.push(temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            st2.push(temp2->val);
            temp2=temp2->next;
        }
        while(st1.empty()!=1||st2.empty()!=1||carry)
        {
            int sum=carry;
            if(st1.empty()!=1&&st2.empty()!=1)
            {
                sum+=st1.top()+st2.top();
                st1.pop();
                st2.pop();
            }
           else if(st1.empty()==1&&st2.empty()!=1)
            {
                sum+=st2.top();
                st2.pop();
            }
            else
            {
                if(st1.empty()!=1&&st2.empty()==1)
                {
                    sum+=st1.top();
                    st1.pop();
                }
            }
            
            carry=sum/10;
            st3.push(sum%10);
            
        }
        ListNode* root=NULL;
        ListNode* tail=NULL;
        while(st3.empty()!=1)
        {
            if(root==NULL)
            {
                root=new ListNode(st3.top());
                tail=root;
                st3.pop();
            }
            else
            {
                tail->next=new ListNode(st3.top());
                st3.pop();
                tail=tail->next;
            }
        }
        return root;

    }
};