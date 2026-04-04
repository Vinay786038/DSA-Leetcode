class Solution {
public:
    bool DFS(vector<int>&arr,int i,vector<bool>&visited)
    {
        int n=arr.size();
        if(i<0||i>=n||visited[i]==true)
        return false;
        if(arr[i]==0)
        return true;
        visited[i]=true;
        return DFS(arr,i+arr[i],visited)||DFS(arr,i-arr[i],visited);
    }
    bool canReach(vector<int>& arr, int start)
    {
        vector<bool>visited(arr.size(),false);
        return DFS(arr,start,visited);
    }
};