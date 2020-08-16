class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n=A.size();
        vector<int> s;
        int ans=0;
        for (int i=0; i<n; i++)
        {
            if (s.empty() or A[s.back()]>A[i])
                s.push_back(i);
        }
        for (int i=n-1; i>=0; i--)
        {
            while (!s.empty() and A[s.back()]<=A[i])
            {
                ans=max(ans, i-s.back());
                s.pop_back();
            }
        }
        return ans;
    }
};