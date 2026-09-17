class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target)
    {
        int n=arr.size();
        int size1=INT_MAX;
        int size2=INT_MAX;;
        int sum=0;
        vector<int>best(n+1,INT_MAX);
        int i=0,j=0;
        while(j<n)
        {
            sum+=arr[j];
            j++;
            while(sum>target&&i<j)
            {
                sum-=arr[i];
                i++;
            }
            if(sum==target)
            {
                int len=j-i;
                if(best[i]!=INT_MAX)
                {
                    size2=min(size2,best[i]+len);
                }
                size1=min(size1,len);
            }
            best[j]=size1;
        }
        
        if(size2==INT_MAX)
        {
            return -1;
        }
        return size2;
    }
};