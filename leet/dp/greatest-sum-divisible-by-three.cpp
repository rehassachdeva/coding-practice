class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, -1e9);
        dp[0]=0;
        for (int i=0; i<nums.size(); i++)
        {
            vector<int> newdp(dp);
            if(nums[i]%3==0)
            {
                newdp[0]+=nums[i];
                newdp[1]=max(newdp[1], dp[1]+nums[i]);
                newdp[2]=max(newdp[2], dp[2]+nums[i]);
            }
            else if (nums[i]%3==1)
            {
                newdp[0]=max(newdp[0], dp[2]+nums[i]);
                newdp[1]=max(newdp[1], dp[0]+nums[i]);
                newdp[2]=max(newdp[2], dp[1]+nums[i]);
            }
            else
            {
                newdp[0]=max(newdp[0], dp[1]+nums[i]);
                newdp[1]=max(newdp[1], dp[2]+nums[i]);
                newdp[2]=max(newdp[2], dp[0]+nums[i]);                
            }
            dp=newdp;
        }
        return dp[0];
    }
};