class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>vec;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==1)
            {
                vec.push_back(nums[i]);
                mp[nums[i]]++;

            }
            else
            {
                mp[nums[i]]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(mp[i]==0)
            vec.push_back(i);
        }
        return vec;
        
    }
};