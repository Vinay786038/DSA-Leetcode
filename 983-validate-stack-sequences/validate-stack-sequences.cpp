class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> s;
        int n = pushed.size();
        int i = 0, j = 0;

        while(i < n)
        {
            s.push(pushed[i++]);

            while(!s.empty() && j < n && s.top() == popped[j])
            {
                s.pop();
                j++;
            }
        }

        return s.empty();
    }
};