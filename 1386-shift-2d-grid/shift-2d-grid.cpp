class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int m=grid.size();
        int n=grid[0].size();
        k=k%(m*n);
        if(k==0)
        return grid;
        vector<vector<int>>arr(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=(i*n+j+k)%(m*n);
                int a=x/n;
                int b=x%n;
                arr[a][b]=grid[i][j];
            }
        }
        return arr;
        
    }
};