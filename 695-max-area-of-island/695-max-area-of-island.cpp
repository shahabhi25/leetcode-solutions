class Solution {
public:
    bool isvalid(int x, int y, int n, int m)
    {
        return x>=0 && x<n && y>=0 && y<m;
    }
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &used, int &area)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        used[x][y]=1;
        area++;
        vector<int> d={1, 0, -1, 0, 1};
        for(int i=0; i<4; i++)
        {
            int dx=d[i]+x;
            int dy=d[i+1]+y;
            
            if(isvalid(dx, dy, n, m) && !used[dx][dy] && grid[dx][dy]==1)
            {
                dfs(dx, dy, grid, used, area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> used(n, vector<int>(m, 0));
        
        int max_area=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<m; j++)
            {
                if(!used[i][j] && grid[i][j]==1)
                {
                    int area=0;
                    dfs(i, j, grid, used, area);
                    max_area=max(max_area, area);
                }
            }
        }
        return max_area;
    }
};