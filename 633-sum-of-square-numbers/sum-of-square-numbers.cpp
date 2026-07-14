class Solution {
public:
    bool judgeSquareSum(int c)
    {
        long long l=sqrt(c);
        long long i=0;
        while(i<=l)
        {
            long long sum=(i*i)+(l*l);
            if(sum==c)
            {
                return true;
            }
            else if(sum<c)
            {
                i++;
            }
            else
            {
                l--;
            }
        }
        return false;

        
    }
};