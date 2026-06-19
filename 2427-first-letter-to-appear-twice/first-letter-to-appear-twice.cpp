class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]])
            return s[i];
            mp[s[i]]=1;
        }
        return 'c';
        
    }
};