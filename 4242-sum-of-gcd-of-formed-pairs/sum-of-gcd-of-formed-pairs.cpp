class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>pregcd(n);
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            maxx=max(nums[i],maxx);
            pregcd[i]=gcd(nums[i],maxx);
        }
        sort(pregcd.begin(),pregcd.end());
        int left=0;
        int right=n-1;
        long long ans=0;
        while(left<right)
        {
            ans+=gcd(pregcd[left],pregcd[right]);
            left++;
            right--;
        }
        return ans;


        
    }
};