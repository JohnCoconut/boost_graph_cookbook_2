#include <string>

template <typename T>
struct Base {
protected:
  static unsigned int counter;
};

template <typename T>
unsigned int Base<T>::counter = 0;

struct Counter : Base<Counter>
{
  Counter() {this->counter++;}
  std::string id() const {
    return std::string{"dotfile"} + std::to_string(counter);
  }
};
