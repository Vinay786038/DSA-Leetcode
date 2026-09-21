class Solution {
public:
    int buyChoco(vector<int>& prices, int money)
    {
        int n=prices.size();
        int small1=-1;
        int ind=-1;
        for(int i=0;i<n;i++)
        {
            if(small1==-1||prices[i]<=small1)
            {
                small1=prices[i];
                ind=i;
            }
        }
        int small2;
        if(ind==0)
        {
            small2=prices[1];
        }
        else
        {
            small2=prices[0];
        }
        for(int i=0;i<n;i++)
        {
            if(i==ind)
            {
                continue;
            }
            else if(prices[i]>=small1&&prices[i]<small2)
            {
                small2=prices[i];
            }
        }
        if((small1+small2)>money)
        return money;
        return money-(small1+small2);
    }
};