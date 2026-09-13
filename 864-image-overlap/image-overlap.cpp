class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)
    {
        int ans=0;
        int n=img2.size();
        for(int i=-n+1;i<n;i++)
        {
            for(int j=-n+1;j<n;j++)
            {
                int overlap=0;
                for(int k=0;k<n;k++)
                {
                    for(int l=0;l<n;l++)
                    {
                        int x=i+k;
                        int y=j+l;
                        if((x>=0)&&(x<n)&&(y>=0)&&(y<n))
                        {
                            if((img1[k][l]==1)&&(img2[x][y]==1))
                            {
                                overlap++;
                            }
                        }
                    }
                }
                ans=max(ans,overlap);
            }
        }
        return ans;  
    }
};