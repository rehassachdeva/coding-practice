class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        for (int l=1; l<=9; l++)
        {
            for (int i=1; i<=10-l; i++)
            {
                int s=0;
                for (int j=0; j<l; j++)
                    s=10*s+i+j;
                v.push_back(s);
            }
        }
        auto it1=lower_bound(v.begin(), v.end(), low);
        auto it2=upper_bound(v.begin(), v.end(), high);
        return vector<int>(it1,it2);
    }
};