/**
 * @file animal_factory.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _FACTORY_ANIMAL_FACTORY_H_
#define _FACTORY_ANIMAL_FACTORY_H_

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "animal.h"

namespace fty {

/**
 * @brief Factory of Animal objects, implemented by Singleton
 *
 */
class AnimalFactory final {
  public:
    virtual ~AnimalFactory() = default;

    static AnimalFactory *GetInstance() {
        static AnimalFactory instance;
        return &instance;
    }

    void RegisterAnimal(const std::string &name,
                        const std::function<Animal *()> func) {
        if (animal_hash_.find(name) != animal_hash_.end()) {
            return;
        }
        animal_hash_.emplace(name, func);
    }

    Animal *Create(const std::string &name) {
        if (animal_hash_.find(name) == animal_hash_.end()) {
            return nullptr;
        }
        return animal_hash_.at(name)();
    }

  private:
    // Constructor is set private in Singleton
    AnimalFactory() = default;
    // Hash map to store the function of creating each Animal object and
    // the keys of these objects
    std::unordered_map<std::string, std::function<Animal *()>> animal_hash_;
};

class RegisterHelper {
  public:
    RegisterHelper(const std::string &name,
                   const std::function<Animal *()> &func) {
        AnimalFactory::GetInstance()->RegisterAnimal(name, func);
    }
};

// Macro to register each animal object
#define REGISTER_ANIMAL(class_name, name)                                      \
    static RegisterHelper g_##class_name##_register(                           \
        name, []() -> class_name * {                                           \
            auto ret{std::make_shared<class_name>()};                          \
            return ret.get();                                                  \
        });

} // namespace fty

#endif // _FACTORY_ANIMAL_FACTORY_H_