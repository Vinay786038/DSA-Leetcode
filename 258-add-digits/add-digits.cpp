class Solution {
public:
    int addDigits(int num)
    {
        int res=0;
        if(num<=9&&num>0)
        return num;
        while(num>9)
        {
            res=0;
            while(num>0)
            {
                int rem=num%10;
                res+=rem;
                num/=10;
            }
            num=res;
            
        }
        return res;
    }
};