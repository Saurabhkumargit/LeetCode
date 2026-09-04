// https://leetcode.com/problems/design-add-and-search-words-data-structure/

class WordDictionary {
public:
    struct Node {
        bool isEnd;
        Node* children[26];

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new Node();
            }

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }

    bool dfs(Node* curr, string& word, int pos) {
        // We have processed the entire word
        if (pos == word.size()) {
            return curr->isEnd;
        }

        char c = word[pos];

        // Normal character
        if (c != '.') {
            int idx = c - 'a';

            if (curr->children[idx] == nullptr) {
                return false;
            }

            return dfs(curr->children[idx], word, pos + 1);
        }

        for (int i = 0; i < 26; i++) {
            if (curr->children[i] != nullptr) {
                if (dfs(curr->children[i], word, pos + 1)) {
                    return true;
                }
            }
        }

        return false;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */