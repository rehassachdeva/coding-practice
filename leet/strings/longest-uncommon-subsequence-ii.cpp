class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        
        int n=strs.size();

        int ans=-1;
        
        for (int i=0; i<n; i++)
        {
        
            bool flg = false;
            
            for (int j=0; j<n; j++)
            {
            
                if (i!=j)
                {
                    int k=0,l=0;
                    
                    while(k<strs[i].size() and l<strs[j].size())
                    {
                        if (strs[i][k]==strs[j][l])
                        {
                            k++;
                            l++;
                        }
                        else
                            l++;
                    }

                    if (k==strs[i].size())
                    {
                        flg=true;
                        break;
                    }
                }
                
            }
            
            if (!flg)
                ans=max(ans, (int)strs[i].size());
        }
        
        return ans;
        
    }
};