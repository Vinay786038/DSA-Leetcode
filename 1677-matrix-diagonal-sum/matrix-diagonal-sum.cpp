class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        int n=mat.size();
        int i=0;
        int j=n-1;
        int sum=0;
        for(int row=0;row<n;row++)
        {
            if(i==j)
            {
                sum+=mat[row][i];
                i++;
                j--;
            }
            else
            {
                sum+=mat[row][i];
                sum+=mat[row][j];
                i++;
                j--;
            }
        }
        return sum;

        
    }
};