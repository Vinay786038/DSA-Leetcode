class Solution {
public:
    int numberOfSubstrings(string s)
    {
        int n=s.size();
        int ans=0;
        vector<int>vec(3,-1);
        for(int i=0;i<n;i++)
        {
            vec[s[i]-'a']=i;
            if(vec[0]!=-1&&vec[1]!=-1&&vec[2]!=-1)
            {
                int minidx=min(vec[0],min(vec[1],vec[2]));
                ans+=minidx+1;
            }
        }
        return ans;
        
    }
};