class Solution {
public:
    string removeDuplicates(string s)
    {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(st.top()==s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        int i=0;
        int j=ans.size()-1;
        while(i<j)
        {
            char c=ans[i];
            ans[i]=ans[j];
            ans[j]=c;
            i++;
            j--;
        }
        return ans;
        
    }
};