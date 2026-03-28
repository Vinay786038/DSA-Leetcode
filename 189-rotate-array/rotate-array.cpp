class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int n=nums.size();
        int last;
        k=k%n;
        reverse(nums.begin(),nums.end());//full reverse
        reverse(nums.begin(),nums.begin()+k);//starting k elements reverse
        reverse(nums.begin()+k,nums.end());//ending n-k elements reverse
        return;
        
    }
};