class Solution {
public:

    typedef pair<double, pair<int,int>> P;

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        int n = arr.size();

        priority_queue<P, vector<P>, greater<P>> pq;

        // Initial fractions
        for(int j = 1; j < n; j++)
        {
            double val = (double)arr[0] / arr[j];

            pq.push({val, {0, j}});
        }

        // Remove k-1 smallest fractions
        while(--k)
        {
            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            // Next numerator
            if(i + 1 < j)
            {
                double val = (double)arr[i + 1] / arr[j];

                pq.push({val, {i + 1, j}});
            }
        }

        auto ans = pq.top();

        int i = ans.second.first;
        int j = ans.second.second;

        return {arr[i], arr[j]};
    }
};