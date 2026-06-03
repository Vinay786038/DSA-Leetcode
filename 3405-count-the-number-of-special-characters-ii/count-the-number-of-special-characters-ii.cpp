class Solution {
public:
    int numberOfSpecialChars(string word)
    {
        vector<int>small(26,-1);
        vector<int>up(26,INT_MAX);
        int ans=0;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            char c=word[i];
            if(islower(c))
            small[c-'a']=i;
            else
            up[c-'A']=min(up[c-'A'],i);
        }
        for(int i=0;i<26;i++)
        {
            if(small[i] != -1 &&
           up[i] != INT_MAX &&
           small[i] < up[i])
            ans++;
        }
        return ans;
    }
};