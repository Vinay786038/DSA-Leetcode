class Solution {
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int n = s.size();
        int ans = 0;

        // Count total active sections
        for (char c : s)
            if (c == '1')
                ans++;

        int pre = INT_MIN;
        int mx = 0;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i])
                j++;

            int len = j - i;

            if (s[i] == '0') {
                mx = max(mx, pre + len);
                pre = len;
            }

            i = j;
        }

        return ans + mx;
    }
};