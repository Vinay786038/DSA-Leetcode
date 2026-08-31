class Solution {
public:

    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        int ans = 0;

        for(int i = 0; i <= n; i++)
        {
            int curr = (i == n ? 0 : heights[i]);

            while(!st.empty() && heights[st.top()] > curr)
            {
                int h = heights[st.top()];
                st.pop();

                int width;

                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                ans = max(ans, h * width);
            }

            st.push(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix)
    {
        if(matrix.empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            // Current row ko histogram me convert karo
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            // Current histogram ka maximum rectangle
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};