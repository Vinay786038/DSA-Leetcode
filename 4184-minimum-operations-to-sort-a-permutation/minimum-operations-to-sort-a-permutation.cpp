
class Solution {
public:
    bool isSorted(vector<int>& nums, int i = 0)
    {
        int n = nums.size();

        if (i == n - 1)
            return true;

        if (nums[i] > nums[i + 1])
            return false;

        return isSorted(nums, i + 1);
    }

    bool check(vector<int>& nums, int zero, int step, int i = 1)
    {
        int n = nums.size();

        if (i == n)
            return true;

        int prev = (zero + (i - 1) * step + n) % n;
        int curr = (zero + i * step + n) % n;

        if (nums[prev] > nums[curr])
            return false;

        return check(nums, zero, step, i + 1);
    }

    int minOperations(vector<int>& nums)
    {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();
        int ans = INT_MAX;

        if (check(nums, zero, 1))
        {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        if (check(nums, zero, -1))
        {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
