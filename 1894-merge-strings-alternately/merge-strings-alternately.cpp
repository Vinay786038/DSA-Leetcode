class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int m=word1.size();
        int n=word2.size();
        int i=0;
        int j=0;
        string s="";
        while(i<m&&j<n)
        {
            s+=word1[i];
            i++;
            s+=word2[j];
            j++;
        }
        if(i==m)
        {
            string s1=word2.substr(j,n-j);
            s+=s1;
        }
        if(j==n)
        {
            string s1=word1.substr(i,m-i);
            s+=s1;
        }
        return s;
    }
};