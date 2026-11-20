#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include <iostream>

class LineSegment {
private:
    double x_;
    double y_;

public:
    LineSegment();
    LineSegment(double x, double y);
    LineSegment(const LineSegment& other);

    double GetX() const;
    double GetY() const;

    void SetX(double x);
    void SetY(double y);

    bool Contains(double value) const;

    friend std::ostream& operator<<(std::ostream& os, const LineSegment& seg);

    // перегрузка унарных операторов
    double operator!() const;
    LineSegment& operator++();
    LineSegment operator++(int);

    // приведение типов
    explicit operator int() const;
    operator double() const;

    // перегрузка бинарных операторов
    LineSegment operator+(int d) const;
    bool operator>(int d) const;
};

#endif // LINE_SEGMENT_H
