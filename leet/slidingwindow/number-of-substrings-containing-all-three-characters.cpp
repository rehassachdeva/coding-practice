class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> m;
        int p=0, ans=0;
        for (int i=0; i<s.size(); i++)
        {
            m[s[i]]++;
            while (m['a'] and m['b'] and m['c'])
            {
                m[s[p]]--;
                p++;
            }
            ans += p;
        }
        return ans;
    }
};