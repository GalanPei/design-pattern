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

    std::unique_ptr<Animal> Create(const std::string &name) {
        if (animal_hash_.find(name) == animal_hash_.end()) {
            return nullptr;
        }
        return std::make_unique<Animal>(animal_hash_.at(name));
    }

  private:
    AnimalFactory() = default;
    std::unordered_map<std::string, std::function<Animal *()>> animal_hash_;
};

} // namespace fty

#endif // _FACTORY_ANIMAL_FACTORY_H_