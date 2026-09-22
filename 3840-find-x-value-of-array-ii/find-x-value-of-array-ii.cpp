class Solution {
public:

    struct Node {
        int prod = 1;
        int cnt[5] = {};
    };

    int k;
    int n;
    vector<Node> tree;

    Node merge(const Node& a, const Node& b) {
        Node c;

        c.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left
        memcpy(c.cnt, a.cnt, sizeof(c.cnt));

        // Prefixes which include the whole left
        // and a prefix of right
        for (int r = 0; r < k; r++) {
            c.cnt[(a.prod * r) % k] += b.cnt[r];
        }

        return c;
    }

    void build(int u, int l, int r, vector<int>& nums) {

        if (l == r) {
            int v = nums[l] % k;

            tree[u].prod = v;
            tree[u].cnt[v] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        build(u << 1, l, mid, nums);
        build(u << 1 | 1, mid + 1, r, nums);

        tree[u] = merge(tree[u << 1], tree[u << 1 | 1]);
    }

    void update(int u, int l, int r, int pos, int val) {

        if (l == r) {
            val %= k;

            tree[u].prod = val;

            memset(tree[u].cnt, 0, sizeof(tree[u].cnt));
            tree[u].cnt[val] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid)
            update(u << 1, l, mid, pos, val);
        else
            update(u << 1 | 1, mid + 1, r, pos, val);

        tree[u] = merge(tree[u << 1], tree[u << 1 | 1]);
    }

    Node query(int u, int l, int r, int ql, int qr) {

        if (ql <= l && r <= qr)
            return tree[u];

        int mid = (l + r) >> 1;

        if (qr <= mid)
            return query(u << 1, l, mid, ql, qr);

        if (ql > mid)
            return query(u << 1 | 1, mid + 1, r, ql, qr);

        Node left = query(u << 1, l, mid, ql, qr);
        Node right = query(u << 1 | 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->k = k;
        n = nums.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};