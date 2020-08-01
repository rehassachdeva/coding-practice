// dijkstra directed weighted graph
// dijkstra with heap
// dijkstra with priority queue

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K)
    {
        
        unordered_map<int, int> m;
        for (int i=1; i<=N; i++)
            m[i] = INT_MAX;
        
        using P = pair<int, int>;
        
        vector<vector<P>> adj(N+1);
        for (auto& time : times)
            adj[time[0]].emplace_back(time[1], time[2]);
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.emplace(0, K);
        int dist=0;
        m[K]=0;
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            dist = cur.first;
            int nxt = cur.second;
            
            for (auto& [v,w] : adj[nxt])
            {
                if (m[v]>dist+w)
                {
                    m[v]=dist+w;
                    pq.emplace(dist+w, v);
                }
                
            }
        }
        
        int ans=INT_MIN;
        for (int i=1; i<=N; i++)
        {
            if (m[i]==INT_MAX)
                return -1;
            else
                ans = max(ans, m[i]);
        }
        
        return ans;
    }
};