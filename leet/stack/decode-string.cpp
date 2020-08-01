class Solution {
public:
    string decodeString(string s) {
        
        string cur="", cnt="";
        
        stack<string> stkcnt, stkstr;
        
        for (int i=0; i<s.size(); i++)
        {
            if (isdigit(s[i]))
                cnt+=s[i];
            
            else if (s[i]=='[')
            {
                stkcnt.push(cnt); cnt="";
                stkstr.push(cur); cur="";
            }
            
            else if (isalpha(s[i]))
                cur+=s[i];
            
            else if (s[i]==']')
            {
                int n=stoi(stkcnt.top()); stkcnt.pop();
                
                string tmp="";
                for (int i=0; i<n; i++)
                    tmp+=cur;
                
                cur = stkstr.top()+tmp; stkstr.pop();
            }
        }
        
        return cur;
    }
};