class Solution {
public:
    bool checkPerfectNumber(int num) {
        int x=0;
        for(int i=1;i<=num/2;i++)
        {
            if(num%i==0)
            {
                x+=i;
            }
        }
        if(x==num)
        return true;
        return false;
        
    }
};