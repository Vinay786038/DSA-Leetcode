class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        if(nums.size()<3)
        return 0;
        int ans=0;
        for(int i=0;i<=nums.size()-3;i++)
        {
            int start=nums[i];
            int mid=nums[i+1];
            int last=nums[i+2];
            if((start+last)*2==mid)
            {
                ans++;
            }
        }
        return ans;
        
    }
};