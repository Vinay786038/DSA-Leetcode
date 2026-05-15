class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        long long int count=0;
        int n=nums.size();
        long long int x=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                x++;
            }
            if(nums[i]!=0)
            {
                count+=x*(x+1)/2;
                x=0;
            }
            if(i==n-1)
            count+=x*(x+1)/2;

        }
        return count;
        
    }
};