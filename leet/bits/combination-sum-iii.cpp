class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int cnt=0;
        for (int i=1; i<=pow(2,9)-1; i++)
        {
            cnt=1;
            if (__builtin_popcount(i)==k)
            {
                int j=i,s=0;
                vector<int> cur;
                while (j)
                {
                    int b=(j&1);
                    s+=b*cnt;
                    if (b)
                        cur.push_back(cnt);
                    j>>=1;
                    cnt++;
                }
                if (s==n)
                    ans.emplace_back(cur);
            }
        }
        return ans;
    }
};