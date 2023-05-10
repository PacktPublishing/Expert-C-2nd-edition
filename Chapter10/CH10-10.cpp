#include <atomic>
#include <memory>

template <typename T>
class lock_free_stack {
private:
    struct node {
        T data_;
        std::shared_ptr<node> next_;

        node(T value) : data_(std::move(value)), next_(nullptr) {}
    };

    std::atomic<std::shared_ptr<node>> head_;
public:
    void push(T data) {
        std::shared_ptr<node> new_elem = std::make_shared<node>(data);

        new_elem->next = head_.load();
        while (!std::atomic_compare_exchange_weak(&head_, &new_elem->next, new_elem)) {
            new_elem->next = head_.load();
        }
    }
    std::shared_ptr<T> pop() {
        std::shared_ptr<node> old_head = head_.load();
        while (old_head && 
            !std::atomic_compare_exchange_weak(&head_, &old_head, old_head->next)) {
            old_head = head_.load();
        }

        return (old_head ? std::make_shared<T>(std::move(old_head->value)) : nullptr);
    }

};