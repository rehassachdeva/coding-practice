// Dijkstra with max number of nodes
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        
        // store the distance for each value of number of stops
        unordered_map<int, unordered_map<int, int>> m;
        
        using P = pair<int, int>;
        using T = tuple<int, int, int>;
        
        vector<vector<P>> adj(n);
        for (auto& flight : flights)
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(0, 0, src);

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
        
            int dist = get<0>(cur);
            int stps = get<1>(cur);
            int nxt = get<2>(cur);
            
            if (stps>K)
                continue;
            
            for (auto& [v,w] : adj[nxt])
            {
                if (!m.count(v) or !m[v].count(stps+1) or m[v][stps+1] > dist+w)
                {
                    m[v][stps+1] = dist+w;
                    pq.emplace(dist+w, stps+1, v);
                }
            }
        }
        
        int ret=INT_MAX;
        for (auto& [k,v] : m[dst])
            ret = min(ret, v);
        
        return (ret==INT_MAX) ? -1 : ret;
    }
};