class NumArray {
public:
    vector<int>pref;
    NumArray(vector<int>& nums)
    {
        int n=nums.size();
        pref.resize(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            pref[i]=sum;
        }
    }
    int sumRange(int left, int right)
    {
        if(left>0)
        {
            return pref[right]-pref[left-1];
        }
        return pref[right];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */