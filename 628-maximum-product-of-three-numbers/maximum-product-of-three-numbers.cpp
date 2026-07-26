class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
        vector<int>vec=nums;
        sort(vec.begin(),vec.end());
        int n=nums.size();
        return max(vec[n-1]*vec[n-2]*vec[n-3],vec[0]*vec[1]*vec[n-1]);



        
    }
};