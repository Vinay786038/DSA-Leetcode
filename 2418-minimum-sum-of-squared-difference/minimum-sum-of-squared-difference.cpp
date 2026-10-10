class Solution {
public:
long long minSumSquareDiff(vector<int>& nums1,
                           vector<int>& nums2,
                           int k1, int k2)
{
    long long k = 1LL * k1 + k2;
    int n = nums1.size();

    vector<long long> freq(100001, 0);
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        long long d = abs(nums1[i] - nums2[i]);
        freq[d]++;
        sum += d;
    }

    if (sum <= k)
        return 0;

    for (int d = 100000; d > 0; d--)
    {
        if (freq[d] == 0)
            continue;

        long long cnt = freq[d];
        long long cost = cnt * (d - (d - 1));

        if (k >= cost)
        {
            freq[d - 1] += cnt;
            k -= cost;
            freq[d] = 0;
        }
        else
        {
            long long reduceEach = k / cnt;
            long long rem = k % cnt;

            freq[d] -= cnt;
            freq[d - reduceEach] += cnt - rem;

            if (rem > 0)
                freq[d - reduceEach - 1] += rem;

            k = 0;
            break;
        }
    }

    long long ans = 0;

    for (int d = 0; d <= 100000; d++)
        ans += 1LL * d * d * freq[d];

    return ans;
}
};