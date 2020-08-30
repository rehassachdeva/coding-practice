class Solution {
public:
    int recur(int i, int j, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
    {
        if (i>=grid.size())
            return 0;
        if (j<0 or k<0 or j>=grid[0].size() or k>=grid[0].size())
            return 0;
        if (dp[i][j][k]!=-1)
            return dp[i][j][k];
        int ret=0;
        if (j==k)
            ret+=grid[i][j];
        else
            ret+=grid[i][j]+grid[i][k];
        int tmp=0;
        for (int x=-1; x<=1; x++)
        {
            for (int y=-1; y<=1; y++)
            {
                tmp=max(tmp, recur(i+1, j+x, k+y, grid, dp));
            }
        }
        return dp[i][j][k]=ret+tmp;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(71, vector<vector<int>>(71, vector<int>(71,-1)));
        return recur(0, 0, grid[0].size()-1, grid, dp);
    }
};