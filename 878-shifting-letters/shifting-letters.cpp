class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts)
    {
        vector<char>vec;
        for(char c:s)
        {
            vec.push_back(c);
        }
        int n=shifts.size();
        vector<int>suff(n);
        int sum=0;
        for(int i=n-1;i>=0;i--)
        {
            sum+=shifts[i]%26;
            suff[i]=sum;

        }
        for(int i=0;i<shifts.size();i++)
        {
            int x=suff[i]%26;
            if(x==0)
            continue;
            int y=int(vec[i])+x;
            if(y>122)
            {
                y=96+y-122;
            }
            vec[i]=char(y);
        }
        string str="";
        for(int i=0;i<vec.size();i++)
        {
            str+=vec[i];
        }
        return str;
        
    }
};