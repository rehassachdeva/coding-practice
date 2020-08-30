class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n<=1)
            return n;
        vector<int> dp(n,0), cnt(n,1);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (nums[i]>nums[j])
                {
                    if (dp[j]+1==dp[i])
                        cnt[i]+=cnt[j];
                    else if (dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        cnt[i]=cnt[j];
                    }
                }
            }
        }
        int mx=*max_element(dp.begin(), dp.end());
        int ans=0;
        for (int i=0; i<n; i++)
        {
            if (dp[i]==mx)
                ans+=cnt[i];
        }
        return ans;
    }
};