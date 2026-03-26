class Solution {
public:
    int ans=0;
    bool issafe(int row,int col,vector<string>&board,int n)
    {
        for(int i=row;i>=0;i--)
        {
            if(board[i][col]=='Q')
            return false;
        }
        for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
            return false;
        }
        //upper right diagonal
        for(int i=row,j=col;i>=0&&j<n;i--,j++)
        {
            if(board[i][j]=='Q')
            return false;
        }
        return true;
    }
    void solve(int row,vector<string>&board,int n)
    {
        if(row==n)
        {
            ans++;
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(issafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(row+1,board,n);
                board[row][col]='.';//backtracking
            }
        }
        return;
    }
    int totalNQueens(int n)
    {
        vector<string> board(n,string(n,'.'));
        solve(0,board,n);
        return ans; 
    }
};