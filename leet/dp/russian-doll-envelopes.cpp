class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if (n<=1)
            return n;
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(n,1);
        int ans=1;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (envelopes[i][0]>envelopes[j][0] and envelopes[i][1]>envelopes[j][1])
                    dp[i]=max(dp[i], dp[j]+1);
                ans=max(ans, dp[i]);
            }
        }
        return ans;        
    }
};