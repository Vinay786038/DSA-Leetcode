class Solution {
public:
    vector<vector<int>> original, modified;
    vector<int> last, ans, newParent;

    void dfs1(int node, string& s, vector<int>& parent) {
        int ch = s[node] - 'a';
        int prev = last[ch];

        if (node != 0 && prev != -1)
            newParent[node] = prev;
        else
            newParent[node] = parent[node];

        last[ch] = node;

        for (int child : original[node])
            dfs1(child, s, parent);

        last[ch] = prev;
    }

    int dfs2(int node) {
        int size = 1;

        for (int child : modified[node])
            size += dfs2(child);

        ans[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        original.assign(n, {});
        modified.assign(n, {});
        last.assign(26, -1);
        ans.assign(n, 0);
        newParent.assign(n, -1);

        // Build original tree
        for (int i = 1; i < n; i++)
            original[parent[i]].push_back(i);

        // Determine new parents using the original tree
        dfs1(0, s, parent);

        // Build modified tree
        for (int i = 1; i < n; i++)
            modified[newParent[i]].push_back(i);

        // Calculate subtree sizes
        dfs2(0);

        return ans;
    }
};