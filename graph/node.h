/**
 * @file node.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _GRAPH_NODE_H_
#define _GRAPH_NODE_H_

#include <memory>

#include "op_desc.h"
#include "var_desc.h"

namespace graph {
class Node {
  public:
    std::vector<Node *> GetInputs() { return inputs_; }
    std::vector<Node *> GetOutputs() { return outputs_; }
    void SetInputs(const std::vector<Node *> &inputs) { inputs_ = inputs; }
    void SetOutputs(const std::vector<Node *> &outputs) { outputs_ = outputs; }
    void ClearInputs() { inputs_.clear(); }
    void ClearOutputs() { outputs_.clear(); }
    void AddInput(const Node &node) { inputs_.emplace_back(&node); }
    void AddOutput(const Node &node) { inputs_.emplace_back(&node); }
    std::unique_ptr<VarDesc> Var() { return std::move(var_desc_); }
    std::unique_ptr<OpDesc> Op() { return std::move(op_desc_); }

  private:
    Node() = default;

    enum class Type : unsigned {
        GRAPH_OP = 0U,
        GRAPH_VAR,
    };

    std::unique_ptr<VarDesc> var_desc_{nullptr};
    std::unique_ptr<OpDesc> op_desc_{nullptr};
    std::vector<Node *> inputs_;
    std::vector<Node *> outputs_;
};

} // namespace graph

#endif // _GRAPH_NODE_H_