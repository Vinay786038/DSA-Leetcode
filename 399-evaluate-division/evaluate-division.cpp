class Solution
{
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string src, string dest, unordered_set<string> &visited)
    {
        if (src == dest)
            return 1.0;

        visited.insert(src);

        for (auto &it : graph[src])
        {
            string next = it.first;
            double weight = it.second;

            if (visited.count(next))
                continue;

            double ans = dfs(next, dest, visited);

            if (ans != -1.0)
                return weight * ans;
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>> &equations,vector<double> &values,vector<vector<string>> &queries)
    {
        for (int i = 0; i < equations.size(); i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];

            graph[a].push_back({b, value});
            graph[b].push_back({a, 1.0 / value});
        }

        vector<double> result;

        for (auto &q : queries)
        {
            string a = q[0];
            string b = q[1];

            if (graph.count(a) == 0 || graph.count(b) == 0)
            {
                result.push_back(-1.0);
            }
            else
            {
                unordered_set<string> visited;
                result.push_back(dfs(a, b, visited));
            }
        }

        return result;
    }
};