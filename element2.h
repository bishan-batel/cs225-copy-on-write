#ifndef ELEMENT2_H
#define ELEMENT2_H
#include <iostream>
#include "abstract-element.h"

namespace DigiPen {
  class Element2 : public AbstractElement {
    static std::size_t total_count;
    static std::size_t alive_count;

  public:

    static std::size_t GetAlive();

    static std::size_t GetTotal();

    Element2(int _val);

    Element2(const Element2& rhs);

    virtual ~Element2();

    Element2& operator=(const Element2& rhs);

    virtual int Get() const;

    virtual void Set(int new_val);

    virtual void Print() const;

    virtual AbstractElement* Clone() const;

  private:

    int* p_val;
  };
}
#endif
