class Solution {
public:
    bool go(int i, vector<int>& arr, bool& ans, unordered_map<int, bool>& m)
    {
        if (i<0 or i>=arr.size())
            return false;
        if (m.count(i))
            return m[i];
        if (arr[i]==0)
        {
            return m[i]=true;
        }
        m[i] = false;
        return m[i] = (go(i+arr[i], arr, ans, m) or go(i-arr[i], arr, ans, m));
    }
    bool canReach(vector<int>& arr, int start) {
        unordered_map<int, bool> m;
        bool ans=false;
        return go(start, arr, ans, m);
    }
};