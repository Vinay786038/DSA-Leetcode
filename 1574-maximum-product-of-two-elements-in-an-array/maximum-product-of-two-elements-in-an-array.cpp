class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int n=nums.size();
        int lar=nums[0];
        int slar=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>lar)
            {
                slar=lar;
                lar=nums[i];
            }
            else
            {
                if(nums[i]>slar)
                slar=nums[i];
            }
        }
        return (lar-1)*(slar-1);
        
    }
};