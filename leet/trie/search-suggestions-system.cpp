// tries / trie with augmented nodes, info at every node
// storing top 3 strings at every node
// search auto complete

class TrieNode
{
public:
    
    void insert(string& p, int idx)
    {
        auto* cur = this;
        for (int i=0; i<p.size(); i++)
        {
            if (!cur->children.count(p[i]))
                cur->children[p[i]] = new TrieNode();
            cur = cur->children[p[i]];
            if (cur->first.size()<3)
                cur->first.push_back(idx);
        }
    }
    
    vector<int> first;
    unordered_map<char, TrieNode*> children;    
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(), products.end());
        
        TrieNode* root = new TrieNode();
        for (int i=0; i<products.size(); i++)
            root->insert(products[i], i);
        
        vector<vector<string>> ans(searchWord.size());
        auto cur=root;
        for (int i=0; i<searchWord.size(); i++)
        {
            if (!cur->children.count(searchWord[i]))
                break;
            cur = cur->children[searchWord[i]];
            vector<string> tmp;
            for (auto& idx : cur->first)
                tmp.push_back(products[idx]);
            if (tmp.size())
                ans[i]=tmp;
        }
            
        return ans;
        
    }
};