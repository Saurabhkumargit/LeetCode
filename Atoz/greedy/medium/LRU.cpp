// LRU Cache

class LRUCache {
  private:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail; 

    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addFront(node);
    }

    Node* removeLRU() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

  public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_) {
        if (mp.find(key_) == mp.end()) return -1;
        Node* node = mp[key_];
        moveToFront(node);
        return node->val;
    }

    void put(int key_, int value) {
        if (mp.find(key_) != mp.end()) {
            Node* node = mp[key_];
            node->val = value;
            moveToFront(node);
            return;
        }

        if ((int)mp.size() == cap) {
            Node* lru = removeLRU();
            mp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key_, value);
        mp[key_] = node;
        addFront(node);
    }
};
