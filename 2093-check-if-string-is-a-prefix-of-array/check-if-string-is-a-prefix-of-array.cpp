class Solution {
public:
    bool isPrefixString(string s, vector<string>& words)
    {
        int m=s.size();
        int i=0;
        for(int k=0;k<words.size();k++)
        {
            int n=words[k].size();
            string str=words[k];
            
            for(int l=0;l<n;l++)
            {
                if(i>=m||str[l]!=s[i])
                return false;
                i++;
            }
            if(i==m)
            return true;   
        }
        return false;
    }
};