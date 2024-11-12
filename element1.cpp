#include "element1.h"
#include <iostream>

namespace DigiPen {

  std::size_t Element1::total_count = 0;
  std::size_t Element1::alive_count = 0;

  Element1::Element1(int _val): val(_val) {
    total_count++;
    alive_count++;
  }

  int Element1::Get() const {
    return val;
  }

  void Element1::Set(int new_val) {
    val = new_val;
  }

  void Element1::Print() const {
    std::cout << "[" << Get() << "] ";
  }

  AbstractElement* Element1::Clone() const {
    return new Element1(val);
  }

  std::size_t Element1::GetAlive() {
    return alive_count;
  }

  std::size_t Element1::GetTotal() {
    return total_count;
  }

  Element1::~Element1() {
    alive_count--;
  }

  Element1& Element1::operator=(const Element1& other) {
    if (this == &other) {
      return *this;
    }

    val = other.val;

    return *this;
  }
}
