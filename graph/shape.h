/**
 * @file shape.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _GRAPH_SHAPE_H_
#define _GRAPH_SHAPE_H_

#include <stdint.h>
#include <vector>

namespace graph {
enum class Dim : unsigned {
    INVALID = 0U,
    N,
    C,
    H,
    W,
    O,
    I,
    NV,
    L,
};

enum class Layout : unsigned {
    INVALID = 0U,
    MATRIX,
    LINEAR,
    ACTIVATION,
    WEIGHT,
};

class Shape {
  public:
    Shape() = default;
    Shape(const std::vector<int64_t> &shape, const Layout &layout)
        : shape_{shape}, layout_{layout} {}
    void Set(const std::vector<int64_t> &shape);
    std::vector<int64_t> Get() const { return shape_; }
    int64_t &operator[](const Dim &dim);
    int64_t &operator[](size_t idx) { return shape_[idx]; }

  private:
    std::vector<int64_t> shape_;
    Layout layout_{Layout::INVALID};
};

} // namespace graph

#endif // _GRAPH_SHAPE_H_