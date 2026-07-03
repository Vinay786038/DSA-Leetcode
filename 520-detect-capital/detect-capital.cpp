class Solution {
public:
    bool detectCapitalUse(string word)
    {
        int n=word.size();
        if(n==1)
        return true;
        int case1=0;
        if(64<(int)word[0]&&(int)word[0]<91)
        {
            if(64<(int)word[1]&&(int)word[1]<91)
            {
                case1=1;
            }
            else
            {
                case1=3;
            }
        }
        if(case1==0)
        {
            for(int i=0;i<n;i++)
            {
                if(64<(int)word[i]&&(int)word[i]<91)
                return false;
            }
        }
        if(case1==1)
        {
            for(int i=2;i<n;i++)
            {
                if(96<(int)word[i]&&(int)word[i]<123)
                return false;
            }
        }
        if(case1==3)
        {
            for(int i=1;i<n;i++)
            {
                if(64<(int)word[i]&&(int)word[i]<91)
                return false;
            }
        }
        return true;

        
    }
};