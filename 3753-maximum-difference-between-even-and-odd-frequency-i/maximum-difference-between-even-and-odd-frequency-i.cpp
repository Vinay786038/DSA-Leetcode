class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]])
            mp[s[i]]++;
            else
            mp[s[i]]=1;
        }
        int odd=0;
        int even=INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]]%2==1&&odd<mp[s[i]])
            odd=mp[s[i]];
            if(mp[s[i]]%2==0&&even>mp[s[i]])
            even=mp[s[i]];
        }
        return odd-even;
        
    }
};