class Solution {
public:
    int minChanges(string s)
    {
        int n=s.size();
        int i=0;
        int ans=0;
        int j=i;
        int ones=0;
        int zeroes=0;
        while(i<n&&j<n)
        {
            if(s[j]=='1')
            {
                ones++;
            }
            else if(s[j]=='0')
            {
                zeroes++;
            }
            if((j-i+1)%2==0)
            {
                ans+=min(ones,zeroes);
                ones=0;
                zeroes=0;
                j++;
                i=j;
            }
            else
            {
                j++;
               
            }
        }
        return ans;
    }
};