class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            st.push(0);
            if(st.size()==n)
            break;
            st.push(arr[i]);
            if(st.size()==n)
            break;
        }
        int i=0;
        while(st.empty()!=1)
        {
            arr[i]=st.top();
            st.pop();
            i++;
        }
        reverse(arr.begin(),arr.end());
        return;
        
    }
};