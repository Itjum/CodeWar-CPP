#include "adapt-legacy-rectangle.hh"

#include <cmath>
#include <iostream>

AdaptLegacyRectangle::AdaptLegacyRectangle(LegacyRectangle& rect)
    : rect_(rect)
{}

AdaptLegacyRectangle::~AdaptLegacyRectangle()
{}

void AdaptLegacyRectangle::print() const
{
    std::cout << "x: " << this->rect_.x1_get() << " y: " << this->rect_.y1_get()
              << '\n';
    std::cout << "height: "
              << std::abs(this->rect_.y1_get() - this->rect_.y2_get()) << '\n';
    std::cout << "width: "
              << std::abs(this->rect_.x1_get() - this->rect_.x2_get()) << '\n';
}

unsigned AdaptLegacyRectangle::area() const
{
    return this->rect_.compute_area();
}
