#include "vector.hh"

Vector& Vector::operator+=(const Vector& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vector& Vector::operator*=(int scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& vect)
{
    os << '{' << vect.x << ',' << vect.y << '}';
    return os;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    auto res = Vector();
    res.x = lhs.x + rhs.x;
    res.y = lhs.y + rhs.y;
    return res;
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
    auto res = Vector();
    res.x = lhs.x - rhs.x;
    res.y = lhs.y - rhs.y;
    return res;
}

Vector operator*(const Vector& lhs, int scalar)
{
    auto res = Vector();
    res.x = lhs.x * scalar;
    res.y = lhs.y * scalar;
    return res;
}

Vector operator*(int scalar, const Vector& rhs)
{
    auto res = Vector();
    res.x = rhs.x * scalar;
    res.y = rhs.y * scalar;
    return res;
}

int operator*(const Vector& lhs, const Vector& rhs)
{
    int res = lhs.x * rhs.x + lhs.y * rhs.y;
    return res;
}
