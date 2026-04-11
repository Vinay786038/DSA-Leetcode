class Solution {
public:
    bool rotateString(string s, string goal)
    {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s.compare(goal)==0)
            return true;
            char s1=s[0];
            for(int j=0;j<n-1;j++)
            {
                s[j]=s[j+1];
            }
            s[n-1]=s1;
        }
        return false;

        
    }
};