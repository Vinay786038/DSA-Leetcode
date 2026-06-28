class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
    {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int x=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
            {
                swap(arr[i],arr[0]);
                break;
            }
            x++;
        }
        int max=1;
        if(x==n)
        arr[0]=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>max)
            max=arr[i];
            if(abs(arr[i]-arr[i-1])<=1)
            continue;
            else
            {
                arr[i]=arr[i-1]+1;
                max=arr[i];
            }
        }
        return max;
    }
};