// trie dfs
// compressed trie
struct TrieNode
{
    unordered_map<string, struct TrieNode*> children;
    bool is_end=false;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        auto root = newNode();
        for (int i=0; i<folder.size(); i++)
        {
            string cur = folder[i]+"/";
            insert(cur, root);
        }
        vector<string> ans;
        dfs(root, ans, "");
        return ans;
    }
    
    void insert(string& s, struct TrieNode* root)
    {
        auto cur = root;
        int i=1;
        vector<char> tmp;
        while(i<s.size())
        {
            if (s[i]=='/')
            {
                string path(tmp.begin(), tmp.end());
                if (!cur->children[path])
                    cur->children[path] = newNode();
                cur = cur->children[path];                    
                tmp.clear();
            }
            else
                tmp.push_back(s[i]);
            i++;
        }
        cur->is_end=true;
    }
    
    void dfs(TrieNode* root, vector<string>& ans, string tmp)
    {
        if (!root)
            return;
        if (root->is_end)
        {
            ans.push_back(tmp);
            return;
        }
        for (auto& c : root->children)
        {
            string nw = tmp + "/" + c.first;
            dfs(c.second, ans, nw);
        }
    }
    
    struct TrieNode* newNode()
    {
        auto ret = new TrieNode;
        ret->is_end=false;
        ret->children.clear();
        return ret;
    }
};