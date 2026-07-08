class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums)
    {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(x==nums[j])
                {
                    ans++;
                    nums.erase(nums.begin()+i);
                    nums.erase(nums.begin()+j-1);
                    i--;
                    break;
                }
            }
        }
        vector<int>vec;
        vec.push_back(ans);
        vec.push_back(nums.size());
        return vec;
        
    }
};