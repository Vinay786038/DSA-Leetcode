class Solution {
public:
    int minimumChairs(string s)
    {
        int ans=0;
        int k=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='E')
            {
                k++;
                ans=max(ans,k);
            }
            else
            k--;

        }
        return ans;
        
    }
};