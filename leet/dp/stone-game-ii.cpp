// 2d dp with map of maps
class Solution {
public:
    int dp(int i, int m, unordered_map<int, unordered_map<int, int>>& memo, vector<int>& piles)
    {
        if (i+2*m>=piles.size())
            return piles[i];
        if (memo.find(i)==memo.end() or memo[i].find(m)==memo[i].end())
        {
            int ret=INT_MAX;
            for (int x=1; x<=2*m; x++)
            {
                ret = min(ret, dp(i+x, max(x,m), memo, piles));
            }
            memo[i][m] = piles[i]-ret;
        }
        return memo[i][m];        
    }
    int stoneGameII(vector<int>& piles) {
        unordered_map<int, unordered_map<int, int>> memo;
        for (int i=piles.size()-2; i>=0; i--)
            piles[i]+=piles[i+1];
        return dp(0,1,memo,piles);
    }
};