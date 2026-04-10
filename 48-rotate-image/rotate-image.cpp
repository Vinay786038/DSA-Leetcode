class Solution {
public:
   /* void swap(int *a,int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
        return;
    }*/
    void rotate(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        //transpose
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse row
        for(int i=0;i<n;i++)
        {
            int start=0;
            int end=n-1;
            while(start<end)
            {
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
        return;
    }
};