class Solution {
public:
    set<string> mergeUnion(set<string>& a, set<string>& b)
    {
        set<string> res = a;
        for (auto &x : b)
            res.insert(x);

        return res;
    }

    set<string> multiply(set<string>& a, set<string>& b)
    {
        set<string> res;

        for (auto &x : a) {
            for (auto &y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    set<string> solve(string& s, int& i) {

        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {

                i++; // skip {

                set<string> inside = solve(s, i);

                i++; // skip }

                current = multiply(current, inside);
            }

            else if (s[i] == ',') {

                // Union current with result
                result = mergeUnion(result, current);

                current = {""};

                i++;
            }

            else {

                // Read consecutive characters
                string word;

                while (i < s.size() &&
                       s[i] >= 'a' &&
                       s[i] <= 'z') {
                    word += s[i];
                    i++;
                }

                set<string> temp = {word};

                current = multiply(current, temp);
            }
        }

        result = mergeUnion(result, current);

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};