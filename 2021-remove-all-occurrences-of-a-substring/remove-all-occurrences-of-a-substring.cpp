class Solution {
public:
    string removeOccurrences(string s, string part)
    {
        if(s.size()<part.size())
        return s;
        int n=s.size();
        string ans;
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            int m=part.size()-1;
            if(st.empty()==1)
            st.push(s[i]);
            else
            {
                if(st.top()==part[m])
                {
                    stack<char>st2;
                    while(m>=0&&st.empty()!=1&&st.top()==part[m])
                    {
                        st2.push(st.top());
                        st.pop();
                        m--;
                    }
                    if(m>-1)
                    {
                        while(st2.empty()!=1)
                        {
                            st.push(st2.top());
                            st2.pop();
                        }
                    }
                }
                st.push(s[i]);
            }
        }
        int m=part.size()-1;
        if(st.top()==part[m])
        {
            stack<char>st2;
            while(st.empty()!=1&&m>=0&&st.top()==part[m])
            {
                st2.push(st.top());
                st.pop();
                m--;
            }
            if(m>-1)
            {
                while(st2.empty()!=1)
                {
                    st.push(st2.top());
                    st2.pop();
                }
            }
        }
        while(st.empty()!=1)
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};