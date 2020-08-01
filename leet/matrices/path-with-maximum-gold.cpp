// backtracking
// dfs on matrix
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        int ret=0;
        grid[r][c]*=-1;
        
        static const vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        for (const auto& [dx, dy] : dirs)
        {
            int nx=r+dx, ny=c+dy;
            if (nx<0 or ny<0 or nx>=grid.size() or ny>=grid[0].size() or grid[nx][ny]<=0)
                continue;
            ret = max(ret, dfs(grid, nx, ny));
        }
        
        grid[r][c]*=-1;
        return ret+grid[r][c];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j])
                    ans=max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};