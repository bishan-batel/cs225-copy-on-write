#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include "abstract-element.h"
#include "element-factory.h"

namespace DigiPen {

  /*
   * Class Array implements a simple array-like data structure.
   * Objects inside the Array have to be derived from AbstractElement.
   */
  class Array {
  public:

    Array(
      int* array,
      std::size_t _size,
      const ElementFactory* _pElementFactory
    );

    Array(const Array& from);

    ~Array();

    Array& operator=(const Array& array);

    int Get(unsigned int pos) const;

    void Set(int id, std::size_t pos, int value);

    void Print() const;

  private:

    void deep_copy();

    void unref();

    AbstractElement** data;
    std::size_t* ref_count;
    std::size_t length;
    const ElementFactory* element_factory;
  };
} // namespace DigiPen
#endif
