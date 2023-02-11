/**
 * @file dog.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "animal.h"
#include "animal_factory.h"

namespace fty {
class Dog : public Animal {
  public:
    Dog() = default;
    ~Dog() = default;

    IStatus Execute() override {
        std::cout << "I am a dog!" << std::endl;
        return IStatus::SUCCESS;
    }
};

REGISTER_ANIMAL(Dog, "Dog")
} // namespace fty
