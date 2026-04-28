struct TrieNode {
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        isEnd = false;
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* crawlNode = root;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(crawlNode->child[idx] == NULL) {
                crawlNode->child[idx] = new TrieNode();
            }
            crawlNode = crawlNode->child[idx];
        }
        crawlNode->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* crawlNode = root;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(crawlNode->child[idx] == NULL) {
                return false;
            }
            crawlNode = crawlNode->child[idx];
        }
        return crawlNode->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawlNode = root;
        for(int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if(crawlNode->child[idx] == NULL) {
                return false;
            }
            crawlNode = crawlNode->child[idx];
        }
        return true;
    }
};
