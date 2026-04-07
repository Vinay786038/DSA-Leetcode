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
        
        set<int>s;
        s.insert(nums[0]);
        for(int i=1;i<n;i++)
        {
            int size=s.size();
            s.insert(nums[i]);
            if(s.size()==size)
            return nums[i];
        }
        return 0;*/
        int slow=0;
        int fast=0;
        while(true)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast)
            break;
        }
        slow=0;
        while(true)
        {
            slow=nums[slow];
            fast=nums[fast];
            if(slow==fast)
            return slow;
        }
        return -1;

    }
};