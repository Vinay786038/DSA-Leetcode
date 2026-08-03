class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<bool>>visi(m,vector<bool>(n,0));
        stack<pair<int,int>>st;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='0')
                {
                    continue;
                }
                if(visi[i][j]==1)
                {
                    continue;
                }
                st.push(make_pair(i,j));
                ans++;
                while(!st.empty())
                {
                    int ii=st.top().first;
                    int jj=st.top().second;
                    if(visi[ii][jj]==1)
                    {
                        st.pop();
                        continue;
                    }
                    visi[ii][jj]=1;
                    if(ii+1<m && grid[ii+1][jj]=='1' && !visi[ii+1][jj])
                    st.push({ii+1,jj});

                    if(ii-1>=0 && grid[ii-1][jj]=='1' && !visi[ii-1][jj])
                    st.push({ii-1,jj});

                    if(jj+1<n && grid[ii][jj+1]=='1' && !visi[ii][jj+1])
                    st.push({ii,jj+1});

                    if(jj-1>=0 && grid[ii][jj-1]=='1' && !visi[ii][jj-1])
                    st.push({ii,jj-1});
                }
            }
        }
        return ans;
        
    }
};