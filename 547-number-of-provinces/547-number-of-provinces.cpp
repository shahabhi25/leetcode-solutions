class Solution {
public:
    void dfs(int x, vector<int> &used, vector<vector<int>> &adj)
    {
        used[x]=1;
        for(int c:adj[x])
        {
            if(!used[c])
            {
                dfs(c, used, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count=0;
        vector<int> used(n, 0);
        for(int i=0; i<n; i++)
        {
            if(!used[i])
            {
                dfs(i, used, adj);
                count++;
            }
        }
        return count;
    }
};

// [[1,0,0,1]
// ,[0,1,1,0]
// ,[0,1,1,1]
// ,[1,0,1,1]]