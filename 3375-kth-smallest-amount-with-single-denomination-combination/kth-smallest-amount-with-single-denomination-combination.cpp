class Solution {
public:
    long long lcm(long long a, long long b)
    {
        return a / gcd(a, b) * b;
    }
    long long findKthSmallest(vector<int>& coins, int k)
    {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        while (low < high)
        {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            int n = coins.size();
            // Inclusion-Exclusion
            for (int mask = 1; mask < (1 << n); mask++)
            {
                long long L = 1;
                int bits = 0;
                bool valid = true;
                for (int i = 0; i < n; i++)
                {
                    if (mask & (1 << i))
                    {
                        bits++;
                        L = lcm(L, coins[i]);
                        if (L > mid)
                        {
                            valid = false;
                            break;
                        }
                    }
                }
                if (!valid)
                    continue;
                long long curr = mid / L;
                if (bits % 2 == 1)
                    count += curr;
                else
                    count -= curr;
            }
            if (count >= k)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};