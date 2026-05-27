class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int i=0;
        int j=0;
        int n=nums.size();
        while(i<n)
        {
            if(nums[i]%2==0)
            {
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                i++;
                j++;
            }
            else
            i++;

        }
        return nums;
    }
};