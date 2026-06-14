class Solution {
public:
    bool isHappy(int n) {
        map<int,int>mp;
        int m=n;
        while(!mp[m])
        {
            int sum=0;
            mp[m]=1;
            while(m>0)
            {
                int rem=m%10;
                sum+=rem*rem;
                m/=10;
            }
            if(sum==1)
            return true;
            else
            m=sum;
        }
        return false;
        
    }
};