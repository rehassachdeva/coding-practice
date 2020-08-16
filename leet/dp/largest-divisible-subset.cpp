class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        if (nums.empty())
            return {};
        
        sort(nums.begin(), nums.end());
       
        int n=nums.size();
        
        vector<int> dp(n,1);
        vector<int> prv(n,-1);
        int mxi=0;
        
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (nums[i]%nums[j]==0)
                {
                    if (dp[i]<dp[j]+1)
                    {
                        prv[i]=j;
                        dp[i]=dp[j]+1;
                    }
                }
            }
            if (dp[mxi]<dp[i])
                mxi=i;
        }
        
        vector<int> ans;
        while (mxi!=-1)
        {
            ans.push_back(nums[mxi]);
            mxi=prv[mxi];
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};