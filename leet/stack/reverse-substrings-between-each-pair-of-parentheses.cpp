class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string cur="";
        for (int i=0; i<s.size(); i++)
        {
            if (isalpha(s[i]))
                cur+=s[i];
            else if (s[i]==')')
            {
                reverse(cur.begin(), cur.end());
                cur=stk.top()+cur; stk.pop();
            }
            else
            {
                stk.push(cur);
                cur="";
            }
        }
        return cur;
    }
};