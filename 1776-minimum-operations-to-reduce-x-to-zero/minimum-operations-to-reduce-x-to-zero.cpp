class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n=nums.size();
        int i=0;
        long long total=0;
        for(int num:nums)
        {
            total+=num;
        }
        long long target=total-x;
        if(target==0)
        {
            return n;
        }
        if(target<0)
        {
            return -1;
        }
        long long sum=0;
        int len=-1;
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];
            while(i<=j&&sum>target)
            {
                sum-=nums[i];
                i++;
            }
            if(sum==target)
            {
                len=max(len,j-i+1);
            }
        }
        if(len==-1)
        return -1;
        return n-len;
        
    }
};