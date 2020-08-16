class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy=0, yx=0;
        for (int i=0; i<s1.size(); i++)
        {
            if (s1[i]=='x' and s2[i]=='y') xy++;
            if (s1[i]=='y' and s2[i]=='x') yx++;
        }
        
        if (xy%2 != yx%2)
            return -1;
        else if (xy%2==0)
            return (xy+yx)/2;
        else
            return 2+(xy-1)/2+(yx-1)/2;
    }
};