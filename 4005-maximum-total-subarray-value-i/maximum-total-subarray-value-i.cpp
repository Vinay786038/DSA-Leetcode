class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k){
        vector<int>vec=nums;
        int mn=*min_element(vec.begin(),vec.end());
        int mx=*max_element(vec.begin(),vec.end());
        return 1LL*k*(mx-mn);
        
    }
};