class Solution {
public:
    string getHint(string secret, string guess)
    {
        int n=secret.size();
        vector<int>sc(10,0);
        vector<int>gs(10,0);
        int bull=0;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
                bull++;
            }
            else
            {
                int x=secret[i]-'0';
                int y=guess[i]-'0';
                sc[x]+=1;
                gs[y]+=1;
            }
        }
        int sum=0;
        for(int i=0;i<10;i++)
        {
            sum+=min(sc[i],gs[i]);
        }
        string res="";
        res+=to_string(bull);
        res+='A';
        res+=to_string(sum);
        res+='B';
        return res;
        
    }
};