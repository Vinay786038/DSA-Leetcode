class Solution {
public:
    int abs(int x)
    {
        if(x<0)
        return -x;
        return x;
    }
    vector<int> leftRightDifference(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>vec(n);
        int leftsum=0;
        int rightsum=0;
        for(int i=0;i<n;i++)
        {
            rightsum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            rightsum-=nums[i];
            vec[i]=abs(rightsum-leftsum);
            leftsum+=nums[i];
        }
        return vec;
    }
};