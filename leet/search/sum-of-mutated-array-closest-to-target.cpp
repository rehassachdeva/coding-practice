class Solution {
public:
    int func(vector<int>& arr, int v)
    {
        int sum=0;
        for (int i=0; i<arr.size(); i++)
            sum+=min(arr[i],v);
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int l=1,h=*max_element(arr.begin(), arr.end());
        sort(arr.begin(), arr.end());
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if (func(arr, mid)>target)
                h=mid-1;
            else
                l=mid+1;
        }
        int p=abs(func(arr, l)-target), q=abs(target-func(arr, l-1));
        return (p<q) ? l : l-1;
    }
};