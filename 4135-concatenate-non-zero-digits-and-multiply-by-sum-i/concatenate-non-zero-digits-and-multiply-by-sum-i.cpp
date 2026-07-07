class Solution {
public:
    long long sumAndMultiply(int n)
    {
        long long sum=0;
        long long mul=1;
        long long num=0;
        int m=n;
        while(m>0)
        {
            int rem=m%10;
            if(rem>0)
            {
                num=rem*mul+num;
                mul*=10;
                sum+=rem;
            }
            m/=10;
        }
        return sum*num;

        
    }
};