class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++)
        {
            if(i==nums.size())
            return i;
            if(i==nums[i])
            continue;
            return i;
        }
        return -1;
    }
};