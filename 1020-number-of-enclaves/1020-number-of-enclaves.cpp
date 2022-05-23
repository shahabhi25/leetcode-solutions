class Solution {
public:
    bool isvalid(int x, int y, int n, int m)
    {
        return x>=0 && x<n && y>=0 && y<m;
    }
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &used)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        used[x][y]=1;
        grid[x][y]=0;
        vector<int> d={1, 0, -1, 0, 1};
        
        for(int i=0; i<4; i++)
        {
            int dx=x+d[i];
            int dy=y+d[i+1];
            
            if(isvalid(dx, dy, n, m) && grid[dx][dy]==1 && !used[dx][dy])
            {
                dfs(dx, dy, grid, used);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> used(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++)
        {
            if(!used[i][0] && grid[i][0]==1)
            {
                dfs(i, 0, grid, used);
            }
            if(!used[i][m-1] && grid[i][m-1]==1)
            {
                dfs(i, m-1, grid, used);
            }
        }
        
        for(int i=1; i<m-1; i++)
        {
            if(!used[0][i] && grid[0][i]==1)
            {
                dfs(0, i, grid, used);
            }
            if(!used[n-1][i] && grid[n-1][i]==1)
            {
                dfs(n-1, i, grid, used);
            }
        }
        
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                count+=grid[i][j];
            }
        }
        return count;
    }
};