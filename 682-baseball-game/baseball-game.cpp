class Solution {
public:
    int calPoints(vector<string>& operations)
    {
        int n=operations.size();
        stack<int>st;
         for(string op : operations)
        {
            if(op == "C")
            {
             st.pop();
            }
            else if(op == "D")
            {
                st.push(2 * st.top());
            }
            else if(op == "+")
            {
                int x = st.top();
                st.pop();

                int y = st.top();

                st.push(x);
                st.push(x + y);
            }
            else
            {
                st.push(stoi(op));
            }
        }

       int ans = 0;

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
