#pragma once

#include "leaf.hh"
#include "node.hh"
#include "tree.hh"
#include "visitor.hh"

namespace visitor
{
    class ComputeVisitor : public Visitor
    {
    public:
        ComputeVisitor();
        void visit(const tree::Tree& e) override;
        void visit(const tree::Node& e) override;
        void visit(const tree::Leaf& e) override;
        int value_get();

    private:
        int val_; // result of the computation
    };
} // namespace visitor