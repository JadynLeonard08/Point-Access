#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;
class Point {
private:
    int x;
    int y;
    int id;
    static int nextId;

public:
    Point(int x = 0, int y = 0):x(x), y(y), id(nextId) {
        ++nextId;
    }

    int getX()const{return x;}
    int getY()const{return y;}
    int getID()const{return id;}
    static int getNextId();

    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}

    void display(ostream&)const;
    double distanceFromOrigin()const;
    Point add(const Point&)const;
    Point sub(const Point&)const;

    Point operator+(const Point& other)const;
    Point operator-(const Point& other)const;

    Point& operator=(const Point&);

    Point operator-()const;
    //Pre increment ++
    Point operator++();

    //Post Increment
    Point operator++(int);
    //Relational Operator Overloading

    bool operator<(const Point& rhs)const;
    bool operator>(const Point& rhs)const;
    bool operator==(const Point& rhs)const;
    bool operator<=(const Point& rhs)const;
    bool operator>=(const Point& rhs)const;
    bool operator!=(const Point& rhs)const;

    friend ostream& operator<<(ostream& out, const Point&);
    friend istream& operator>>(istream& in, Point& );


};

void bubbleSort(Point[], int);
#endif