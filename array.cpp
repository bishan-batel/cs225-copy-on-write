#include "array.h"
#include <cstddef>
#include <cstring>

// if Factory is used cirrectly, there will be no more includes

DigiPen::Array::Array(
  int* array,
  std::size_t size,
  const DigiPen::ElementFactory* factory
):
    data(new AbstractElement*[size]),
    ref_count(new std::size_t(1)),
    length(size),
    element_factory(factory) {

  for (std::size_t i = 0; i < size; ++i) {
    data[i] = factory->MakeElement(1, array[i]);
  }
}

DigiPen::Array::~Array() {
  unref();
}

DigiPen::Array::Array(const Array& from):
    data(from.data),
    ref_count(from.ref_count),
    length(from.length),
    element_factory(from.element_factory) {
  *ref_count += 1;
}

DigiPen::Array& DigiPen::Array::operator=(const Array& array) {
  if (this == &array) {
    return *this;
  }

  unref();

  data = array.data;
  length = array.length;
  element_factory = array.element_factory;
  ref_count = array.ref_count;

  *ref_count += 1;

  return *this;
}

void DigiPen::Array::Set(const int id, const std::size_t pos, const int value) {
  if (*ref_count > 1) {
    deep_copy(); // modifying the data - need our own copy
  }
  delete data[pos];
  data[pos] = element_factory->MakeElement(id, value); // make sure is used
}

void DigiPen::Array::Print() const {
  for (unsigned int i = 0; i < length; ++i) {
    data[i]->Print();
  }
  std::cout << std::endl;
}

int DigiPen::Array::Get(unsigned int pos) const {
  return data[pos]->Get();
}

void DigiPen::Array::deep_copy() {
  AbstractElement** const new_data = new AbstractElement*[length];

  // clone all data
  for (std::size_t i = 0; i < length; i++) {
    new_data[i] = data[i]->Clone();
  }

  // unref  from the current reference counted data
  unref();

  // create new refocount
  ref_count = new std::size_t(1);
  data = new_data;
}

void DigiPen::Array::unref() {
  *ref_count -= 1;

  if (*ref_count > 0) {
    return;
  }

  delete ref_count;
  ref_count = NULL;

  for (std::size_t i = 0; i < length; i++) {
    delete data[i];
  }

  delete[] data;
  data = NULL;
}
