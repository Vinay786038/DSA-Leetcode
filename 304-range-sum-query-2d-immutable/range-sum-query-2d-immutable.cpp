class NumMatrix {
public:
    vector<vector<int>>pref;
    NumMatrix(vector<vector<int>>& matrix)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        pref.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=matrix[i][j];
                pref[i][j]=sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum=0;
        for(int i=row1;i<=row2;i++)
        {
            if(col1>0)
            {
                sum+=(pref[i][col2]-pref[i][col1-1]);
            }
            else
            {
                sum+=(pref[i][col2]);
            }
            
        }
        return sum;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */