class Solution {
public:
    int minimumPushes(string word)
    {
        int ans=0;
        int n=word.size();
        if(n<=8)
        {
            ans=n;
        }
        else if(n>8&&n<=16)
        {
            ans=8;
            int x=n-8;
            ans+=x*2;
        }
        else if(n>16&&n<=24)
        {
            ans=8;
            n=n-8;
            int x=8*2;
            ans+=x;
            n=n-8;
            ans+=n*3;
        }
        else if(n>24&&n<=26)
        {
            ans=8;
            n-=8;
            ans+=8*2;
            n-=8;
            ans+=8*3;
            n=n-8;
            ans+=n*4;
        }
        else
        {
            ans=0;
        }
        return ans;
        
    }
};