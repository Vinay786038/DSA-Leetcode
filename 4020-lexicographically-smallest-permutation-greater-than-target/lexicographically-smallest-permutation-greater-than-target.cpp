class Solution {
public:
    string lexGreaterPermutation(string s, string target)
    {
        int n=s.size();
        vector<int>freq(26,0);
        for(char c:s)
        {
            freq[c-'a']++;
        }
        int pos=-1;
        int bigger=-1;
        for(int i=0;i<n;i++)
        {
            int x=target[i]-'a';
            for(int c=x+1;c<26;c++)
            {
                if(freq[c]>0)
                {
                    pos=i;
                    bigger=c;
                    break;
                }
            }
            if(freq[x])
            {
                freq[x]--;
            }
            else
            {
                break;
            }
        }
        if(pos==-1)
        return "";
        freq.assign(26,0);
        for(char c:s)
        {
            freq[c-'a']++;
        }
        for(int i=0;i<pos;i++)
        {
            freq[target[i]-'a']--;
        }
        freq[bigger]--;
        string ans=target.substr(0,pos);
        ans+=char('a'+bigger);
        for(int c=0;c<26;c++)
        {
            ans+=string(freq[c],'a'+c);
        }
        return ans;
    }
};