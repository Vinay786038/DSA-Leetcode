class Solution {
public:
    string reverseWords(string s)
    {
        string str;
        int len=0;
        bool x=true;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                len++;
                x=false;
            }
            else
            {
                str+=s.substr(i+1,len);
                if(x==false)
                str+=" ";
                len=0;
                x=true;
            }
        }
        if(0<len)
        {
            str+=s.substr(0,len);
        }
        if(str.back()==' ')
        str.pop_back();
        return str;
    }
};