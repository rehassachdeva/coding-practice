// binary search
class Solution {
public:
    
    bool possible(vector<int>& weights, int D, int w)
    {
        int cnt=0, cur=0;
        for (int i=0; i<weights.size(); i++)
        {
            if (cur+weights[i]>w)
            {
                cur=0;
                cnt++;
            }
            cur+=weights[i];
        }
        
        return cnt+1<=D;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        
        int h=accumulate(weights.begin(), weights.end(), 0);
        int l=*max_element(weights.begin(), weights.end());
        
        while (l<=h)
        {
            int mid = l+(h-l)/2;
            if (possible(weights, D, mid))
                h=mid-1;
            else
                l=mid+1;
        }
        
        return l;
    }
};