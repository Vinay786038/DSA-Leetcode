class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        int m=mat.size();
        int n=mat[0].size();
        bool dir=0;
        int row=0;
        int col=0;
        vector<int>ans;
        for(int i=0;i<m*n;i++)
        {
            ans.push_back(mat[row][col]);
            if(dir==0)
            {
               
                row--;
                col++;
                if(col>=n)
                {
                    col=n-1;
                    row=row+2;
                    dir=1;
                }   
                else if(row<0)
                {
                    dir=1;
                    row=0;
                }  
            }
            else if(dir==1)
            {
                row++;
                col--;
                if(row>=m)
                {
                    col+=2;
                    dir=0;
                    row=m-1;
                }
                else if(col<0)
                {
                    dir=0;
                    col=0;
                }
            }
            
        }
        return ans;

        
    }
};