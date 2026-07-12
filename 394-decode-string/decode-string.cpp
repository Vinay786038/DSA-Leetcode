class Solution {
public:
    string decodeString(string s) 
    {
        int n=s.size();
        stack<int>st1;
        stack<char>st2;
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                int x=0;
                bool y=false;
                while(isdigit(s[i]))
                {
                    y=true;
                    x=x*10+(s[i]-'0');
                    i++;
                }
                if(y)
                i--;
                st1.push(x);
                continue;
            }
            if(s[i]==']')
            {
                string x="";
                while(!st2.empty()&&st2.top()!='[')
                {
                    x+=st2.top();
                    st2.pop();
                }
                st2.pop();
                reverse(x.begin(),x.end());
                int digit=st1.top();
                st1.pop();
                string y="";
                while(digit)
                {
                    y+=x;
                    digit--;
                }
                int size=y.size();
                int index=0;
                while(index<size)
                {
                    st2.push(y[index]);
                    index++;
                }
            }
            else
            {
                st2.push(s[i]);
            }
        }
        while(!st2.empty())
        {
            ans+=st2.top();
            st2.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};