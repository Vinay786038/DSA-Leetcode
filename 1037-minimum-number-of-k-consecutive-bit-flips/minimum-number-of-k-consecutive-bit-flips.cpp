class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>flipped(n,0);
        int activeflips=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i>=k)
            {
                activeflips-=flipped[i-k];
            }
            int curr=nums[i];
            if(activeflips%2)
            {
                curr^=1;
            }
            if(curr==0)
            {
                if(i+k>n)
                {
                    return -1;
                }
                flipped[i]=1;
                activeflips++;
                ans++;
            }
        }
        return ans;

        
    }
};