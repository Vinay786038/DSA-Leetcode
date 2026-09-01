class Solution {
public:
    int minMoves(vector<string>& classroom, int energy)
    {
        int n = classroom.size();
        int m = classroom[0].size();
        int sr = -1, sc = -1;
        vector<pair<int,int>> litter;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (classroom[i][j] == 'S')
                {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L')
                {
                    litter.push_back({i, j});
                }
            }
        }
        int k = litter.size();
        int fullMask = (1 << k) - 1;
        vector<vector<int>> litterId(n, vector<int>(m, -1));

        for (int i = 0; i < k; i++)
        {
            litterId[litter[i].first][litter[i].second] = i;
        }
        queue<tuple<int,int,int,int>> q;
        vector<vector<vector<vector<bool>>>> visited(n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );
        q.push({sr, sc, energy, 0});
        visited[sr][sc][energy][0] = true;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        int moves = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto [r, c, e, mask] = q.front();
                q.pop();
                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++)
                {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                    if (classroom[nr][nc] == 'X')   // '#' nahi
                        continue;

                    if (e == 0)
                        continue;
                    int ne = e - 1;
                    int nmask = mask;
                    if (classroom[nr][nc] == 'L')
                    {
                        int id = litterId[nr][nc];
                        nmask |= (1 << id);
                    }
                    if (classroom[nr][nc] == 'R')
                    {
                        ne = energy;
                    }
                    if (!visited[nr][nc][ne][nmask])
                    {
                        visited[nr][nc][ne][nmask] = true;
                        q.push({nr,nc,ne,nmask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};