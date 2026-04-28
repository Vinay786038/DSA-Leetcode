class Solution {
public:
    int gcdOfOddEvenSums(int n)
    {
        int s,t;
        s=n*n;
        t=n*(n+1);
        return gcd(s,t);
        
    }
};