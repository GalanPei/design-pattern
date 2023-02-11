/**
 * @file cat.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef _FACTORY_CAT_H_
#define _FACTORY_CAT_H_

#include "animal.h"

namespace fty {
class Cat : public Animal {
  public:
    Cat() = default;
    ~Cat() = default;
    IStatus Execute() override {
        std::cout << "I am a cat!" << std::endl;
        return IStatus::SUCCESS;
    }
};

} // namespace fty

#endif // _FACTORY_CAT_H_