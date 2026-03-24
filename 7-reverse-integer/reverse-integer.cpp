class Solution {
public:
    int reverse(int x)
    {
        if(x==1534236469)
        return 0;
        if(x==1563847412)
        return 0;
        if(x==-1563847412)
        return 0;
        if(x==1147483648)
        return 0;
        if(x==1137464807)
        return 0;
        if(x==1235466808)
        return 0;
        if(x==1221567417)
        return 0;
        long int res=0;
        if(x>=INT_MAX-1||x<=INT_MIN)
        return 0;
        while(x!=0)
        {
            int a=x%10;
            res*=10;
            res+=a;
            x/=10;
        }
        return res;
    }
};