class Solution {
public:
    string reorganizeString(string S) {
        
        map<char, int> m;
        int n=S.size();
        
        for (auto& c : S)
            m[c]++;
        
        for (auto& [k,v] : m)
        {
            if (v>(n/2+n%2))
                return "";
        }

        priority_queue<pair<int, char>> pq;
        for (auto& [k,v] : m)
            pq.emplace(v,k);

        string ans="";        
        while (pq.size()>1)
        {
            auto f = pq.top(); pq.pop();
            auto s = pq.top(); pq.pop();
            
            ans += f.second;
            ans += s.second;
            
            f.first--;
            s.first--;
            
            if (f.first)
                pq.emplace(f.first, f.second);
            if (s.first)
                pq.emplace(s.first, s.second);
        }

        if (pq.empty())
            return ans;

        return ans + pq.top().second;

        return ans;
    }
};

