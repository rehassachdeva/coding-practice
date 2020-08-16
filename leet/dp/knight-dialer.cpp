class Solution {
public:
    int knightDialer(int N) {
        if (N==1)
            return 10;
        
        vector<vector<int>> preds = {{4,6}, {6,8}, {7,9}, {4,8}, {3,9,0}, {}, {1,7,0}, {2,6}, {1,3}, {2,4}};
        
        vector<vector<int>> dp(N+1, vector<int>(10,0));
        
        for (int i=0; i<10; i++)
            dp[1][i]=1;
        
        const int mod = 1e9+7;
        
        for (int i=2; i<=N; i++)
        {
            for (int j=0; j<10; j++)
            {
                dp[i][j]=0;
                for (const auto& p : preds[j])
                    dp[i][j]=(dp[i][j]+dp[i-1][p])%mod;
            }

        }
        
        int ret=0;
        for (int i=0; i<10; i++)
            ret = (ret+dp[N][i])%mod;
        return ret;
    }
};