class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        /*int n=nums.size();
        set<int>st;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                st.insert(nums[i]^nums[j]);
            }
        }
        set<int>st2;
        for(int i:nums)
        {
            for(int j:st)
            {
                st2.insert(i^j);
            }
        }
        return st2.size();
        /*if(n<3)
        return n;
        int ans=1;
        while(ans<=n)
        {
            ans<<=1;
        }
        return ans;*/
        const int LIMIT=2048;
        vector<bool>pairXOR(LIMIT,false);
        vector<bool>triplXOR(LIMIT,false);
        for(int i:nums)
        {
            for(int j:nums)
            {
                pairXOR[i^j]=true;
            }
        }
        for(int x=0;x<LIMIT;x++)
        {
            if(!(pairXOR[x]))
            continue;
            for(int c:nums)
            {
                triplXOR[x^c]=true;
            }
        }
        return count(triplXOR.begin(),triplXOR.end(),true);
        
    }
};