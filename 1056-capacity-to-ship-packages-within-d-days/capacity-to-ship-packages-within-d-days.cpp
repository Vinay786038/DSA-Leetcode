class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days)
    {
        int n=weights.size();        
        int minn=*max_element(weights.begin(),weights.end());
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            maxx+=weights[i];
        }
        while(minn<maxx)
        {
            int sum=0;
            int cnt=1;
            int capacity=minn+(maxx-minn)/2;
            for(int i=0;i<n;i++)
            {
                if(sum+weights[i]>capacity)
                {
                    cnt++;
                    sum=weights[i];
                }
                else
                {
                    sum+=weights[i];
                }
            }
            if(cnt<=days)
            {
                maxx=capacity;
            }
            else
            {
                minn=capacity+1;
            }
        }
        return minn;


        
    }
};