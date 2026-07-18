class Solution
{
    public:
        int countCharacters(vector<string>& words, string chars) 
        {
            map<char,int>mp;
            int ans=0;
            for(int i=0;i<chars.size();i++)
            {
                if(mp[chars[i]])
                mp[chars[i]]++;
                else
                mp[chars[i]]=1;
            }
            for(int i=0;i<words.size();i++)
            {
                string s=words[i];
                int l=0;
                map<char,int>temp=mp;;
                for(int j=0;j<s.size();j++)
                {
                    if(temp[s[j]]>0)
                    {
                        l++;
                        temp[s[j]]--;
                    }
                    else
                    {
                        l=0;
                        break;
                    }
                }
                ans+=l;
            }

            return ans;
        }
};