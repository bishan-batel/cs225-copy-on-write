#include "element2.h"

namespace DigiPen {
  std::size_t Element2::total_count = 0;
  std::size_t Element2::alive_count = 0;

  Element2::Element2(int _val): p_val(new int(_val)) {
    total_count++;
    alive_count++;
  }

  Element2::Element2(const Element2& rhs):
      AbstractElement(), p_val(new int(*rhs.p_val)) {
    total_count++;
    alive_count++;
  }

  Element2& Element2::operator=(const Element2& rhs) {
    if (this != &rhs) {
      delete p_val;
      total_count++;
      p_val = new int(*rhs.p_val);
    }
    return *this;
  }

  int Element2::Get() const {
    return *p_val;
  }

  void Element2::Print() const {
    std::cout << "(" << *p_val << ") ";
  }

  void Element2::Set(int new_val) {
    *p_val = new_val;
  }

  Element2::~Element2() {
    alive_count--;
    delete p_val;
  }

  AbstractElement* Element2::Clone() const {
    return new Element2(*this);
  }

  std::size_t Element2::GetAlive() {
    return alive_count;
  }

  std::size_t Element2::GetTotal() {
    return total_count;
  }
}
