class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int> scores(1e5+1, 0);
        for (auto& num : nums)
            scores[num]+=num;
        int prv=-1, inc=0, wdout=0;
        for (int i=0; i<scores.size(); i++)
        {
            if (!scores[i])
                continue;
            
            int tmp=max(inc, wdout);
            if (prv==i-1)
            {
                inc = wdout+scores[i];
                wdout = tmp;
            }
            else
            {
                inc = tmp+scores[i];
                wdout = tmp;
            }
            prv=i;
        }
        return max(wdout, inc);
    }
};