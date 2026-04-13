class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        int left=0;
        int right=1;
        int sum=nums[0];
        int size=INT_MAX;
        while(left<right)
        {
            if(sum>=target)
            {
                sum-=nums[left];
                size=min(size,right-left);
                left++;
            }
            else if(right<n)
            {
                sum+=nums[right];
                right++;
            }
            else
            left++;
        }
        return size==INT_MAX?0:size;

        
    }
};