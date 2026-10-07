class Solution {
public:
    vector<string> ans;

    void dfs(string& s, int start, int lremove, int rremove) {
        // If removals are finished, check validity
        if (lremove == 0 && rremove == 0) {
            int balance = 0;

            for (char c : s) {
                if (c == '(')
                    balance++;
                else if (c == ')') {
                    balance--;

                    if (balance < 0)
                        return;
                }
            }

            if (balance == 0)
                ans.push_back(s);

            return;
        }

        for (int i = start; i < s.size(); i++) {

            // Don't remove duplicate parentheses
            if (i > start && s[i] == s[i - 1])
                continue;

            // We only remove parentheses
            if (s[i] != '(' && s[i] != ')')
                continue;

            // Remove '('
            if (lremove > 0 && s[i] == '(') {
                char ch = s[i];
                s.erase(s.begin() + i);

                dfs(s, i, lremove - 1, rremove);

                s.insert(s.begin() + i, ch);
            }

            // Remove ')'
            if (rremove > 0 && s[i] == ')') {
                char ch = s[i];
                s.erase(s.begin() + i);

                dfs(s, i, lremove, rremove - 1);

                s.insert(s.begin() + i, ch);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        ans.clear();

        int left = 0;
        int right = 0;

        // Find minimum removals
        for (char c : s) {
            if (c == '(') {
                left++;
            }
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        dfs(s, 0, left, right);

        return ans;
    }
};