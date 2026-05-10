class Solution {
public:
    int mySqrt(int x) 
    {
        /*
        int res=-1;
        if(x<4&&x>0)
        return 1;
        int a=x/2;
        while(true)
        {
            if(a*a<=x)
            {
                break;
            }
            a/=2;
        }
        while(a*a<=x)
        {
            a++;
        }
        return a-1*/;
        return sqrt(x);
    }
};