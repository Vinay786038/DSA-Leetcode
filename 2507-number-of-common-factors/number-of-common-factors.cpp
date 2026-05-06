class Solution {
public:
    int commonFactors(int a, int b)
    {
        int small;
        int factors=0;
        small=a<b?a:b;
        for(int i=1;i<=small;i++)
        {
            if(a%i==0&&b%i==0)
            factors++;

        }
        return factors;
        
    }
};