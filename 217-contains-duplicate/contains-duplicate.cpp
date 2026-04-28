class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        map<int,bool>mp;
        while(n>0)
        {
            if(mp[nums[n-1]]==true)
            return true;
            else
            {
                mp[nums[n-1]]=true;
                n--;
            }
        }
        return false;
    }
};