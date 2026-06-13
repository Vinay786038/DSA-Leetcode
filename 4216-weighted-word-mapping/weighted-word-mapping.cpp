class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights)
    {
        string ans="";
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            int sum=0;
            for(int j=0;j<s.size();j++)
            {
                int index=(int)s[j]-97;
                sum+=weights[index];
            }
            int rem=sum%26;
            int x=122-rem;
            ans+=(char)x;
        }
        return ans;
     
    }
};