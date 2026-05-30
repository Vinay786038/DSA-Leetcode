class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) 
    {
        int res=INT_MAX;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    res=min(res,nums1[i]);
                }
            
            }
        }
        if(res!=INT_MAX)
        return res;
        else
        res=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(nums1[0]==nums2[0])
        res=nums1[0];
        else
        {
            if(nums1[0]<nums2[0])
            {
                res+=nums1[0];
                res=res*10+nums2[0];
            }
            else
            {
                res+=nums2[0];
                res=res*10+nums1[0];
            }
            
        } 
        return res;
    }
};