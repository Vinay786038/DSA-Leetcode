class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge)
    {
        int n=knowledge.size();
        map<string,string>mp;
        for(int i=0;i<n;i++)
        {
            string key=knowledge[i][0];
            string value=knowledge[i][1];
            mp[key]=value;

        }
        n=s.size();
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                string key="";
                i++;
                while(s[i]!=')')
                {
                    key+=s[i];
                    i++;
                }
                if(mp.find(key)!=mp.end())
                {
                    ans+=mp[key];
                }
                else
                {
                    ans+='?';
                }
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;


        
    }
};