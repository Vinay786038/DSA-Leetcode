class Solution {
public:
    /*bool DFS(vector<int>&arr,int i,vector<bool>&visited)
    {
        //DFS traversal
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
    }*/
    bool canReach(vector<int>& arr,int start)
    {
        //BFS traversal
        int n=arr.size();
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(start);
        visited[start]=true;
        while(q.empty()!=true)
        {
            int i=q.front();
            q.pop();
            if(arr[i]==0)
            return true;
            int forw=i+arr[i];
            int back=i-arr[i];
            if(forw<n&&visited[forw]==false)
            {
                q.push(forw);
                visited[forw]=true;
            }
            if(back>-1&&visited[back]==false)
            {
                q.push(back);
                visited[back]=true;
            }
        }
        return false;



    }
};