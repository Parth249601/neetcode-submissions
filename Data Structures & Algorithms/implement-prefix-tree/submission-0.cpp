struct Trie{
    Trie* nxt[26] = {};
    bool isEnd = false;
};
class PrefixTree {
    Trie* root = new Trie();
    Trie* walk(const string& w){
        Trie* curr = root;
        for(char ch : w){
            int k = ch - 'a';
            if(!curr->nxt[k]) return nullptr;
            curr = curr->nxt[k];
        }
        return curr;
    }
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        Trie* curr = root;
        for(char ch : word){
            int k = ch - 'a';
            if(!curr->nxt[k]) curr->nxt[k] = new Trie();
            curr = curr->nxt[k];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Trie* curr = walk(word); 
        return curr && curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = walk(prefix);
        return curr;
    }
};
