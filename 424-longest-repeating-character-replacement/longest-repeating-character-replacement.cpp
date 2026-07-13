class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int n=s.size();
        vector<int>frq(26,0);
        int i=0;
        int maxfrq=0;
        int ans=0;
        for(int j=0;j<n;j++)
        {
            frq[s[j]-'A']++;
            maxfrq=max(maxfrq,frq[s[j]-'A']);
            while((j-i+1)-maxfrq>k)
            {
                frq[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;

    }
};