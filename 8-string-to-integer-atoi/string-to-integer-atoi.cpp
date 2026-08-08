class Solution {
public:
    int myAtoi(string s)
    {
        int x=0;
        int n=s.size();
        bool neg=false;
        int i=0;
        while(s[i]==' ')
        {
            i++;
        }
        if(i<n&&(s[i]=='-'||s[i]=='+'))
        {
            if(s[i]=='-')
            {
                neg=true;
            }
            i++;
        }
        while(i<n&&isdigit(s[i]))
        {
            int digit=s[i]-'0';
            if(x>(INT_MAX-digit)/10)
            {
                if(neg)
                return INT_MIN;
                else
                return INT_MAX;
            }
            x=x*10+digit;

            i++;
        }
        if(neg)
        return -x;
        return x;
        
    }
};