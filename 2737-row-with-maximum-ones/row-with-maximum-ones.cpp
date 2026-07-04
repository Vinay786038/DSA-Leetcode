class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat)
    {
        int m=mat.size();
        int n=mat[0].size();
        int index=0;
        int count=0;
        for(int i=0;i<m;i++)
        {
            int count1=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    count1++;
                }
            }
            if(count1>count)
            {
                index=i;
                count=count1;
            }
        }
        return {index,count};

        
    }
};