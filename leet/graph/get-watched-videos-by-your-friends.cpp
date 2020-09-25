class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=watchedVideos.size();
        queue<int> q; q.push(id);
        int l=0;
        vector<bool> vis(n,false);
        vis[id]=true;     
        unordered_map<string, int> m;
        while(!q.empty())
        {
            if (l==level)
            {
                int t=q.size();
                for (int i=0; i<t; i++)
                {
                    auto cur=q.front(); q.pop();
                    for (auto& w : watchedVideos[cur])
                        m[w]++;
                }
                break;
            }
            int t=q.size();
            for (int i=0; i<t; i++)
            {
                auto cur=q.front(); q.pop();
                for (auto& nei : friends[cur])
                {
                    if (!vis[nei])
                        q.push(nei);
                    vis[nei]=true;
                }
            }
            l++;
        }
        vector<string> ans;
        for (auto& [k,v] : m)
            ans.emplace_back(k);
        sort(ans.begin(), ans.end(), [&m](const auto& a, const auto& b) { return make_pair(m[a], a) < make_pair(m[b], b); });
        return ans;
    }
};