class Solution {
public:
    struct Node {
        int child[26];
        int idx;

        Node() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<Node> trie;

    void updateIdx(int &cur, int nw,
                   vector<string>& wordsContainer) {

        if (cur == -1 ||
            wordsContainer[nw].size() <
                wordsContainer[cur].size() ||
            (wordsContainer[nw].size() ==
                 wordsContainer[cur].size() &&
             nw < cur)) {

            cur = nw;
        }
    }

    void insert(string &s, int ind,
                vector<string>& wordsContainer) {

        int node = 0;

        updateIdx(trie[node].idx, ind, wordsContainer);

        for (int i = (int)s.size() - 1; i >= 0; --i) {

            int c = s[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].child[c];

            updateIdx(trie[node].idx, ind, wordsContainer);
        }
    }

    int search(string &s) {

        int node = 0;

        for (int i = (int)s.size() - 1; i >= 0; --i) {

            int c = s[i] - 'a';

            if (trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.reserve(500001);   // IMPORTANT
        trie.emplace_back();    // root

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (auto &q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};