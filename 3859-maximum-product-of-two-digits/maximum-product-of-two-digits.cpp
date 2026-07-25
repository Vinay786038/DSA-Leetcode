class Solution {
public:
    int maxProduct(int n) {
        int m=n;
        int x=0;
        int y=0;
        vector<int>arr;
        while(m>0)
        {
            int rem=m%10;
            arr.push_back(rem);
            m/=10;
        }
        sort(arr.begin(),arr.end());
        int size=arr.size();
        return arr[size-1]*arr[size-2];
        
    }
};