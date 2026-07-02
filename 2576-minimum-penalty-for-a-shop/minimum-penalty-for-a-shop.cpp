class Solution {
public:
    int bestClosingTime(string customers)
    {
        int penality=0;
        int n=customers.size();
        int ans=0;
        for(char ch:customers)
        {
            if(ch=='Y')
            penality++;
        }
        int minpenality=penality;
        for(int i=0;i<=n;i++)
        {
            if(customers[i]=='Y')
            penality--;
            else
            penality++;
            if(penality<minpenality)
            {
                minpenality=penality;
                ans=i+1;
            }
        }
        return ans;
        
    }
};