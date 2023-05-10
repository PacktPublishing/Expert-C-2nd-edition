#include <memory>
#include <mutex>
#include <stack>


template <typename T> class safe_stack {

private:
  std::stack<T> wrappee_;
  mutable std::mutex mutex_;

public:
  safe_stack();
  safe_stack(const safe_stack &other);
  void push(T value);
  std::shared_ptr<T> pop();
  bool empty() const;
};

template <typename T> safe_stack<T>::safe_stack(const safe_stack<T> &other) {
  std::lock_guard<std::mutex> lock(other.mutex_);
  wrappee_ = other.wrappee_;
}

template <typename T> void safe_stack<T>::push(T value) {
  std::lock_guard<std::mutex> lock(mutex_);
  wrappee_.push(value);
}

template <typename T> std::shared_ptr<T> safe_stack<T>::pop() {
  std::lock_guard<std::mutex> lock(mutex_);
  if (wrappee_.empty()) {
    return nullptr;
  } else {
    return std::make_shared<T>(wrappee_.top());
  }
}
