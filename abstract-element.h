#pragma once

namespace DigiPen {

  class AbstractElement {
  public:

    AbstractElement() {}

    virtual ~AbstractElement() {}

    virtual int Get() const = 0;

    virtual void Set(int new_val) = 0;

    virtual void Print() const = 0;

    virtual AbstractElement* Clone() const = 0;
  };
}
