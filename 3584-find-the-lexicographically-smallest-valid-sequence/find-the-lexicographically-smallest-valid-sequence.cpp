class Solution {
public:
    vector<int> validSequence(string word1, string word2)
    {
        int n=word1.size();
        int m=word2.size();
        vector<int>suff(m+1,n);
        int j=m-1;
        for(int i=n-1;i>=0;i--)
        {
            if(j>=0&&word1[i]==word2[j])
            {
                suff[j]=i;
                j--;
            }
        }
        vector<int>ans;
        int p=0;
        bool usedMismatch=false;
        for(int i=0;i<n&&p<m;i++)
        {
            if(word1[i]==word2[p])
            {
                ans.push_back(i);
                p++;
            }
            else if(!usedMismatch)
            {
                if(p+1==m||(suff[p+1]<n&&suff[p+1]>i))
                {
                    ans.push_back(i);
                    p++;
                    usedMismatch=true;
                }
            }
        }
        if(p==m)
        return ans;
        return {}; 
    }
};