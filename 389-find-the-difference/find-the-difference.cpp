class Solution {
public:
    char findTheDifference(string s, string t)
    {
        char x;
        int n=0;
        if(s.size()<t.size())
        n=s.size();
        else
        n=t.size();
        if(s.size()<t.size())
        {
            for(int i=0;i<n;i++)
            {
                int p=t.find(s[i]);
                t.erase(p,1);
            }

        }
        else
        {
            for(int i=0;i<n;i++)
            {
                int p=s.find(t[i]);
                s.erase(p,1);

            }
        }
        if(s.size()==1)
        x=s[0];
        else
        x=t[0];
        return x;
        
        
    }
};