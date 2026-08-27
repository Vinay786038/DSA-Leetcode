class Solution {
public:
    double trimMean(vector<int>& arr)
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int x=n/20;
        int i=x;
        int j=n-x;
        int sum=0;
        for(int k=i;k<j;k++)
        {
            sum+=arr[k];
        }
        return (double)sum/(j-i);

        
        
    }
};