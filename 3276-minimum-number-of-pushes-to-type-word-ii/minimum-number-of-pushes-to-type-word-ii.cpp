class Solution {
public:
    int minimumPushes(string word) 
    {
        vector<int>freq(26,0);
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i<8)
            {
                ans+=freq[i];
            }
            else if(i<16)
            {
                ans+=freq[i]*2;
            }
            else if(i<24)
            {
                ans+=freq[i]*3;
            }
            else if(i<26)
            {
                ans+=freq[i]*4;
            }
        }
        return ans;
        
    }
};