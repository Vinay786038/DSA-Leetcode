class Solution {
public:
    int numberOfSteps(int num)
    {
        int n=num;
        int x=0;
        while(n>0)
        {
            x++;
            if(n%2==0)
            {
                n/=2;
            }
            else
            {
                n--;
            }
        }
        return x;
    }
};