class Solution {
public:
    int recur(string s, unordered_map<string, int>& memo)
    {
        if (s.empty())
            return 1;
        if (s[0]=='0')
            return 0;
        if (s.size()==1)
            return 1;
        if (memo.find(s) != memo.end())
            return memo[s];
        int ret = recur(s.substr(1), memo);
        if (s[0]=='1')
            ret += recur(s.substr(2), memo);
        if (s[0]=='2' and s[1]<='6')
            ret += recur(s.substr(2), memo);
        memo[s] = ret;
        return ret;
    }
    int numDecodings(string s) {
        unordered_map<string, int> memo;
        return recur(s, memo);
    }
};