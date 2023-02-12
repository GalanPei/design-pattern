/**
 * @file phone.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef _PROTOTYPE_PHONE_H_
#define _PROTOTYPE_PHONE_H_

#include "prototype.h"

namespace ptype {
class Phone : public Prototype {
  public:
    Phone() { type_ = Type::PHONE; }
    ~Phone() = default;
    Phone(const Phone &phone) : Phone() {
        brand_ = phone.brand_;
        size_ = phone.size_;
        model_ = phone.model_;
    }

    void SetBrand(const std::string &brand) { brand_ = brand; }

    void SetSize(float size) { size_ = size; }

    void SetModel(const std::string &model) { model_ = model; }

    Prototype *Clone() const override {
        auto ret{std::make_shared<Phone>(*this)};
        return ret.get();
    }

  protected:
    std::string brand_;
    float size_;
    std::string model_;
};
} // namespace ptype

#endif // _PROTOTYPE_PHONE_H_