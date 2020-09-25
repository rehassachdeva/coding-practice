class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> dp(N+W,0);
        for (int i=K; i<=N; i++) dp[i]=1;
        double cur = min(N-K+1, W);
        for (int i=K-1; i>=0; i--)
        {
            dp[i] = cur/W;
            cur += dp[i] - dp[i+W];
        }
        return dp[0];
    }
};