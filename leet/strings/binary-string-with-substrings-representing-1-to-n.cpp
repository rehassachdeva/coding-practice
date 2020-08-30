class Solution {
public:
    void add(string& cur)
    {
        for (int i=cur.size()-1; i>=0; i--)
        {
            if (cur[i]=='0')
            {
                cur[i]='1';
                return;
            }
            else
                cur[i]='0';
        }
        cur="1"+cur;
    }
    bool queryString(string S, int N) {
        string n="";
        while (N)
        {
            n+=to_string(N&1);
            N/=2;
        }
        reverse(n.begin(), n.end());
        string i="0";
        while (i!=n)
        {
            add(i);
            if (S.find(i)==string::npos)
                return false;
        }
        return true;
    }
};