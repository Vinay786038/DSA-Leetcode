class Solution {
public:
    string reverseVowels(string s)
    {
        map<char,char>mp;
        mp['a']='a';
        mp['e']='e';
        mp['i']='i';
        mp['o']='o';
        mp['u']='u';
        mp['A']='A';
        mp['E']='E';
        mp['I']='I';
        mp['O']='O';
        mp['U']='U';
        int left=0;
        int right=s.size()-1;
        while(left<right)
        {
            if(mp[s[left]]==s[left]&&mp[s[right]]==s[right])
            {
                char c=s[left];
                s[left]=s[right];
                s[right]=c;
                left++;
                right--;
            }
            if(!mp[s[left]])
            left++;
            if(!mp[s[right]])
            right--;
        }
        return s;
        
        
    }
};