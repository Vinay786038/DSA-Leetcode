class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries)
    {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums) {
            freq[x]++;
        }

        vector<long long> cnt(mx + 1, 0);

        for (int g = 1; g <= mx; g++) {
            for (int m = g; m <= mx; m += g) {
                cnt[g] += freq[m];
            }
        }

        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            exact[g] = cnt[g] * (cnt[g] - 1) / 2;

            for (int m = 2 * g; m <= mx; m += g) {
                exact[g] -= exact[m];
            }
        }

        vector<long long> pref;
        vector<int> value;

        long long sum = 0;

        for (int g = 1; g <= mx; g++) {
            if (exact[g] > 0) {
                sum += exact[g];
                pref.push_back(sum);
                value.push_back(g);
            }
        }

        vector<int> ans;

        for (long long q : queries) {
            int idx =
                lower_bound(pref.begin(), pref.end(), q + 1)
                - pref.begin();

            ans.push_back(value[idx]);
        }

        return ans;
        
    }
};