/**
 * @file shape.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "shape.h"

namespace graph {
int64_t &Shape::operator[](const Dim &dim) {
    switch (layout_) {
    case Layout::MATRIX:
        break;
    case Layout::ACTIVATION:
        break;
    case Layout::WEIGHT:
        break;
    case Layout::LINEAR:
        break;
    default:
        break;
    }
    return shape_[0];
}
} // namespace graph
