class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        vector<int>ans(nums.size());
        sort(nums.begin(),nums.end());
        int left=((nums.size()+1)/2)-1;
        int right=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                ans[i]=nums[left];
                left--;
            }
            else
            {
                ans[i]=nums[right];
                right--;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=ans[i];
        }
        return;

        
    }
};