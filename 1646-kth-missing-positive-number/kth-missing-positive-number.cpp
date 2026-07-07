class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        int i=0;
        int n=1;
        while(k>0)
        {
            if(i>arr.size()-1)
            {
                k--;
                n++;
            }
            else if(n<arr[i])
            {
                n++;
                k--;
            }
            else
            {
                i++;
                n++;
            }
        }
        return n-1;
    }
};