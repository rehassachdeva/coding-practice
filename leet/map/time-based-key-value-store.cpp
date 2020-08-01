// custom cmp function in lower_bound
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    static bool cmp(const pair<int, string>& a, const pair<int, string>& b)
    {
        return a.first<=b.first;
    }
    
    string get(string key, int timestamp) {
        
        if (!m.count(key) or m[key].empty())
            return "";
        
        auto it = lower_bound(m[key].begin(), m[key].end(), make_pair(timestamp, ""), cmp);
        
        if (it!=m[key].end() and it->first==timestamp)
            return it->second;
        
        if (it==m[key].begin())
            return "";
        
        --it;
        
        return it->second;
        
    }
    
    unordered_map<string, vector<pair<int, string>>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */