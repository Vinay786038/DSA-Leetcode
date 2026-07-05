class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        int n=arr.size();
        if(n==1||n==2)
        {
            return arr[0];
        }
        double per=(double)(n*25)/100;
        int i=0;
        int j=1;
        int count=0;
        while(i<n-1)
        {
            if(arr[i]==arr[j])
            {
                count=j-i+1;
                if(count>per)
                return arr[j];
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return 0;
    }
};