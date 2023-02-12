/**
 * @file prototype.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef _PROTOTYPE_PROTOTYPE_H_
#define _PROTOTYPE_PROTOTYPE_H_

#include <string>

namespace ptype {

enum class Type : unsigned {
    INVALID = 0,
    PHONE,
    COMPUTER,
};

class Prototype {
  public:
    Prototype() = default;
    virtual ~Prototype() = default;
    virtual Prototype *Clone() const = 0;

  protected:
    Type type_;
    std::string name_;
};

} // namespace ptype

#endif // _PROTOTYPE_PROTOTYPE_H_