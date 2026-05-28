class Solution {
public:
    bool halvesAreAlike(string s)
    {
        int n=s.size();
        string a;
        string b;
        for(int i=0;i<n/2;i++)
        {
            a+=s[i];
        }
        for(int i=n/2;i<n;i++)
        {
            b+=s[i];
        }
        int vowel1=0;
        int vowel2=0;
        map<char,int>mp;
        mp['a']=1;
        mp['e']=1;
        mp['i']=1;
        mp['o']=1;
        mp['u']=1;
        mp['A']=1;
        mp['E']=1;
        mp['I']=1;
        mp['O']=1;
        mp['U']=1;
        for(int i=0;i<n/2;i++)
        {
            if(mp[a[i]])
            vowel1++;
            if(mp[b[i]])
            vowel2++;
        }
        if(vowel1==vowel2)
        return true;
        return false;
        
    }
};