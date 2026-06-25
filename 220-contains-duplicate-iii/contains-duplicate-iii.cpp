class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff)
    {
        int i=0;
        int j=1;
        int n=nums.size();
        set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        if(valueDiff==0&&st.size()==n)
        return false;
        while(i<j||j<n)
        {
            if(i!=j)
            {
                if(j<n&&abs(i-j)<=indexDiff)
                {
                    if(abs((long long)nums[i]-nums[j])<=valueDiff)
                    return true;
                    else
                    j++;
                }
                else
                {
                    i++;
                    j=i+1;
                }
            }
            if(i==n-1)
            break;
        }
        return false;
        
    }
};