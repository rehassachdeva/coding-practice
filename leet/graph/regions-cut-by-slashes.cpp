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
    bool unionr(int x, int y)
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
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        Graph g(4*n*n);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                int vn = 4*(i*n+j);
                int nx, ny;
                
                if (i-1>=0)
                    g.unionr(vn, vn-4*n+2);
                
                if (i+1<n)
                    g.unionr(vn+2, vn+4*n);
                
                if (j-1>=0)
                    g.unionr(vn+3, vn-4+1);
                
                if (j+1<n)
                    g.unionr(vn+1, vn+4+3);

                if (grid[i][j]=='/')
                {
                    g.unionr(vn, vn+3);
                    g.unionr(vn+1, vn+2);
                }
                else if (grid[i][j]=='\\')
                {
                    g.unionr(vn, vn+1);
                    g.unionr(vn+3, vn+2);
                }
                else
                {
                    g.unionr(vn, vn+3);
                    g.unionr(vn, vn+1);
                    g.unionr(vn+1, vn+2);
                    g.unionr(vn+3, vn+2);
                }
            }
        }
        int ans=0;
        for (int i=0; i<g.subsets.size(); i++)
            if (g.subsets[i].first==i)
                ans++;
        return ans;
    }
};