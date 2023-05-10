template <typename T>
class node {
private:
  node* head_;
  node* next_;
  T val;

public:
  node(T data) {}

  void push(T data) {
    node *new_elem = new node(data);
    new_elem->next_ = head_;
    head_ = new_elem;
  }
};
