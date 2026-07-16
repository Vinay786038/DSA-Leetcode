class Solution {
public:
    string largestEven(string s)
    {
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='2')
            {
                return s;
            }
            s.erase(i,1);
        }
        return "";


        
    }
};