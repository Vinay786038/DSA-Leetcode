class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        /*int left=0;
        int right=n-1;
        while(left<right)
        {
            if(nums[left]==nums[right])
            return nums[left];
            left++;
            if(left==right)
            {
                left=0;
                right--;
            }
        }
        return 0;
        */
        set<int>s;
        s.insert(nums[0]);
        for(int i=1;i<n;i++)
        {
            int size=s.size();
            s.insert(nums[i]);
            if(s.size()==size)
            return nums[i];
        }
        return 0;

    }
};