// I don't know what observation this is
// Majority of numbers<1e5 can be represented as sum of <=3 perfect squares!

// Ah checkout Legendre's three-square theorem

// this stupid exponential approach gets accepted because ans is atmost 4!

class Solution {
public:
    bool check(int n, int k)
    {
        if (k==1)
        {
            int t=sqrt(n);
            return t*t==n;
        }
        for (int i=1; i*i<n; i++)
        {
            int t=n-i*i;
            if (check(t, k-1))
                return true;
        }
        return false;
    }
    int numSquares(int n) {
        int l=1, h=n;
        for (int i=1; i<=n; i++)
            if (check(n,i))
                return i;
        return n;
    }
};