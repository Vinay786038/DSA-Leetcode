class Solution {
public:
    int heightChecker(vector<int>& heights)
    {
        vector<int>vec=heights;
        sort(vec.begin(),vec.end());
        int ans=0;
        for(int i=0;i<vec.size();i++)
        {
            if(heights[i]!=vec[i])
            {
                ans++;
            }
        }
        return ans;
        
    }
};