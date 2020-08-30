class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string, bool> m;
        static const vector<pair<int, int>> dirs={{0,1}, {0,-1}, {1,0}, {-1, 0}};
        int step=0;
        string cur="";
        for (int i=0; i<board.size(); i++)
        {
            for (int j=0; j<board[0].size(); j++)
            {
                cur+=to_string(board[i][j]);
            }
        }
        queue<string> q;
        q.push(cur);
        while (!q.empty())
        {
            int n=q.size();
            for (int i=0; i<n; i++)
            {
                auto cur = q.front();
                q.pop();
                if (cur=="123450")
                    return step;
                int pos=cur.find("0");
                int x=pos/3, y=pos%3;
                for (auto& d : dirs)
                {
                    int nx=x+d.first, ny=y+d.second;
                    if (nx>=0 and ny>=0 and nx<2 and ny<3)
                    {
                        int npos=nx*3+ny;
                        swap(cur[pos], cur[npos]);
                        if (m.find(cur)==m.end())
                        {
                            m[cur]=true;
                            q.push(cur);
                        }
                        swap(cur[pos], cur[npos]);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};