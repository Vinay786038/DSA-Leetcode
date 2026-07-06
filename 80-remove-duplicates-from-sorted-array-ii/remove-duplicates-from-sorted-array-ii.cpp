class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int k=nums.size();
        int i=0;
        int j=1;
        while(j<k)
        {
            if(nums[i]==nums[j])
            {
                if(j-i>1)
                {
                    while(j<k&&nums[i]==nums[j])
                    {
                        for(int m=j;m<k-1;m++)
                        {
                            nums[m]=nums[m+1];
                        }
                        k--;
                    }
                    i=j;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                i=j;
                j++;
            }
        }
        return k;
        
    }
};