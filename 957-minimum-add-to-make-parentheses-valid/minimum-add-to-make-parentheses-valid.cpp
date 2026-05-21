class Solution {
public:
    int minAddToMakeValid(string s)
    {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                char x=s[i];
                st.push(x);
            }
            else if(s[i]==')'&&st.empty()!=1&&st.top()=='(')
            {
                st.pop();
            }
            else
            {
                char x=s[i];
                st.push(x);
            }
        }
        return st.size();
    }
};