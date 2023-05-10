template <typename T>
class lock_free_stack {
private:

  struct node {
    T data_;
    node* head_;

    node(const T& data) {}

  };

  node* head_;

// The rest of the body is omitted for brevity

public:

  void push(T data) {
    node *new_elem = new node(data);
    new_elem->next_ = head_;
    head_ = new_elem;
  }
};