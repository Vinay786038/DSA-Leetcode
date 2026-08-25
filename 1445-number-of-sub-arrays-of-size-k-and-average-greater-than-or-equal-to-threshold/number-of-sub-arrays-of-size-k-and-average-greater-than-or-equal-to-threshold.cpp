class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold)
    {
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=arr[i];
        }
        int i=0;
        int j=k;
        int ans=0;
        if((sum/k)>=threshold)
        {
            ans++;
        }
        while(j<arr.size())
        {
            sum=sum-arr[i];
            i++;
            sum+=arr[j];
            j++;
            if((sum/k)>=threshold)
            {
                ans++;
            }
        }
        return ans;
    }
};