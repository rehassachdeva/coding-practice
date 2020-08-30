// gray code
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans(pow(2,n),0);
        for (int i=0; i<ans.size(); i++)
        {
            ans[i] = i^(i>>1);
        }
        rotate(ans.begin(), find(ans.begin(), ans.end(), start), ans.end());
        return ans;
    }
};