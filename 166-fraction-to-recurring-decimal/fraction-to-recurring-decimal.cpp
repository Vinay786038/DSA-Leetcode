class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string s="";
        if(numerator==0)
        return "0";
        if((numerator<0)^(denominator<0))
        s+="-";
        long long num=llabs(numerator);
        long long den=llabs(denominator);
        s+=to_string(num/den);
        long long rem=num%den;
        if(rem==0)
        {
            return s;
        }
        s+=".";
        map<int,int>mp;
        while(rem!=0)
        {
            if(mp.find(rem)!=mp.end())
            {
                s.insert(mp[rem],"(");
                s+=')';
                break;
            }
            mp[rem]=s.size();
            rem*=10;
            s+=to_string(rem/den);
            rem%=den;
        }
        return s;

        
    }
};