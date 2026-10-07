class Solution {
public:
    int ans = 0;

    void solve(vector<string>& arr, int index, int mask, int len) {

        ans = max(ans, len);

        for (int i = index; i < arr.size(); i++) {

            int currMask = 0;
            bool valid = true;

            for (char c : arr[i]) {
                int bit = c - 'a';

                // Duplicate character inside current string
                if (currMask & (1 << bit)) {
                    valid = false;
                    break;
                }

                currMask |= (1 << bit);
            }

            // Current string itself is invalid
            if (!valid)
                continue;

            // Character already present in previous strings
            if (mask & currMask)
                continue;

            solve(arr, i + 1, mask | currMask,
                  len + arr[i].size());
        }
    }

    int maxLength(vector<string>& arr) {
        solve(arr, 0, 0, 0);
        return ans;
    }
};