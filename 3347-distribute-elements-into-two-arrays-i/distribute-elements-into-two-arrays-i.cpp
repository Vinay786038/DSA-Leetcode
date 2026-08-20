class Solution {
public:
    vector<int> resultArray(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>vec1;
        vector<int>vec2;
        vec1.push_back(nums[0]);
        vec2.push_back(nums[1]);
        for(int i=2;i<n;i++)
        {
            int a=vec1.size()-1;
            int b=vec2.size()-1;
            if(vec1[a]>vec2[b])
            {
                vec1.push_back(nums[i]);
            }
            else
            {
                vec2.push_back(nums[i]);
            }
        }
        for(int i=0;i<vec2.size();i++)
        {
            vec1.push_back(vec2[i]);
        }
        return vec1;
        
    }
};