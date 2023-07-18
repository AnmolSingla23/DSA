class LRUCache {
public:
    //creating a doubly linked list class with key value pair
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;

        node(int key,int val){
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    unordered_map<int,node*> mp; //map with key and its nodes val

    node* head = new node(0,0);
    node* tail = new node(0,0);
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insert(node* curr){
        
        curr->next = head->next;
        head->next->prev = curr;
        head->next = curr;
        curr->prev = head;
        mp[curr->key] = curr;
    }

    void remove(node* curr){  //removing the curr node from the ddl
        mp.erase(curr->key);   
        curr->next->prev = curr->prev;   //then replacing the next and prev pointers
        curr->prev->next = curr->next;  //of its next and prev
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end()){  //if key is not found in the map
            return -1;
        }

        node* curr = mp[key];  //take the curr as the node
        remove(curr);   //remove th val from ddl 
        insert(curr);   //then insert it at the begining that is recently used
        return curr->val;   
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            remove(mp[key]);
        }

        if(mp.size() == capacity){  //if size is full remove the least used that is
            remove(tail->prev);   //nearest to tail
        }
        insert(new node(key,value));  //now insert it in the ddl by making a nn
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */