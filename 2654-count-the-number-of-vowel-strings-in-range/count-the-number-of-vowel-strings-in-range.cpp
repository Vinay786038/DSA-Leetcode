class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right)
    {
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            string s=words[i];
            int n=s.size()-1;
            if((s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')&&(
            s[n]=='a'||s[n]=='e'||s[n]=='i'||s[n]=='o'||s[n]=='u'))
            {
                ans++;
            }
        }
        return ans;
    }
};