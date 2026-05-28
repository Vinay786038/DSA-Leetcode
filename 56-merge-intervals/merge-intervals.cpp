class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> ans;
        int n=intervals.size();
        int i=0;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        while(i<n)
        {
            if(ans.back()[1]>=intervals[i][0])
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
            i++;
        }
        return ans;

     
    }
};