class Solution {
public:
    int arrayNesting(vector<int>& nums)
    {
        int n=nums.size();
        vector<bool>visi(n,false);
        int ans=0;
        int i=0;
        int maxi=0;
        while(i<n)
        {
            int k=i;
            if(visi[i])
            {
                i++;
                continue;
            }
            
            ans=0;
            while(!visi[k])
            {
                visi[k]=true;
                k=nums[k];
                ans++;
            }
            maxi=max(maxi,ans);
            i++;
           
        }
       
        return maxi;
    }
};