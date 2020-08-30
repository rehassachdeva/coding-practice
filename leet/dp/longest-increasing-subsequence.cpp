// longest increasing subsequence lis - dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=1;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (nums[i]>nums[j])
                    dp[i]=max(dp[i], dp[j]+1);
                ans=max(ans, dp[i]);
            }
        }
        return ans;
    }
};

// binary search soln
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n=nums.size();
        int ans=1;
        set<int> s;
        for (int i=0; i<n; i++)
        {
            auto it = s.lower_bound(nums[i]);
            if (it==s.end())
                s.insert(nums[i]);
            else
            {
                s.erase(it);
                s.insert(nums[i]);
            }
        }
        return s.size();
    }
};