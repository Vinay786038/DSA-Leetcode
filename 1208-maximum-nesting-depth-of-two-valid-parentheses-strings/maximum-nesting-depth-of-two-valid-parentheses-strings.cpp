class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int>ans;
        int x=0;
        for(int i=0;i<seq.size();i++)
        {
            if(seq[i]=='(')
            {
                ans.push_back(x%2);
                x++;
            }
            else
            {
                x--;
                ans.push_back(x%2);
            }
        }
        return ans;
        
    }
};