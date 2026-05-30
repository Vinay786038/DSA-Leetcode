class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        stack<int>s;
        for(int i=0;i<num.size();i++)
        {
            int x=num[i]-'0';
            while(s.empty()!=1&&s.top()>x&&k>0)
            {
                s.pop();
                k--;
            }
            s.push(x);
        }
        while(k>0&&s.empty()!=1)
        {
            s.pop();
            k--;
        }
        string str;
        while(s.empty()!=1)
        {
            str+=(char)(s.top()+'0');
            s.pop();
        }
        reverse(str.begin(),str.end());
        int i=0;
        while(i<str.size()&&str[i]=='0')
        {
            i++;
        }
        str=str.substr(i);
        if(str.empty()==1)
        str+='0';
        return str;
    }
};