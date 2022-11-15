#include "builder.hh"

#include <memory>

Car Builder::get_car() const
{
    Car car;
    car.wheels_.at(0) = get_wheel();
    car.wheels_.at(1) = get_wheel();
    car.wheels_.at(2) = get_wheel();
    car.wheels_.at(3) = get_wheel();
    car.body_ = get_body();
    car.engine_ = get_engine();
    return car;
}

std::unique_ptr<Wheel> JeepBuilder::get_wheel() const
{
    auto res = std::make_unique<Wheel>(Wheel(22));
    return res;
}

std::unique_ptr<Engine> JeepBuilder::get_engine() const
{
    auto res = std::make_unique<Engine>(Engine(400));
    return res;
}

std::unique_ptr<Body> JeepBuilder::get_body() const
{
    auto res = std::make_unique<Body>(Body("SUV"));
    return res;
}

std::unique_ptr<Wheel> NissanBuilder::get_wheel() const
{
    auto res = std::make_unique<Wheel>(Wheel(16));
    return res;
}

std::unique_ptr<Engine> NissanBuilder::get_engine() const
{
    auto res = std::make_unique<Engine>(Engine(85));
    return res;
}

std::unique_ptr<Body> NissanBuilder::get_body() const
{
    auto res = std::make_unique<Body>(Body("hatchback"));
    return res;
}