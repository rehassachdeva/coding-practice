class Solution {
public:

    double recur(int N, int K, int r, int c, vector<vector<vector<double>>>& dp)
    {
        if (r<0 or c<0 or r>=N or c>=N)
            return 0;
        
        if (K==0)
            return 1;
        
        if (dp[r][c][K] != -1.0)
            return dp[r][c][K];
        
        double ret=0;

        static const vector<pair<int, int>> dirs = {{2,1}, {2,-1}, {-2,1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
        
        for (const auto& [dx, dy] : dirs)
        {
            ret += recur(N, K-1, r+dx, c+dy, dp);
        }
        
        return dp[r][c][K]=ret/8;        
    }
    
    double knightProbability(int N, int K, int r, int c) {
        
        vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K+1,-1.0)));
        
        return recur(N, K, r, c, dp);
    }
};