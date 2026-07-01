class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations)
    {
        int x=0;
        int n=operations.size();
        for(int i=0;i<n;i++)
        {
            string s=operations[i];
            if(s=="++X"||s=="X++")
            {
                x++;
            }
            if(s=="--X"||s=="X--")
            {
                x--;
            }
        }
        return x;
        
    }
};