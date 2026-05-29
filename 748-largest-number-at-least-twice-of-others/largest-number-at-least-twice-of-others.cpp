class Solution {
public:
    int dominantIndex(vector<int>& nums) 
    {
        int index=-1;
        int max=-1;
        int second=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>max)
            {
                second=max;
                max=nums[i];
                index=i;
            }
            else if(nums[i]>second)
            {
                second=nums[i];
            }
        }
        if(max>=2*second)
        return index;
        return -1;
    }
};