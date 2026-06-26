class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<vector<int>>vec;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    vec.push_back({i,j});
                }
            }
        }
        for(int i=0;i<vec.size();i++)
        {
            int m=vec[i][0];
            int n=vec[i][1];
            for(int j=0;j<matrix[0].size();j++)
            {
                matrix[m][j]=0;
            }
            for(int j=0;j<matrix.size();j++)
            {
                matrix[j][n]=0;
            }
        }
        return;
    }
};