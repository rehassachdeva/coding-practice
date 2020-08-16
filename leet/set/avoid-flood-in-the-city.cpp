class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        set<int> s;
        map<int, int> m;
        
        for (int i=0; i<rains.size(); i++)
        {
            if (rains[i])
                m[rains[i]]=-1;
        }
        
        vector<int> ans(rains.size(), 1);
        for (int i=0; i<rains.size(); i++)
        {
            if (rains[i]==0)
            {
                s.insert(i);
                continue;
            }
            else if (m[rains[i]] != -1)
            {
                int idx=m[rains[i]];
                m[rains[i]]=i;
                
                if (s.empty())
                    return {};
                
                auto it = s.lower_bound(idx);
                if (it==s.end())
                    return {};
                
                ans[*it]=rains[i];
                s.erase(it);
            }
            m[rains[i]]=i;
            ans[i]=-1;
        }
        
        return ans;
        
    }
};