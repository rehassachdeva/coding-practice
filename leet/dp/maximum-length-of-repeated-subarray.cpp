// longest common subarray
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n=A.size(), m=B.size();
        int ans=0;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for (int i=1; i<=m; i++)
        {
            for (int j=1; j<=n; j++)
            {
                dp[i][j] = (A[i-1] == B[j-1]) ? dp[i-1][j-1]+1 : 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};