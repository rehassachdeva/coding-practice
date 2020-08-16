class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        
        vector<string> ans;
        
        vector<int> target(26,0);
        
        for (int i=0; i<B.size(); i++)
        {
            vector<int> cur(26,0);
            
            for (int j=0; j<B[i].size(); j++)
                cur[B[i][j]-'a']++;

            for (int j=0; j<target.size(); j++)
                target[j] = max(target[j], cur[j]);
        }
        
        for (int i=0; i<A.size(); i++)
        {
            vector<int> cnts(26,0);
        
            for (int j=0; j<A[i].size(); j++)
            {
                cnts[A[i][j]-'a']++;
            }
            
            bool flg = true;
            
            for (int j=0; j<target.size(); j++)
            {
                if (cnts[j] < target[j])
                    flg = false;
            }
            
            if (flg)
                ans.emplace_back(A[i]);
            
        }
        
        return ans;
    }
};