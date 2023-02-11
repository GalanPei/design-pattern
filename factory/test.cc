/**
 * @file test.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "animal_factory.h"

int main() {
    using namespace fty;
    auto cat{AnimalFactory::GetInstance()->Create("Cat")};
    cat->Execute();
    auto dog{AnimalFactory::GetInstance()->Create("Dog")};
    dog->Execute();
}