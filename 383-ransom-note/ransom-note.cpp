class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char,int>mp;
        for(int i=0;i<magazine.size();i++)
        {
            if(mp[magazine[i]])
            {
                mp[magazine[i]]++;
            }
            else
            mp[magazine[i]]=1;
        }
        for(int i=0;i<ransomNote.size();i++)
        {
            if(mp[ransomNote[i]]>0)
            {
                mp[ransomNote[i]]--;
            }
            else
            return false;
        }
        return true;
        
    }
};