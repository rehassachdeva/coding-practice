// flood fill
// dfs on matrix
// dfs on grid
class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid)
    {
        if (r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or grid[r][c]==0)
            return false;
        grid[r][c]=0;
        static vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ret=1;       
        for (const auto& [dx,dy] : directions)
        {
            ret+=dfs(r+dx,c+dy,grid);
        }
        return ret;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=0;
        
        for(int i=0; i<m; i++)
        {
            dfs(0,i,grid);
            dfs(n-1,i,grid);
        }
        for(int i=0; i<n; i++)
        {
            dfs(i,0,grid);
            dfs(i,m-1,grid);
        }
        
        for (int i=1; i<n-1; i++)
        {
            for (int j=1; j<m-1; j++)
            {
                if (grid[i][j])
                {
                    ans+=dfs(i,j,grid);
                }
            }
        }
        return ans;        
    }
};