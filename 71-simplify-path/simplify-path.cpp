class Solution {
public:
    string simplifyPath(string path)
    {
        int n=path.size();
        stack<string>st;
        int i=0;
        while(i<n)
        {
            string s="";
            while(i<n&&path[i]=='/')
            {
                i++;
            }
            if(i>=n)
            break;
            while(i<n&&path[i]!='/')
            {
                s+=path[i];
                i++;
            }
            if(s==".")
            continue;
            else if(s=="..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s);
            }
        }
        string s="";
        while(!st.empty())
        {
            s="/"+st.top()+s;
            st.pop();
        }
        if(s.empty())
        {
            return "/";
        }
        return s;
        
    }
};