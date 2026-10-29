
class Solution {
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout;
    string s;
    int timer = 0;

    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void update(int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        }

        int query(int i) {
            int ans = 0;
            for (; i > 0; i -= i & -i)
                ans ^= bit[i];
            return ans;
        }

        void rangeUpdate(int l, int r, int val) {
            update(l, val);
            if (r + 1 <= n)
                update(r + 1, val);
        }
    };

    void dfs(int root) {
        vector<pair<int, int>> st;
        st.push_back({root, 0});

        while (!st.empty()) {
            auto [u, state] = st.back();
            st.pop_back();

            if (state == 0) {
                tin[u] = ++timer;
                st.push_back({u, 1});

                for (int v : adj[u]) {
                    if (v == up[0][u]) continue;

                    up[0][v] = u;
                    depth[v] = depth[u] + 1;
                    st.push_back({v, 0});
                }
            } else {
                tout[u] = timer;
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                u = up[j][u];
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string str,
        vector<string>& queries
    ) {
        s = str;
        adj.assign(n, {});
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        timer = 0;

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n, 0));

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        up[0][0] = 0;
        dfs(0);

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        Fenwick fw(n);

        // Each node contributes its character
        // to the root-prefix masks of its subtree.
        for (int u = 0; u < n; u++) {
            int mask = 1 << (s[u] - 'a');
            fw.rangeUpdate(tin[u], tout[u], mask);
        }

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                fw.rangeUpdate(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);

                int maskU = fw.query(tin[u]);
                int maskV = fw.query(tin[v]);
                int maskW = 1 << (s[w] - 'a');

                int pathMask = maskU ^ maskV ^ maskW;

                // At most one character can have odd frequency.
                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
