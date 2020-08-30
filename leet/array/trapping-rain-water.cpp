class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> maxl(n,-1), maxr(n,-1);
        int cmx=0;
        for (int i=1; i<n; i++)
        {
            maxl[i]=cmx;
            if (height[i]>height[cmx])
                cmx=i;
        }
        cmx=n-1;
        for (int i=n-2; i>=0; i--)
        {
            maxr[i]=cmx;
            if (height[i]>height[cmx])
                cmx=i;
        }
        int ans=0;
        for (int i=0; i<n; i++)
        {
            if (maxl[i]!=-1 and maxr[i]!=-1)
                ans += max(0, min(height[maxl[i]], height[maxr[i]]) - height[i]);
        }
        return ans;
    }
};