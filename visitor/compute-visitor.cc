#include "compute-visitor.hh"

#include <stdexcept>

namespace visitor
{
    ComputeVisitor::ComputeVisitor()
    {}

    void ComputeVisitor::visit(const tree::Tree& e)
    {
        auto temp = ComputeVisitor();
        e.accept(temp);
    }

    int ComputeVisitor::value_get()
    {
        return val_;
    }

    void ComputeVisitor::visit(const tree::Node& e)
    {
        auto l = ComputeVisitor();
        auto r = ComputeVisitor();

        e.lhs_get()->accept(l);
        e.rhs_get()->accept(r);

        auto rhs = r.value_get();
        auto lhs = l.value_get();

        auto currentoperateur = e.value_get();

        if (currentoperateur == "-")
        {
            this->val_ = lhs - rhs;
        }
        else if (currentoperateur == "+")
        {
            this->val_ = lhs + rhs;
        }
        else if (currentoperateur == "*")
        {
            this->val_ = lhs * rhs;
        }
        else if (currentoperateur == "/")
        {
            if (rhs == 0)
            {
                throw std::overflow_error("Divide by zero exception");
            }
            else
            {
                this->val_ = lhs / rhs;
            }
        }
    }

    void ComputeVisitor::visit(const tree::Leaf& e)
    {
        val_ = std::stoi(e.value_get());
    }
} // namespace visitor