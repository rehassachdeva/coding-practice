class Solution {
public:
    double recur(int a, int b, map<pair<int, int>, double>& memo)
    {
        if (memo.find({a,b}) != memo.end())
            return memo[{a,b}];
        if (a<=0 and b<=0) return 0.5;
        if (a<=0) return 1;
        if (b<=0) return 0;
        double ret=0;
        ret += 0.25*recur(a-4,b,memo);
        ret += 0.25*recur(a-3,b-1,memo);
        ret += 0.25*recur(a-2,b-2,memo);
        ret += 0.25*recur(a-1,b-3,memo);
        return memo[{a,b}]=ret;
    }
    double soupServings(int N) {
        N = N/25 + (N%25 != 0);
        if (N>=500) return 1;
        map<pair<int, int>, double> memo;
        return recur(N, N, memo);
    }
};