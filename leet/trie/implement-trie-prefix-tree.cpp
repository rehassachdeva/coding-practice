// clean trie code
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto* cur = this;
        for (int i=0; i<word.size(); i++)
        {
            if (!cur->children.count(word[i]))
                cur->children[word[i]] = new Trie();
            cur = cur->children[word[i]];
        }
        cur->isend=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto* cur = this;
        for (int i=0; i<word.size(); i++)
        {
            if (!cur->children.count(word[i]))
                return false;
            cur = cur->children[word[i]];
        }
        return cur->isend==true;        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        auto* cur = this;
        for (int i=0; i<word.size(); i++)
        {
            if (!cur->children.count(word[i]))
                return false;
            cur = cur->children[word[i]];
        }
        return true;
    }
    
    bool isend=false;
    unordered_map<char, Trie*> children;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */