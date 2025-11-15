struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the front
    void pushFront(int key, int value) {
        Node* node = new Node(key, value);

        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    // Insert at the end
    void pushBack(int key, int value) {
        Node* node = new Node(key, value);

        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    // Remove a specific node
    void remove(Node* node) {
        if (!node)
            return;

        if (node == head) {
            head = node->next;
        }
        if (node == tail) {
            tail = node->prev;
        }
        if (node->prev) {
            node->prev->next = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }

        delete node;
    }
};

class LRUCache {
public:
    int capacity;
    DoublyLinkedList dll;
    unordered_map<int, pair<int, Node*>> cache; // key -> {value, node}
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }
        dll.remove(cache[key].second);
        dll.pushFront(key, cache[key].first);
        cache[key].second = dll.head;
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            dll.remove(cache[key].second);
        } else if (cache.size() == capacity) {
            // Remove LRU item
            Node* evict = dll.tail;
            cache.erase(evict->key);
            dll.remove(evict);
        }
        dll.pushFront(key, value);
        cache[key] = {value, dll.head};
    }
};
