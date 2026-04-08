class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        // Step 1: prefix sum
        for(int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + nums[i];
        deque<int> dq;
        int ans = INT_MAX;
        for(int i = 0; i <= n; i++)
        {
            // Step 2: check valid subarray
            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k)
            {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            // Step 3: maintain increasing order
            while(!dq.empty() && prefix[i] <= prefix[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};