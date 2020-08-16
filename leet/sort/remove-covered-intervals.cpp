class Solution {
public:
    
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0]==b[0])
            return a[1]>b[1];
        else
            return a<b;
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int ans=0, maxr=0;
        
        for (auto& i : intervals)
        {
            ans += (i[1]>maxr);
            maxr=max(maxr,i[1]);
        }
        
        return ans;
    }
};