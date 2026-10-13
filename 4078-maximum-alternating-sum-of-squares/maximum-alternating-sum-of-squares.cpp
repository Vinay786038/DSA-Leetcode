class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums)
    {
        vector<int>vec1;
        for(int i=0;i<nums.size();i++)
        {
            vec1.push_back(abs(nums[i]));
        }
        sort(vec1.begin(),vec1.end());
        long long sum1=0;
        long long sum2=0;
        int n=nums.size();
        for(int i=0;i<n/2;i++)
        {
            sum1+=vec1[i]*vec1[i];
        }
        for(int i=n/2;i<n;i++)
        {
            sum2+=vec1[i]*vec1[i];
        }
        return sum2-sum1;
    }
};