class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr)
    {
        vector<int>ans;
        int right=arr.size()-1;
        while(right>0)
        {
            int maxIdx=0;
            int left=0;
            int r=right;
            while(left<=r)
            {
                if(arr[left]>arr[maxIdx])
                {
                    maxIdx=left;
                }
                if(arr[r]>arr[maxIdx])
                {
                    maxIdx=r;
                }
                left++;
                r--;
            }
            if(maxIdx==right)
            {
                right--;
                continue;
            }
            if(maxIdx!=0)
            {
                reverse(arr.begin(),arr.begin()+maxIdx+1);
                ans.push_back(maxIdx+1);
            }
            reverse(arr.begin(),arr.begin()+right+1);
            ans.push_back(right+1);
            right--;
        }
        return ans;
        
    }
};