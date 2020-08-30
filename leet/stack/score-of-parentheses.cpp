class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        for (int i=0; i<S.size(); i++)
        {
            if (S[i]=='(')
                s.push(0);
            else
            {
                int tmp=max(1, 2*s.top());
                s.pop();
                if (s.empty())
                    s.push(tmp);
                else
                    s.top()+=tmp;
            }
        }
        return s.top();
    }
};