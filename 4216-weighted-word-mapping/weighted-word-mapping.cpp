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
                sum+=weights[(int)s[j]-97];
            }
            ans+=(char)(122-sum%26);
        }
        return ans;
     
    }
};