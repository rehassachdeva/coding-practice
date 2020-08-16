class Solution {
public:
    bool isRobotBounded(string s) {
        int n=s.size(),x=0,y=0;
        s+=s+s+s;
        vector<pair<int, int>> dirs={{0,1}, {1,0}, {0,-1}, {-1,0}};
        int di=0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='G')
            {
                x+=dirs[di].first;
                y+=dirs[di].second;
            }
            else if (s[i]=='R')
            {
                di = (di+1)%4;
            }
            else
                di = (di-1+4)%4;
            if (((i+1)%n)==0 and x==0 and y==0)
                return true;
        }
        return false;
    }
};