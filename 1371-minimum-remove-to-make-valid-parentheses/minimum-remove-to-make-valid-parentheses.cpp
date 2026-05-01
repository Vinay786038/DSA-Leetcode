class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            st.push(i);
            else if(st.empty()!=1&&s[st.top()]==s[i]&&s[i]==')')
            {
                st.push(i);
            }
            else if(st.empty()!=1&&s[i]==')')
            {
                st.pop();
            }
            else if(st.empty()==1&&s[i]==')')
            {
                st.push(i);
            }
            
        }
        if(st.empty()==1)
        return s;
        while(st.empty()!=1)
        {
            int a=st.top();
            st.pop();
            s.erase(a,1);
        }
        return s;
        
    }
};