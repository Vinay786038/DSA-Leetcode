class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int>ans;
        queue<int>q;
        stack<int>s;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            {
                ans.push_back(nums[i]);
            }
            else if(nums[i]==pivot)
            {
                s.push(nums[i]);
            }
            else
            {
                q.push(nums[i]);
            }
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
        
    }
};