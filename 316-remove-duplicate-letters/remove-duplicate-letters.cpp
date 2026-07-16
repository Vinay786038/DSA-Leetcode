class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        int n=s.size();
        vector<int>last(26);
        for(int i=0;i<n;i++)
        {
            last[s[i]-'a']=i;
        }
        vector<bool>visi(26,false);
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(visi[ch-'a'])
            {
                continue;
            }
            while(!st.empty()&&st.top()>ch&&last[st.top()-'a']>i)
            {
               
                visi[st.top()-'a']=false;
                st.pop();
            }
            st.push(ch);
            visi[ch-'a']=true;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

     
    }
};