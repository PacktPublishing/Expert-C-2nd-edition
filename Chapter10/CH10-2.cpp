#include <memory>
#include <mutex>

namespace db_utils {

class ConnectionManager {

private:
  static std::shared_ptr<ConnectionManager> instance_;
  static std::mutex mutex_;

public:
  static std::shared_ptr<ConnectionManager> get_instance() {
    if (instance_ == nullptr) {
      // lock the mutex
      std::lock_guard lg { mutex_ };
      if (instance_ == nullptr) { 
        // double-checking 
        instance_.reset(new ConnectionManager());
      }
    }
    return instance_;
  }

}; // class ConnectionManager

} // namespace db_utils
