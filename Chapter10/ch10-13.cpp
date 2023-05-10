#include <iostream>
#include <atomic>

template<typename T>
class lock_free_set {
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& v) : value(v), next(nullptr) {}
    };

    std::atomic<Node*> head;

public:
    lock_free_set() : head(nullptr) {}

    bool insert(const T& value) {
        Node* newNode = new Node(value);
        while (true) {
            Node* curHead = head.load();
            newNode->next = curHead;
            if (head.compare_exchange_weak(curHead, newNode)) {
                return true;
            }
            newNode->next = nullptr;
        }
    }

    bool contains(const T& value) {
        Node* curNode = head.load();
        while (curNode != nullptr) {
            if (curNode->value == value) {
                return true;
            }
            curNode = curNode->next;
        }
        return false;
    }
};

int main() {
    lock_free_set<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);

    if (set.contains(2)) {
        std::cout << "Set contains 2." << std::endl;
    } else {
        std::cout << "Set does not contain 2." << std::endl;
    }

    return 0;
}
