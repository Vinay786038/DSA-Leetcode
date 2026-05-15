class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int n=bills.size();
        int five=0;
        int ten=0;
        int twenty=0;
        if(bills[0]>5)
        return false;
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            five++;
            else if(bills[i]==10)
            {
                if(five>0)
                {
                    five--;
                    ten++;
                }
                else
                return false;
            }
            else if(bills[i]==20)
            {
                if(five>0&&ten>0)
                {
                    five--;
                    ten--;
                    twenty++;
                }
                else if(five>2)
                {
                    five-=3;
                    twenty++;
                }
                else
                return false;

            }
            else
            return false;
        }   
        return true;
    }
};