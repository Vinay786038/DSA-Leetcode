class Solution {
public:
    string digitSum(string s, int k)
    {
        int n=s.size();
        if(n<=k)
        {
            return s;
        }
        while(n>k)
        {
            string str="";
            for(int i=0;i<n;i+=k)
            {
                int sum=0;
                for(int j=0;j<k&&(i+j)<n;j++)
                {
                    sum+=s[j+i]-'0';
                }
                str+=to_string(sum);
            }
            s=str;
            n=s.size();
        }
        return s;
        
        
    }
};