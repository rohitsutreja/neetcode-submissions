class MyHashSet {
public:
    MyHashSet() : _set(1000) {
        
    }
    
    void add(int key) {
        auto hash{key % _set.size()};

        if(_set[hash]){
            if(_set[hash]->key == key){
                return;
            }

            auto* cur{_set[hash]};

            while(cur->next){
                if(cur->key == key){
                    return;
                }
                cur = cur->next;
            }

            cur->next = new Node{key, nullptr};
        }
        else{
            _set[hash] = new Node{key, nullptr};
        }
    }
    
    void remove(int key) {
        auto hash{key % _set.size()};

        if(!_set[hash]){
            return;
        }

        auto* cur = _set[hash];

        if(cur->key == key){
            _set[hash] = cur->next;
            return;
        }

        while(cur->next){
            if(cur->next->key == key){
                cur->next = cur->next->next;
            }
        }

    }
    
    bool contains(int key) {
        auto hash{key % _set.size()};

        if(!_set[hash]){
            return false;
        }

        auto* cur = _set[hash];

        while(cur){
            if(cur->key == key){
                return true;
            }
        }

        return false;
    }


private:
    struct Node{
        int key{};
        Node* next{};
    };

    std::vector<Node*> _set{};
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */