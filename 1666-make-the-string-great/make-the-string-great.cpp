class Solution {
public:
    int myabs(int x,int y)
    {
        if(x>y)
        return x-y;
        return y-x;
    }
    string makeGood(string s) 
    {
        stack<char>st;
        st.push(s[0]);
        int i=1;
        int n=s.size();
        while(i<n)
        {
            if(st.size()>0&&myabs(st.top(),s[i])==32)
            {
                st.pop();
            }
            else
            st.push(s[i]);
            i++;
        }
        string ans;
        while(st.empty()!=1)
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};