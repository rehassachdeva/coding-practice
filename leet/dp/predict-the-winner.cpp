
// either end max score problem

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if (n%2==0)
            return true;
        vector<vector<int>> dp(21, vector<int>(21, 0));
        for (int i=n-1; i>=0; i--)
        {
            dp[i][i]=nums[i];
            for (int j=i+1; j<n; j++)
            {
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
};