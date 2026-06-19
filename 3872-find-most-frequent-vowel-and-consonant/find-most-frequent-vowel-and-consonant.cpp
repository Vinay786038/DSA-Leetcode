class Solution {
public:
    int maxFreqSum(string s)
    {
        int n=s.size();
        map<char,int>vow={{'a',0},{'e',0},{'i',0},{'o',0},{'u',0}};
        map<char,int>cons;
        int vo=0;
        int con=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                vow[s[i]]++;
                vo=max(vo,vow[s[i]]);
            }
            else
            {
                cons[s[i]]++;
                con=max(con,cons[s[i]]);
            }
        }
        return vo+con;


        
    }
};