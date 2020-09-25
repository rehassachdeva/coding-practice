// general k sum solution
class Solution {
public:
    
    vector<vector<int>> twosum(vector<int>& nums, int idx, int target)
    {
        unordered_map<int, bool> m;
        set<vector<int>> ret;
        for (int i=idx; i<nums.size(); i++)
        {
            if (m[target-nums[i]])
                ret.insert({target-nums[i], nums[i]});
            m[nums[i]]=true;
        }
        return vector<vector<int>>(ret.begin(), ret.end());
    }
    
    vector<vector<int>> ksum(vector<int>& nums, int idx, int k, int target)
    {
        if (idx>=nums.size() or nums.back()*k<target or nums[idx]*k>target)
            return {};
        if (k==2)
            return twosum(nums, idx, target);
        vector<vector<int>> ret;
        for (int i=idx; i<nums.size(); i++)
        {
            if (i>idx and nums[i]==nums[i-1])
                continue;
            for (auto& tmp : ksum(nums, i+1, k-1, target-nums[i]))
            {
                tmp.insert(tmp.begin(), nums[i]);
                ret.emplace_back(move(tmp));
            }
        }
        return ret;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return ksum(nums, 0, 4, target);
    }
};