class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            int j=0;
            while(nums1[i]!=nums2[j])
            {
                j++;
            }
            bool x=false;;
            if(j==nums2.size()-1)
            {
                ans.push_back(-1);
                continue;
            }
            for(int k=j+1;k<nums2.size();k++)
            {
                if(nums2[k]>nums2[j]&&x==false)
                {
                    x=true;
                    ans.push_back(nums2[k]);
                }
                
            }
            if(x==false)
            ans.push_back(-1);
        }
        return ans;
        
    }
};