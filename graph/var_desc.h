/**
 * @file var_desc.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _GRAPH_VAR_DESC_H_
#define _GRAPH_VAR_DESC_H_

#include <string>

#include "shape.h"

namespace graph {
class VarDesc {
  public:
    VarDesc() = delete;
    ~VarDesc() = default;
    explicit VarDesc(const std::string &name);
    Shape GetShape() const { return shape_; }
    void SetShape(const Shape &shape) { shape_ = shape; }
    void SetShape(const std::vector<int64_t> &shape);
    Layout GetLayout() const { return layout_; }
    void SetLayout(const Layout &layout) { layout_ = layout; }

  private:
    std::string var_name_;
    Shape shape_;
    Layout layout_;
};

} // namespace graph

#endif // _GRAPH_VAR_DESC_H_