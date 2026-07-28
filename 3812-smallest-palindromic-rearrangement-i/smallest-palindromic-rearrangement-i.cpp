class Solution {
public:
    string smallestPalindrome(string s)
    {
        vector<int>count(26,0);
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            count[ch-'a']++;
        }
        string left="";
        char mid=0;
        for(int i=0;i<26;i++)
        {
            left.append(count[i]/2,'a'+i);
            if(count[i]%2)
            {
                mid='a'+i;
            }
        }
        string ans=left;
        if(mid)
        ans+=mid;
        reverse(left.begin(),left.end());
        ans+=left;
        return ans;
        
    }
};