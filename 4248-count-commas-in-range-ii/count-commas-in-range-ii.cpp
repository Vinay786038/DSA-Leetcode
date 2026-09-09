class Solution {
public:
    long long countCommas(long long n)
    {
        long long ans=0;
        long long m=n;
        while(m>999)
        {
            if(m==1e15)
            {
                long long x=m-(1e15-1);
                ans+=x*5;
                m=1e15-1;
            }
            else if(m<1e15&&m>=1e12)
            {
                long long x=m-(1e12-1);
                ans+=x*4;
                m=1e12-1;;
            }
            else if(m<1e12&&m>=1e9)
            {
                long long x=m-(1e9-1);
                ans+=x*3;
                m=1e9-1;
            }
            else if(m<1e9&&m>=1e6)
            {
                long long x=m-(1e6-1);
                ans+=x*2;
                m=1e6-1;;
            }
            else
            {
                int x=m-999;
                ans+=x;
                m=1e3-1;;
            }
        }          
        return ans;
    }
};