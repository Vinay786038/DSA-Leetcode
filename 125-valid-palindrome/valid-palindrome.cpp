class Solution {
public:
    bool isPalindrome(string s)
    {
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))
            {
                res+=tolower(s[i]);
            }
        }
        int left=0;
        int right=res.size()-1;
        while(left<right)
        {
            if(res[left]!=res[right])
            return false;
            left++;
            right--;
        }
        return true;
        
    }
};