class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int total=0;
        int n=cardPoints.size();
        for(int i=0;i<n;i++)
        {
            total+=cardPoints[i];
        }
        int win=n-k;
        if(win==0)
        {
            return total;
        }
        int curr=0;
        for(int i=0;i<win;i++)
        {
            curr+=cardPoints[i];
        }
        int minwin=curr;
        for(int i=win;i<n;i++)
        {
            curr+=cardPoints[i];
            curr-=cardPoints[i-win];
            minwin=min(minwin,curr);

        }
        return total-minwin;
        
    }
};