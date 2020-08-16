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
    int totcomps()
    {
        unordered_map<int, int> m;
        for (auto& [v,r] : subsets)
            m[find(v).first]++;
        return m.size();
    }
    vector<pair<int, int>> subsets;
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Graph g(n);
        int extra=0;
        
        for (auto& e : connections)
        {
            if (!g.unionf(e[0], e[1]))
                extra++;
        }
        
        int totc=g.totcomps();
        
        if (extra>=totc-1)
            return totc-1;
        
        return -1;
        
    }
};