class Solution {
public:
    int getlivecnt(vector<vector<int>>& grid, int i, int j)
    {
        static const vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1, 1}, {1,-1}, {1,0}, {-1,0}, {-1,1}, {-1,-1}};
        int cnt=0;
        for (auto& d : dirs)
        {
            int x=i+d.first, y=j+d.second;
            if (x<0 or y<0 or x>=grid.size() or y>=grid[0].size())
                continue;
            if (grid[x][y]==1 or grid[x][y]==-1)
                cnt++;
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                int lnei = getlivecnt(grid, i, j);
                if (lnei<2 or lnei>3)
                    grid[i][j]*=-1;
                if (lnei==3 and grid[i][j]==0)
                    grid[i][j]=2;
            }
        }
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j]==-1)
                    grid[i][j]=0;
                if (grid[i][j]==2)
                    grid[i][j]=1;
            }
        }
    }
};