// disjoint set union dsu
// union find

class Graph {
public:
    Graph(int n)
    {
        for (int i=0; i<=n; i++)
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Graph g(edges.size());
        for (int i=0; i<edges.size(); i++)
        {
            if (!g.unionf(edges[i][0], edges[i][1]))
                return edges[i];
        }
        return {};
    }
};