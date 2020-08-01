// topological sort
// iscyclic
// graph of graphs
class Graph
{
public:
    
    void addNode(int node)
    {
        adj[node] = {};
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool isCyclicUtil(int s, unordered_map<int, bool>& vis,
                      unordered_map<int, bool>& recstk)
    {
        if (vis[s])
            return false;
        
        vis[s] = recstk[s] = true;
        
        for (auto& nei : adj[s])
        {
            if (!vis[nei] and isCyclicUtil(nei, vis, recstk))
                return true;
            else if (recstk[nei])
                return true;
        }
        
        recstk[s] = false;
        return false;
    }   

    bool isCyclic()
    {
        unordered_map<int, bool> vis;
        unordered_map<int, bool> recstk;

        for (auto& v : adj)
        {
            if (isCyclicUtil(v.first, vis, recstk))
                return true;
        }

        return false;
    }

    void topologicalSortUtil(int s, unordered_map<int, bool>& vis, vector<int>& ans)
    {
        vis[s] = true;
        
        for (auto& nei : adj[s])
        {
            if (!vis[nei])
                topologicalSortUtil(nei, vis, ans);
        }        
        
        ans.push_back(s);
    }

    vector<int> topologicalSort()
    {
        unordered_map<int, bool> vis;
        vector<int> ans;

        for (auto& v : adj)
        {
            if (!vis[v.first])
                topologicalSortUtil(v.first, vis, ans);         
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    unordered_map<int, vector<int>> adj;
};

class Solution {
public:

    vector<int> sortItems(int n, int m,
                          vector<int>& group,
                          vector<vector<int>>& beforeItems)
    {
        
        for (int i=0; i<n; i++)
        {
            if (group[i] == -1)
                group[i] = m++;
        }

        // create the graphs
        Graph groups;
        for (int i=0; i<m; i++)
            groups.addNode(i);
        unordered_map<int, Graph> items;
        for (int i=0; i<n; i++)
        {
            items[group[i]].addNode(i);
        }

        map<pair<int, int>, bool> lookup;
        for (int i=0; i<n; i++)
        {
            for (auto& v : beforeItems[i])
            {
                int grpu = group[v], grpv = group[i];
                
                if (!lookup[{grpu, grpv}] and grpu != grpv)
                {
                    groups.addEdge(grpu, grpv);
                    lookup[{grpu, grpv}] = true;
                }
                else if (grpu == grpv)
                {
                    items[grpu].addEdge(v, i);
                }
            }
        }

        // First check if groupadj is not cyclic
        if (groups.isCyclic())
            return {};

        // Now proceed in topo sort order of groups
        vector<int> ans;
        vector<int> sorted_groups = groups.topologicalSort();
        for (int i=0; i<m; i++)
        {
            int grp = sorted_groups[i];
            if (items[grp].isCyclic())
                return {};
            vector<int> tmp = items[grp].topologicalSort();
            for (int j=0; j<tmp.size(); j++)
                ans.push_back(tmp[j]);
        }
    
        return ans;   
    }
};