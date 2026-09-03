class Solution {
public:
    int minInsertions(string s) 
    {
        int n=s.size();
        int i=0;
        stack<char>st;
        int ans=0;
        while(i<n)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else
            {
                if(i+1<n&&s[i+1]==')')
                {
                    if(!st.empty())
                    {
                        st.pop();
                    }
                    else
                    {
                        ans++;
                    }
                    i++;
                }
                else
                {
                    ans++;
                    if(!st.empty())
                    {
                        st.pop();
                    }
                    else
                    {
                        ans++;
                    }
                }
            }
            i++;
        }
        while(!st.empty())
        {
            ans+=2;
            st.pop();
        }
        return ans;
                
    }
};