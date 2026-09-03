class Solution {
public:
    bool uniformArray(vector<int>& nums1)
    {
        int odd=INT_MAX;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            if(nums1[i]%2==1)
            {
                odd=min(nums1[i],odd);
            }
        }
        if(odd==INT_MAX)
        {
            return true;
        }
        for(int i=0;i<n;i++)
        {
            if(nums1[i]%2==0&&nums1[i]<=odd)
            {
                return false;
            }
        }
        return true;

        
    }
};