class Solution {
public:
    bool recur(int mci, int mask, unordered_map<int, bool>& memo, int tot)
    {
        if (memo.find(mask) != memo.end())
            return memo[mask];
        bool ret=false;
        for (int i=0; i<mci; i++)
        {
            if (!(mask & (1<<i)))
            {
                ret |= !recur(mci, mask | (1<<i), memo, tot-(i+1)) or ((i+1) >= tot);
            }
            if (ret)
            {
                break;
            }
        }
        return memo[mask]=ret;
    }
    bool canIWin(int mci, int tot) {
        if ((mci * (mci + 1) / 2) < tot)
            return false;
        unordered_map<int, bool> memo;
        return recur(mci, 0, memo, tot);
    }
};