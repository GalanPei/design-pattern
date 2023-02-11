/**
 * @file animal.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef _FACTORY_ANIMAL_H_
#define _FACTORY_ANIMAL_H_

#include <iostream>

namespace fty {
enum class IStatus : unsigned {
    INVALID = 0u,
    SUCCESS,
    BAD_PARAM,
};

/**
 * @brief Base class of Animal object
 *
 */
class Animal {
  public:
    Animal() = default;
    virtual ~Animal() = default;
    virtual IStatus Execute() { return IStatus::SUCCESS; }
};

} // namespace fty

#endif // _FACTORY_ANIMAL_H_