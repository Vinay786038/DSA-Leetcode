
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        multiset<int> lo, hi;
        long long sumLo = 0, sumHi = 0;

        auto balance = [&]() {
            int target = (lo.size() + hi.size() + 1) / 2;

            while (lo.size() > target) {
                auto it = prev(lo.end());
                int v = *it;

                lo.erase(it);
                sumLo -= v;

                hi.insert(v);
                sumHi += v;
            }

            while (lo.size() < target) {
                auto it = hi.begin();
                int v = *it;

                hi.erase(it);
                sumHi -= v;

                lo.insert(v);
                sumLo += v;
            }
        };

        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                sumLo += v;
            } else {
                hi.insert(v);
                sumHi += v;
            }

            balance();
        };

        auto remove = [&](int v) {
            auto it = lo.find(v);

            if (it != lo.end()) {
                lo.erase(it);
                sumLo -= v;
            } else {
                it = hi.find(v);
                hi.erase(it);
                sumHi -= v;
            }

            balance();
        };

        vector<long long> cost(n - x + 1);

        // Sliding window
        for (int i = 0; i < n; i++) {

            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {

                long long med = *lo.rbegin();

                cost[i - x + 1] =
                    med * (long long)lo.size() - sumLo
                    + sumHi - med * (long long)hi.size();
            }
        }

        // DP with rolling arrays
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {

            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current element
                curr[i] = curr[i - 1];

                // Select window of length x
                if (i >= x) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
