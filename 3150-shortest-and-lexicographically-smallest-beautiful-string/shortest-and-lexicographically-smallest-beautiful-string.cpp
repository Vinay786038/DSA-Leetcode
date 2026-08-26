class Solution {
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int n=s.size();
        string ans="";
        int i=0;
        int j=i;
        int count=0;
        while(j<n&&i<n)
        {
            if(s[j]=='1')
            {
                count++;
            }
            while(count>k)
            {
                if(s[i]=='1')
                {
                    count--;
                }
                i++;
            }
            if(count==k)
            {
                while(i<=j&&s[i]=='0')
                {
                    i++;
                }
                string curr=s.substr(i,j-i+1);
                if(ans=="")
                {
                    ans=s.substr(i,j-i+1);
                }
                else if(ans.size()>curr.size())
                {
                    ans=curr;
                }
                else if(curr.size()==ans.size()&&curr<ans)
                {
                    ans=curr;
                }
            }
            j++;
        }
        return ans;
    }
};