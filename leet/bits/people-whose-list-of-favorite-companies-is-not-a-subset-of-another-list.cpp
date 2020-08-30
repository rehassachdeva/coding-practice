class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, int> m;
        int id=0;
        for (auto& p : favoriteCompanies)
        {
            for (auto& c : p)
            {
                m[c]=id++;
            }
        }
        vector<bitset<50001>> masks(101);
        int i=0;
        for (auto& p : favoriteCompanies)
        {
            for (auto& c : p)
            {
                masks[i].set(m[c]);
            }
            i++;
        }
        vector<int> ans;
        int n=favoriteCompanies.size();
        for (int i=0; i<n; i++)
        {
            bool flg=false;
            for (int j=0; j<n; j++)
            {
                if (i!=j)
                {
                    if ((masks[i]&masks[j])==masks[i])
                    {
                        flg=true;
                        break;
                    }
                }
            }
            if (!flg)
                ans.push_back(i);
        }
        return ans;
    }
};