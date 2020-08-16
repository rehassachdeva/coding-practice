// disjoint set union dsu
// union find

class Graph {
public:
    Graph(int n)
    {
        for (int i=0; i<n; i++)
            subsets.push_back({i, 1});
    }
    pair<int, int> find(int x)
    {
        if (subsets[x].first != x)
            subsets[x] = find(subsets[x].first);
        return subsets[x];
    }
    bool unionf(int x, int y)
    {
        auto xr=find(x), yr=find(y);
        if (xr == yr)
            return false;
        else if (xr.second<yr.second)
        {
            subsets[yr.first]=subsets[xr.first];
        }
        else  if (xr.second>yr.second)
        {
            subsets[xr.first]=subsets[yr.first];
        }
        else
        {
            subsets[yr.first].second++;
            subsets[xr.first]=subsets[yr.first];
        }
        return true;
    }
    vector<pair<int, int>> subsets;
};

class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n=accounts.size();
        
        Graph g(n);
        
        unordered_map<string, set<int>> idsbyemail;
        
        for (int i=0; i<n; i++)
        {
            for (int j=1; j<accounts[i].size(); j++)
            {
                idsbyemail[accounts[i][j]].emplace(i);
            }
        }
        
        for (auto& [email, v] : idsbyemail)
        {
            for (auto& idx1 : v)
            {
                for (auto& idx2 : v)
                {
                    if (idx1!=idx2)
                        g.unionf(idx1, idx2);
                }
            }
        }
        
        unordered_map<int, set<string>> ans;
        
        for (int i=0; i<g.subsets.size(); i++)
        {
            int head = g.find(g.subsets[i].first).first;
            for (int j=1; j<accounts[i].size(); j++)
            {
                ans[head].emplace(accounts[i][j]);    
            }
        }
        
        vector<vector<string>> ret;
        for (auto& [k, v] : ans)
        {
            vector<string> cur;
            cur.emplace_back(accounts[k][0]);
            for (auto& email : v)
                cur.emplace_back(email);
            ret.emplace_back(cur);
        }
        
        return ret;
    }
};