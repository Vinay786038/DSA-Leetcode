class Solution {
public:
    int kthFactor(int n, int k)
    {
        vector<int>vec;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
            vec.push_back(i);
        }
        if(vec.size()>=k)
        return vec[k-1];
        return -1;

        
    }
};