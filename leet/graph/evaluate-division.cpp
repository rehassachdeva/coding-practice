class Solution {
public:
    
    void dfs(string cur, string& s, string& d, unordered_map<string, unordered_map<string, double>>& adj, unordered_map<string, bool>& vis, unordered_map<string, unordered_map<string, double>>& abyb, double prod)
    {
        vis[cur]=true;
        abyb[s][cur] = prod;
        if (cur==d)
            return;
        for (auto& [nei, val] : adj[cur])
        {
            if (!vis[nei])
                dfs (nei, s, d, adj, vis, abyb, prod*val);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, unordered_map<string, double>> adj;
        
        for (int i=0; i<equations.size(); i++)
        {
            adj[equations[i][0]][equations[i][1]] = values[i];
            if (values[i] != 0)
                adj[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        
        vector<double> ans(queries.size(), -1);
        unordered_map<string, unordered_map<string, double>> abyb;
        
        for (int i=0; i<queries.size(); i++)
        {
            auto& q = queries[i];
            
            if (!adj.count(q[0]) or !adj.count(q[1]))
                continue;
            
            if (q[0] == q[1])
            {
                ans[i] = 1;
                continue;
            }
            
            if (abyb.count(q[0]) and abyb[q[0]].count(q[1]))
            {
                ans[i] = abyb[q[0]][q[1]];
                continue;
            }
            
            unordered_map<string, bool> vis;
            dfs (q[0], q[0], q[1], adj, vis, abyb, 1);
            
            if (abyb.count(q[0]) and abyb[q[0]].count(q[1]))
                ans[i] = abyb[q[0]][q[1]];
        }
        
        return ans;
    }
};