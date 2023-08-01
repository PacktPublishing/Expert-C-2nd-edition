#include <mutex>

std::mutex mutex_;

void foo() {
  mutex_.lock();
  int a{41};
  int b{a + 1};
  mutex_.unlock();
}
/*
load() 
store() 
exchange()
compare_exchange_weak() 
compare_exchange_strong() 
wait()
notify_one() 
notify_all()

load()
store()
exchange()
compare_exchange_weak()
compare_exchange_strong()
wait()
notify_one()
notify_all()

top()
empty()
size() 
push() 
emplace()
pop()
swap()
*/