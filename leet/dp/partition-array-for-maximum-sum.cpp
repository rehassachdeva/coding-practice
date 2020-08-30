class Solution {
public:
    int recur(int idx, vector<int>& A, vector<int>& dp, int K)
    {
        if (idx>=A.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int ret=0, mx=0;
        for (int i=0; i<K and i+idx<A.size(); i++)
        {
            mx = max(A[idx+i], mx);
            ret = max(mx*(i+1) + recur(idx+i+1, A, dp, K), ret);
        }
        return dp[idx]=ret;
    }
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size(),-1);
        return recur(0, A, dp, K);
    }
};