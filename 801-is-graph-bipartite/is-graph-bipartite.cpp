class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int size=0;
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                if(graph[i][j]>size)
                size=graph[i][j];
            }
        }
        size++;
        vector<int>colour(size,-1);
        for(int k=0;k<size;k++)
        {
            if(colour[k]!=-1)
            continue;
            queue<int>q;
            q.push(k);
            while(q.empty()!=1)
            {
                int i=q.front();
                q.pop();
                if(colour[i]==-1)
                colour[i]=0;
                for(int j=0;j<graph[i].size();j++)
                {
                    if(colour[graph[i][j]]==-1&&colour[i]==0)
                    {
                        colour[graph[i][j]]=1;
                        q.push(graph[i][j]);
                    }
                    else if(colour[i]==1&&colour[graph[i][j]]==-1)
                    {
                        colour[graph[i][j]]=0;
                        q.push(graph[i][j]);
                    }
                    else
                    {
                        if(colour[i]==colour[graph[i][j]])
                        return false;
                    }
                }
            }
        }
        return true;
    }
};