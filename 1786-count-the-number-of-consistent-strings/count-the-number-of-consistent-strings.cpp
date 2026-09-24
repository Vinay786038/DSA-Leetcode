class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        vector<bool>vec1(26,false);
        int n=allowed.size();
        for(int i=0;i<n;i++)
        {
            vec1[allowed[i]-'a']=true;
        }
        n=words.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            bool x=true;
            for(char c:words[i])
            {
                if(vec1[c-'a']==false)
                {
                    x=false;
                    break;
                }
            }
            if(x)
            {
                ans++;
            }
        }
        return ans;
        
    }
};