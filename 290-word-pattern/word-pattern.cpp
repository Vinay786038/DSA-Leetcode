class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char,string>mp;
        set<string>st;
        int n=pattern.size();
        int m=s.size();
        vector<string>words;
        string str="";
        for(int i=0;i<m;i++)
        {
            if(s[i]==' '&&str.size()!=0)
            {
                words.push_back(str);
                str="";
            }
            else if(s[i]!=' ')
            {
                str+=s[i];
            }
        }
        if(str.size()!=0)
        {
            words.push_back(str);
        }
        if(words.size()!=pattern.size())
        {
            return false;
        }
        n=words.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(pattern[i])!=mp.end())
            {
                if(mp[pattern[i]]!=words[i])
                {
                    return false;
                }
            }
            else
            {
                if(st.find(words[i])!=st.end())
                {
                    return false;
                }
                mp[pattern[i]]=words[i];
                st.insert(words[i]);
            }
        }
        return true;
    }
};