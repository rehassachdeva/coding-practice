class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.back().size();
        int ans=INT_MAX;
        vector<int> dp(n,1e9);
        dp[0]=triangle[0][0];
        for (int i=2; i<=n; i++)
        {
            vector<int> newdp(n,1e9);
            newdp[0]=dp[0]+triangle[i-1][0];
            newdp[i-1]=dp[i-2]+triangle[i-1].back();
            for (int j=1; j<i-1; j++)
            {
                newdp[j]=min(triangle[i-1][j]+dp[j-1], triangle[i-1][j]+dp[j]);
            }
            dp=move(newdp);
        }
        return *min_element(dp.begin(),dp.end());
    }
};