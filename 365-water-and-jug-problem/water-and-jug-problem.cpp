class Solution {
public:
    int gcd(int x,int y)
    {
        while(y)
        {
            int t=x%y;
            x=y;
            y=t;;
        }
        return x;
    }
    bool canMeasureWater(int x, int y, int target)
    {
        if(target==0)
        {
            return true;
        }
        if(x+y<target)
        {
            return false;
        }
        return target%gcd(x,y)==0;

        
    }
};