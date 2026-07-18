class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries)
    {
        int n=queries.size();
        vector<int>ans(n);
        int m=words.size();
        vector<int>pref(m,0);
        int count=0;
        for(int i=0;i<m;i++)
        {
            string s=words[i];
            int m=s.size()-1;
            if((s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')&&(s[m]=='a'||s[m]=='e'||s[m]=='i'||s[m]=='o'||s[m]=='u'))
            {
                count++;
            }
            pref[i]=count;
        }
        for(int i=0;i<n;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            if(start==0)
            {
                ans[i]=pref[end];
            }
            else
            {
                ans[i]=pref[end]-pref[start-1];
            }
        }
        /*
        for(int i=0;i<n;i++)
        {
            int start=queries[i][0];
            int count=0;
            int last=queries[i][1];
            for(int j=start;j<=last;j++)
            {
                string s=words[j];
                int m=s.size()-1;
                if((s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')&&(s[m]=='a'||s[m]=='e'||s[m]=='i'||s[m]=='o'||s[m]=='u'))
                {
                    count++;
                }
            }
            ans[i]=count;
        }*/
        return ans;
        
    }
};