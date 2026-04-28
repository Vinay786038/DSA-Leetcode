class Solution {
public:
    int gcdOfOddEvenSums(int n)
    {
        if(n==1||n==2)
        return n;
        int a=1;
        int a1=0;
        int b=2;
        int b1=0;
        while(n>0)
        {
            a1+=a;
            a+=2;            
            b1+=b;
            b+=2;
            n--;
        }
        int ans=0;
        int k=a1/2;
        int i=2;
        while(i<k)
        {
            if(b1%i==0&&a1%i==0)
            {
                ans=i;
                i++;
            }
            else
            {
                i++;
            }
        }
        return ans;
        
    }
};