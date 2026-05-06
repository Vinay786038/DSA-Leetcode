class Solution {
public:
    int trailingZeroes(int n)
    {
        int zeroes=0;
        int k=5;
        while(true)
        {
            if(k>n)
            break;
            zeroes+=n/k;
            k*=5;
        }
        return zeroes; 
    }
};