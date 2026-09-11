class Solution {
public:
    int totalNumbers(vector<int>& digits)
    {
        int n=digits.size();
        int ans=0;
        int even=0;
        int zero;
        vector<int>freq(10,0);
        for(int i=0;i<n;i++)
        {
            freq[digits[i]]++;
        }
        for(int i=100;i<999;i+=2)
        {
            vector<int>freq2(10,0);
            int m=i;
            while(m>0)
            {
                int rem=m%10;
                freq2[rem]++;
                m/=10;
            }
            int k=0;
            for(int j=0;j<10;j++)
            {
                if(freq[j]>=freq2[j]&&freq2[j]!=0)
                {
                    k=k+freq2[j];
                }
            }
            if(k==3)
            {
                ans++;
            }
        }
        return ans;




        
    }
};