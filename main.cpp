#include <iostream>
#include <limits>
#include <string>

#include "line_segment.h"

// Функция безопасного ввода double с проверкой
double ReadDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        // Сообщение об ошибке
        std::cout << "Error. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Функция безопасного ввода int с проверкой
int ReadInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "Error. Please enter an integer." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    std::cout << "Lab 4. LineSegment testing." << std::endl;
    std::cout << std::endl;

    // 1: Базовое тестирование

    std::cout << "Task 1. Constructors." << std::endl;
    LineSegment seg1;
    std::cout << "seg1: " << seg1 << std::endl;

    // Запросы ввода
    double x = ReadDouble("Enter x: ");
    double y = ReadDouble("Enter y: ");
    LineSegment seg2(x, y);
    std::cout << "seg2: " << seg2 << std::endl;

    LineSegment seg3(seg2);
    std::cout << "seg3: " << seg3 << std::endl;
    std::cout << std::endl;

    std::cout << "Task 1. Contains." << std::endl;
    double value = ReadDouble("Enter number to check: ");
    std::cout << "Segment: " << seg2 << std::endl;
    std::cout << "Contains(" << value << "): " << (seg2.Contains(value) ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // 2: Перегруженные операции

    std::cout << "Task 2. Operators." << std::endl;
    std::cout << std::endl;

    LineSegment seg(3.7, 8.2);
    std::cout << "seg: " << seg << std::endl;
    std::cout << std::endl;

    // унарный оператор !
    std::cout << "Operator ! (length):" << std::endl;
    double length = !seg;
    std::cout << "!seg = " << length << std::endl;
    std::cout << std::endl;

    // операторы ++
    std::cout << "Operator ++:" << std::endl;
    LineSegment seg_inc1(2.0, 5.0);
    std::cout << "seg_inc1: " << seg_inc1 << std::endl;

    ++seg_inc1;
    std::cout << "++seg_inc1: " << seg_inc1 << std::endl;

    LineSegment seg_inc2(2.0, 5.0);
    LineSegment seg_inc2_old = seg_inc2++;
    std::cout << "seg_inc2++: " << seg_inc2 << " (old: " << seg_inc2_old << ")" << std::endl;
    std::cout << std::endl;

    // приведение типов
    std::cout << "Type casting:" << std::endl;
    LineSegment seg_cast(7.89, 12.34);
    std::cout << "seg_cast: " << seg_cast << std::endl;

    int int_value = static_cast<int>(seg_cast);
    std::cout << "(int)seg_cast = " << int_value << std::endl;

    double double_value = seg_cast;
    std::cout << "(double)seg_cast = " << double_value << std::endl;
    std::cout << std::endl;

    // бинарный оператор +
    std::cout << "Operator +:" << std::endl;
    LineSegment seg_add(3.0, 7.0);
    std::cout << "seg_add: " << seg_add << std::endl;
    int d = ReadInt("Enter d: ");
    LineSegment seg_result = seg_add + d;
    std::cout << "seg_add + d = " << seg_result << std::endl;
    std::cout << std::endl;

    // бинарный оператор >
    std::cout << "Operator >:" << std::endl;
    std::cout << "seg2: " << seg2 << std::endl;
    int check_value = ReadInt("Enter number to check: ");
    bool result = seg2 > check_value;
    std::cout << "seg2 > check_value: " << (result ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // комплексный тест
    std::cout << "Complex test:" << std::endl;
    LineSegment test_seg(1.5, 6.5);
    std::cout << "test_seg = " << test_seg << std::endl;
    std::cout << "!test_seg = " << !test_seg << std::endl;
    std::cout << "(int)test_seg = " << static_cast<int>(test_seg) << std::endl;
    std::cout << "(double)test_seg = " << static_cast<double>(test_seg) << std::endl;
    std::cout << "test_seg + 3 = " << (test_seg + 3) << std::endl;
    std::cout << "test_seg > 4 = " << (test_seg > 4 ? "true" : "false") << std::endl;
    std::cout << "test_seg > 10 = " << (test_seg > 10 ? "true" : "false") << std::endl;

    ++test_seg;
    std::cout << "++test_seg = " << test_seg << std::endl;

    return 0;
}
