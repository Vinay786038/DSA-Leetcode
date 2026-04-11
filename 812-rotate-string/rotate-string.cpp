class Solution {
public:
    bool rotateString(string s, string goal)
    {
        if(s.size()!=goal.size())
        return false;
        /*int n=s.size();
        (int i=0;i<n;i++)
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
        return false;*/
        s.append(s);
        if(s.find(goal) != string::npos)
        return true;
        return false;

        
    }
};