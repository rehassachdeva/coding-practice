// generate all permutations
class Solution {
public:
    vector<vector<int>> recur(vector<int>& nums, int l, int h)
    {
        if (l>h)
            return {};
        if (l==h)
            return {{nums[l]}};
        if (l+1==h)
            return {{nums[l], nums[h]}, {nums[h], nums[l]}};

        vector<vector<int>> ret;
        
        for (int i=l; i<=h; i++)
        {
            swap(nums[l], nums[i]);
            auto tmp = recur(nums, l+1, h);
            for (auto& p : tmp)
            {
                p.insert(p.begin(), nums[l]);
                ret.push_back(p);
            }
            swap(nums[l], nums[i]);            
        }

        return ret;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return recur(nums, 0, nums.size()-1);
    }
};