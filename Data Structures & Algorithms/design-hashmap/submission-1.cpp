class MyHashMap {
public:
    MyHashMap() : _set(1000, nullptr) {
        
    }
    
    void put(int key, int value) {
        auto hash = key % _set.size();

        if (!_set[hash]) {
            _set[hash] = new Node{key, value, nullptr};
            return;
        }

        auto* cur = _set[hash];
        while (true) {
            if (cur->key == key) {
                cur->val = value;
                return;
            }
            
            if (!cur->next) break;      
            cur = cur->next;             
        }

        cur->next = new Node{key, value, nullptr};
    }
    
    int get(int key) {
        auto hash = key % _set.size();
        auto* cur = _set[hash];

        while (cur) {
            if (cur->key == key) {
                return cur->val;
            }
            cur = cur->next;        
        }

        return -1;
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

private:
    struct Node {
        int key{};
        int val{};
        Node* next{};
    };

    std::vector<Node*> _set{};
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */