//211. Design Add and Search Words Data Structure

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

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;

        for (auto it: word) {
            if (!node->containsKey(it)) {
                node->put(it, new TrieNode());
            }

            node = node->get(it);
        }

        node->setEnd();
    }

    bool searchInWords(string word, TrieNode* root) {
        TrieNode* node = root;

        for (int i=0; i<word.size(); i++) {
            char ch = word[i];

            if (ch == '.') {
                for (auto j : node->links) {
                    string tmp = word.substr(i+1);
                    if (j && searchInWords(tmp, j)) 
                    return true;
                }
                return false;
            } else if (!node->containsKey(ch))
            return false;

            node = node->get(ch);
        }

        if (node->isEnd()) {
            return true;
        }

        return false;
    }
    
    bool search(string word) {
        return searchInWords(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
