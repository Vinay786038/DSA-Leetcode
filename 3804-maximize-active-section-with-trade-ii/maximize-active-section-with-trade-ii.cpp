class ST
{
public:
    int n;
    vector<int> tree;

    ST(vector<int> &arr)
    {
        n = arr.size();
        if (n == 0)
        {
            tree.resize(1, 0);
            return;
        }
        tree.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    void build(int node, int l, int r, vector<int> &arr)
    {
        if (l == r)
        {
            tree[node] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, arr);
        build(node * 2 + 1, mid + 1, r, arr);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr)
    {
        if (n == 0 || ql > qr)
            return 0;

        if (r < ql || l > qr)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return max(query(node * 2, l, mid, ql, qr),
                   query(node * 2 + 1, mid + 1, r, ql, qr));
    }
};

class Solution
{
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>> &queries)
    {
        int n = s.size();

        int ones = 0;
        vector<pair<int, int>> zeroes;

        int i = 0;

        while (i < n)
        {
            if (s[i] == '0')
            {
                int j = i;

                while (j < n && s[j] == '0')
                    j++;

                zeroes.push_back({i, j - 1});
                i = j;
            }
            else
            {
                ones++;
                i++;
            }
        }

        if (zeroes.size() < 2)
            return vector<int>(queries.size(), ones);

        vector<int> pairs;

        for (int i = 1; i < (int)zeroes.size(); i++)
        {
            int l1 = zeroes[i - 1].first;
            int r1 = zeroes[i - 1].second;

            int l2 = zeroes[i].first;
            int r2 = zeroes[i].second;

            pairs.push_back((r1 - l1 + 1) + (r2 - l2 + 1));
        }

        ST st(pairs);

        vector<int> starts, ends;

        for (auto &p : zeroes)
        {
            starts.push_back(p.first);
            ends.push_back(p.second);
        }

        vector<int> res;

        for (auto &q : queries)
        {
            int l = q[0];
            int r = q[1];

            int first = lower_bound(ends.begin(), ends.end(), l) - ends.begin();
            int last = upper_bound(starts.begin(), starts.end(), r) - starts.begin() - 1;

            if (first >= last)
            {
                res.push_back(ones);
                continue;
            }

            int best = st.query(1, 0, st.n - 1, first + 1, last - 2);

            int prev1 = min(zeroes[first].second, r) - max(zeroes[first].first, l) + 1;
            int next1 = min(zeroes[first + 1].second, r) - max(zeroes[first + 1].first, l) + 1;
            best = max(best, prev1 + next1);

            prev1 = min(zeroes[last - 1].second, r) - max(zeroes[last - 1].first, l) + 1;
            next1 = min(zeroes[last].second, r) - max(zeroes[last].first, l) + 1;
            best = max(best, prev1 + next1);

            res.push_back(ones + best);
        }

        return res;
    }
};