class Solution {
public:

    void solve(int index, vector<int>& candidates, int target,
               vector<int>& current, vector<vector<int>>& ans)
    {
        // Target mil gaya
        if(target == 0)
        {
            ans.push_back(current);
            return;
        }

        // Target negative ho gaya
        if(target < 0)
            return;

        // Saare elements check kar liye
        if(index == candidates.size())
            return;

        // 1. Current element choose karo
        current.push_back(candidates[index]);

        // Same element dobara choose kar sakte hain
        solve(index, candidates, target - candidates[index],
              current, ans);

        // Backtrack
        current.pop_back();

        // 2. Current element skip karo
        solve(index + 1, candidates, target,
              current, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> current;

        solve(0, candidates, target, current, ans);

        return ans;
    }
};