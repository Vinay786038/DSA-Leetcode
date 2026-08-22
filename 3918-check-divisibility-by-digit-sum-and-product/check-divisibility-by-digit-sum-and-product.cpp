class Solution {
public:
    bool checkDivisibility(int n)
    {
        int sum=0;
        long pro=1;
        int m=n;
        while(m>0)
        {
            int rem=m%10;
            sum+=rem;
            pro*=rem;
            m/=10;
        }
        if(n%(sum+pro)==0)
        {
            return true;
        }
        return false;
        
    }
};