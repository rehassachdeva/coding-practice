class Solution {
public:
    int rob1(vector<int>& nums, int l, int h)
    {
        if (l>h)
            return 0;
        int n=h-l+1;
        if(n==0) return 0;
        if(n==1) return nums[l];
        if(n==2) return max(nums[l],nums[h]);
        int dp[n];
        dp[0]=nums[l];
        dp[1]=max(nums[l],nums[l+1]);
        for(int i=2;i<n;i++) dp[i]=max(dp[i-2]+nums[l+i],dp[i-1]);
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1)
            return nums[0];
        return max(rob1(nums, 0, n-2), rob1(nums, 1 , n-1));
    }
};