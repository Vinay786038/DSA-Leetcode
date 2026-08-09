class Solution {
public:
    string largestOddNumber(string num)
    {
        string s=num;
        int n=num.size()-1;
        while(n>=0)
        {
            int x=num[n]-'0';
            if(x%2!=0)
            {
                return s;
            }
            s.pop_back();
            n--;
        }
        return "";
        
    }
};