class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int pre=0;
        int mn=0;
        for(int num:nums)
        {
            pre+=num;
            mn=min(mn,pre);
        }
        return 1-mn;
    }
};