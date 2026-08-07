class Solution {
    public String smallestNumber(String num, long t) {
        long remfactor=t;
        for(int i=2;i<=9;i++)
        {
            while(remfactor%i==0)
            {
                remfactor/=i;
            }
        }
        if(remfactor>1)
        {
            return "-1";
        }
        int len=num.length();
        long[] rfactor=new long[len+1];
        rfactor[0]=t;
        int fZeroInd=len-1;
        char[] digits=num.toCharArray();
        for(int i=0;i<len;i++)
        {
            if(digits[i]=='0')
            {
                fZeroInd=i;
                break;
            }
            rfactor[i+1]=rfactor[i]/gcd(rfactor[i],digits[i]-'0');
        }
        if(rfactor[len]==1)
        {
            return num;
        }
        for(int i=fZeroInd;i>=0;i--)
        {
            while(++digits[i]<='9')
            {
                long curneed=rfactor[i]/gcd(rfactor[i],digits[i]-'0');
                int condidigit=9;
                for(int j=len-1;j>i;j--)
                {
                    while(curneed%condidigit!=0)
                    {
                        condidigit--;
                    }
                    curneed/=condidigit;
                    digits[j]=(char)('0'+condidigit);
                }
                if(curneed==1)
                {
                    return new String(digits);
                }
            }
        }
        StringBuilder ans=new StringBuilder();
        long rem=t;
        for(int digit=9;digit>=2;digit--)
        {
            while(rem%digit==0)
            {
                ans.append((char)('0'+digit));
                rem/=digit;
            }
        }
        int extraone=Math.max(len+1-ans.length(),0);
        while(extraone-->0)
        {
            ans.append('1');
        }
        return ans.reverse().toString();
    }
    private long gcd(long first,long second)
    {
        while(second!=0)
        {
            long temp=second;
            second=first%second;
            first=temp;
        }
        return first;
    }
}