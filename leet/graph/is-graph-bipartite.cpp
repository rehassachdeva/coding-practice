// graph colouring
// bipartite
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        for (int i=0; i<n; i++)
        {
            if (col[i]!=-1)
                continue;
            queue<pair<int, int>> q;
            q.emplace(i,0);
            while(!q.empty())
            {
                auto cur=q.front(); q.pop();
                for (auto& v : graph[cur.first])
                {
                    if (col[v]==cur.second)
                        return false;
                    if (col[v]==-1)
                        q.push({v, 1-cur.second});
                    col[v]=1-cur.second;
                }
            }
        }
        return true;
    }
};