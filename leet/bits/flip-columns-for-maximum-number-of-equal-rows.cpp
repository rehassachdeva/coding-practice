class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<bitset<300>, int> m;
        for (int i=0; i<matrix.size(); i++)
        {
            bitset<300> a,b;
            for (int j=0; j<matrix[i].size(); j++)
            {
                if (matrix[i][j]==0) a[j]=1;
                else b[j]=1;
            }
            m[a]++; m[b]++;
        }
        int ans=0;
        for (auto& [k,v] : m)
            ans=max(ans,v);
        return ans;
    }
};