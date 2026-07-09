class Solution {
public:
    bool digitCount(string num)
    {
        int n=num.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(num[i]-'0')!=mp.end())
            {
                mp[num[i]-'0']++;
            }
            else
            {
                mp[num[i]-'0']=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(mp[i]!=num[i]-'0')
            return false;
        }
        return true;

        
    }
};