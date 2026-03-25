class Solution {
public:
    //declare 2D vector globally
    vector<vector<string> >ans;
    bool issafe(int row,int col,vector<string>&board,int n)
    {
        //check column
        for(int i=row;i>=0;i--)
        {
            if(board[i][col]=='Q')
            return false;
        }
        //upper left diagonal
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
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(issafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(row+1,board,n);
                board[row][col]='.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string>board(n,string(n,'.'));
        solve(0,board,n);
        return ans;   
    }
};