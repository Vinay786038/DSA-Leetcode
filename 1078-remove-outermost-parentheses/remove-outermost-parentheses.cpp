class Solution {
public:
    string removeOuterParentheses(string s)
    {
        string ans="";
        int depth=0;
        for(char c:s)
        {
            if(c=='(')
            {
                if(depth>0)
                {
                    ans+=c;
                }
                depth++;
            }
            else
            {
                if(depth>1)
                {
                    ans+=c;
                }
                depth--;
            }
           
        }
        return ans;
        
    }
};