#include "line_segment.h"
#include <cmath>
#include <algorithm>

LineSegment::LineSegment() {
    x_ = 0.0;
    y_ = 0.0;
}

LineSegment::LineSegment(double x, double y) {
    x_ = x;
    y_ = y;
}

LineSegment::LineSegment(const LineSegment& other) {
    x_ = other.x_;
    y_ = other.y_;
}

double LineSegment::GetX() const {
    return x_;
}

double LineSegment::GetY() const {
    return y_;
}

void LineSegment::SetX(double x) {
    x_ = x;
}

void LineSegment::SetY(double y) {
    y_ = y;
}

bool LineSegment::Contains(double value) const {
    double min_val = std::min(x_, y_);
    double max_val = std::max(x_, y_);
    return (value >= min_val && value <= max_val);
}

std::ostream& operator<<(std::ostream& os, const LineSegment& seg) {
    os << "LineSegment[" << seg.x_ << ", " << seg.y_ << "]";
    return os;
}

// 2: Перегруженные операции

// перегрузка унарного оператора ! - вычислить длину отрехка
double LineSegment::operator!() const {
    return std::abs(y_ - x_);
}

// ++ (префиксный)
LineSegment& LineSegment::operator++() {
    x_++;
    y_++;
    return *this;
}

// ++ (постфиксный)
LineSegment LineSegment::operator++(int) {
    LineSegment temp = *this;
    x_++;
    y_++;
    return temp;
}

// приведение типа к int (явная) - целая часть координаты x
LineSegment::operator int() const {
    return static_cast<int>(x_);
}

// приведение типа к double (неявная) - координата y
LineSegment::operator double() const {
    return y_;
}

// перегрузка бинарного оператора + int d
LineSegment LineSegment::operator+(int d) const {
    return LineSegment(x_ + d, y_ + d);
}

// перегрузка бинарного оператора > int d
bool LineSegment::operator>(int d) const {
    return Contains(static_cast<double>(d));
}
