class Solution {
public:
    int firstUniqueEven(vector<int>& nums)
    {
        map<int,int>mp;
        int even=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                even++;
                if(mp[nums[i]])
                mp[nums[i]]++;
                else
                mp[nums[i]]=1;

            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]==1)
            return nums[i];
        }

        return -1;
    }
};