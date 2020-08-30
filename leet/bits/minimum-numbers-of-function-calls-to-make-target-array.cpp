class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0, mx=0, cnt;
        for (int i=0; i<nums.size(); i++)
        {
            cnt=0;
            while (nums[i])
            {
                ans += (nums[i]&1);
                mx = max(mx, cnt);
                cnt++;
                nums[i]>>=1;
            }
        }
        return ans + mx;
    }
};