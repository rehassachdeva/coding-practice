class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1==s2)
            return true;
        map<char, int> m;
        for (int i=0; i<s1.size(); i++)
        {
            m[s1[i]]++;
            m[s2[i]]--;
        }
        for (auto& [k,v] : m)
            if (v!=0)
                return false;
        int n=s1.size();
        for (int i=1; i<n; i++)
        {
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) and isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0,i), s2.substr(n-i)) and isScramble(s1.substr(i), s2.substr(0,n-i)))
                return true;
        }
        return false;
    }
};