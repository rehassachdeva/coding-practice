class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, unordered_map<int, int>> m;
        int r=1;
        for (int i=0; i<votes.size(); i++)
        {
            r=1;
            for (auto& c : votes[i])
            {
                m[c][r++]++;
            }
        }
        string ans{votes[0]};
        int t=votes[0].size();
        sort(ans.begin(), ans.end(), [&m, &t] (const auto& a, const auto& b) {
            for (int i=1; i<=t; i++)
            {
                if (m[a][i]>m[b][i])
                    return true;
                if (m[b][i]>m[a][i])
                    return false;
            }
            return a<b;
        });
        return ans;
    }
};