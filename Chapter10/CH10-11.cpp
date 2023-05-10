#include <atomic>
#include <memory>
#include <iostream>

template<typename T>
class lock_free_queue {
private:
    struct node {
        T data;
        std::atomic<node*> next;
        node(const T& value): data(value), next(nullptr) {}
    };

    std::atomic<node*> head;
    std::atomic<node*> tail;

public:
    lock_free_queue(): head(new node(T())), tail(head.load()) {}

    void push(const T& value) {
        node* new_node = new node(value);
        node* old_tail = tail.exchange(new_node, std::memory_order_acq_rel);
        old_tail->next = new_node;
    }

    bool pop(T& value) {
        node* old_head = head.load(std::memory_order_relaxed);
        while (true) {
            node* next = old_head->next.load(std::memory_order_acquire);
            if (!next) {
                return false;
            }
            if (head.compare_exchange_weak(old_head, next, std::memory_order_release)) {
                value = next->data;
                delete old_head;
                return true;
            }
        }
    }
};

int main() {
    lock_free_queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    int value;
    while (q.pop(value)) {
        std::cout << "Popped value: " << value << std::endl;
    }

    return 0;
}
