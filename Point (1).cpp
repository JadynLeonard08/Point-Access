#include "Point.h"

int Point::nextId = 100;
int Point::getNextId(){return nextId;}

void Point::display(ostream& out)const {
    out << id << " - (" << x << "," << y << ")" << endl;
}
double Point::distanceFromOrigin()const {
    return sqrt(x * x + y * y);
}
Point Point::add(const Point& other)const {
    Point p;
    p.x = x + other.x;
    p.y = y + other.y;
    return p;
}
Point Point::sub(const Point& other)const {
    Point p;
    p.x = x - other.x;
    p.y = y - other.y;
    return p;
}
Point Point::operator+(const Point& other)const {
    return Point(x + other.x, y + other.y);
}
Point Point::operator-(const Point& other)const {
    return Point(x - other.x, y - other.y);
}

Point& Point::operator=(const Point& other) {
    x = other.x;
    y = other.y;
    return *this;
}

Point Point::operator-()const {
    return Point(-x, -y);
}

Point Point::operator++() {
    ++x;
    ++y;
    return *this;
}

Point Point::operator++(int) {
    Point temp = *this;
    x++;
    y++;
    return temp;
}

bool Point::operator<(const Point& rhs)const {
    return (x < rhs.x || (x == rhs.x && y < rhs.y));
}
bool Point::operator>(const Point& rhs)const {
    return (x > rhs.x || (x == rhs.x && y > rhs.y));
}
bool Point::operator==(const Point& rhs)const {
    return (x == rhs.x && y == rhs.y);
}
bool Point::operator<=(const Point& rhs)const {
    return !(*this > rhs);
}
bool Point::operator>=(const Point& rhs)const{
    return !(*this < rhs);
}
bool Point::operator!=(const Point& rhs)const{
    return !(*this == rhs);
}

 ostream& operator<<(ostream& out, const Point& rhs){
     out << rhs.id << " - (" << rhs.x << "," << rhs.y << ")" << endl;
     return out;
 }
 istream& operator>>(istream& in, Point& rhs){
    in >> rhs.x >> rhs.y;
    return in;
 }



void bubbleSort(Point p[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (p[j].getX() > p[j+1].getX() ||
                (p[j].getX() == p[j+1].getX() &&
                    p[j].getY() > p[j+1].getY())) {
                swap(p[j], p[j+1]);
            }
        }
    }
}