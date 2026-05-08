class MyHashSet {
public:
    MyHashSet() : _set(1000, nullptr) {
        
    }
    
    ~MyHashSet() {
        for (auto* head : _set) {
            auto* cur = head;
            while (cur) {
                auto* nextNode = cur->next;
                delete cur;
                cur = nextNode;
            }
        }
    }
    
    void add(int key) {
        auto hash = key % _set.size();

        if (!_set[hash]) {
            _set[hash] = new Node{key, nullptr};
            return;
        }

        auto* cur = _set[hash];
        while (true) {
            if (cur->key == key) return;
            
            if (!cur->next) break;    
            cur = cur->next;        
        }

        cur->next = new Node{key, nullptr};
    }
    
    void remove(int key) {
        auto hash = key % _set.size();

        if (!_set[hash]) return;

        auto* cur = _set[hash];

        if (cur->key == key) {
            _set[hash] = cur->next;
            delete cur; 
            return;
        }

        while (cur->next) {
            if (cur->next->key == key) {
                auto* nodeToDelete = cur->next;
                cur->next = cur->next->next;
                delete nodeToDelete; 
                return;         
            }
            cur = cur->next;         
        }
    }
    
    bool contains(int key) {
        auto hash = key % _set.size();
        auto* cur = _set[hash];

        while (cur) {
            if (cur->key == key) {
                return true;
            }
            cur = cur->next;        
        }

        return false;
    }

private:
    struct Node {
        int key{};
        Node* next{};
    };

    std::vector<Node*> _set{};
};