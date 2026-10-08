class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        int mask = 0;

        for (int bit = 30; bit >= 0; bit--) {

            mask |= (1 << bit);

            unordered_set<int> st;

            // Store prefixes
            for (int num : nums) {
                st.insert(num & mask);
            }

            // Try to make current bit of XOR = 1
            int candidate = ans | (1 << bit);

            for (int prefix : st) {
                int needed = prefix ^ candidate;

                if (st.find(needed) != st.end()) {
                    ans = candidate;
                    break;
                }
            }
        }

        return ans;
    }
};