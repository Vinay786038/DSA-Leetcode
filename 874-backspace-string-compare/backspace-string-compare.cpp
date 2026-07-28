class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char>st1;
        stack<char>st2;
        for(int i=0;i<s.size();i++)
        {
            if(!st1.empty()&&s[i]=='#')
            {
                st1.pop();
            }
            else
            {
                if(s[i]!='#')
                st1.push(s[i]);
            }
        }
        for(int i=0;i<t.size();i++)
        {
            if(!st2.empty()&&t[i]=='#')
            {
                st2.pop();
            }
            else
            {
                if(t[i]!='#')
                st2.push(t[i]);
            }
        }
        string s1="";
        string s2="";
        while(!st1.empty())
        {
            s1+=st1.top();
            st1.pop();
        }
        while(!st2.empty())
        {
            s2+=st2.top();
            st2.pop();
        }
        if(s1.compare(s2)==0)
        return true;
        return false;
        
    }
};