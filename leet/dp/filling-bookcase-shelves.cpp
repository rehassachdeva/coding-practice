class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n=books.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for (int i=1; i<=n; i++)
        {
            int maxw = shelf_width;
            int maxh = 0;
            for (int j=i-1; j>=0; j--)
            {
                if (maxw - books[j][0] < 0)
                    break;
                maxw -= books[j][0];
                maxh = max(maxh, books[j][1]);
                dp[i] = min(dp[i], dp[j]+maxh);
            }
        }
        return dp[n];
    }
};