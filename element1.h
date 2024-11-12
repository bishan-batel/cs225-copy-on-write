#ifndef ELEMENT1_H
#define ELEMENT1_H
#include "abstract-element.h"
#include <cstddef>

namespace DigiPen {
  class Element1 : public AbstractElement {
    static std::size_t total_count;
    static std::size_t alive_count;

  public:

    static std::size_t GetAlive();

    static std::size_t GetTotal();

    Element1(int _val);

    virtual ~Element1();

    Element1& operator=(const Element1& other);


    virtual int Get() const;

    virtual void Set(int new_val);

    virtual void Print() const;

    virtual AbstractElement* Clone() const;

  private:

    int val;
  };
} // namespace DigiPen
#endif
