class TrieNode {
public:
    TrieNode* links[26];

    bool ending;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch -'a'] = node;
    }

    void setEnd() {
        ending = true;
    }

    bool isEnd() {
        return ending;
    }
};

class Trie {
public:

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* node = root;

        for (auto it: word) {
            if (!node->containsKey(it)) {
                node->put(it, new TrieNode());
            }

            node = node->get(it);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;

        for (auto it: word) {
            if (!node->containsKey(it)) {
                return false;
            }

            node = node->get(it);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (auto it: prefix) {
            if (!node->containsKey(it)) {
                return false;
            }

            node = node->get(it);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
