class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            unordered_map<char,char>mp;
            set<char>st;
            bool x=true;
            for(int j=0;j<s.size();j++)
            {
                if(mp.find(pattern[j])!=mp.end())
                {
                    if(mp[pattern[j]]!=s[j])
                    {
                        x=false;
                        break;
                    }
                }
                else
                {
                    if(st.find(s[j])!=st.end())
                    {
                        x=false;
                        break;
                    }
                    mp[pattern[j]]=s[j];
                    st.insert(s[j]);
                }
               
            }
            if(x)
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};