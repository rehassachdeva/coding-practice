class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        
        int n=A.size();
        
        vector<vector<int>> dp(n, vector<int>(2,1));
        dp[0][0]=1;
        dp[0][1]=1;
        
        int ans=1;
        for (int i=1; i<n; i++)
        {
            if (A[i]>A[i-1])
            {
                dp[i][0]=1+dp[i-1][1];
                dp[i][1]=1;
                ans=max(ans, dp[i][0]);
            }
            else if (A[i]<A[i-1])
            {
                dp[i][1]=1+dp[i-1][0];
                dp[i][0]=1;
                ans=max(ans, dp[i][1]);
            }
            else
            {
                dp[i][0]=dp[i][1]=1;
            }
        }
        
        return ans;
    }
};