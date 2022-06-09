#include "Circle.h"

Circle::Circle(double r, const char* sn)
{
    this->setRadius(r);
    m_centerPoint.setPoint(0, 0);
    this->setName(sn);
}

Circle::Circle(const Circle& other)
{
    *this = other;
}

Circle::~Circle()
{
}

double Circle::getRadius() const
{
    return m_radius;
}

void Circle::setRadius(double r)
{
    m_radius = r;
}

int Circle::calcArea() const
{
    int radius=0;
    radius = (int)(PI * (m_radius*m_radius));
    return radius;
    
}

int Circle::calcPerimeter() const
{
    int perimeter = 0;
    perimeter = (int)(2 * PI *m_radius);
    return perimeter;
}

const Circle& Circle::operator=(const Circle& other)
{
    Shape::operator=(other);
    m_radius = other.m_radius;
    return *this;
}

const Circle& Circle::operator=(const char* name)
{
    this->setName(name);
    return *this;
}

Circle operator+(int r, const Circle& other)
{
    Circle tmp;
    tmp.setShape(other.getName(), other.m_centerPoint);
    tmp.setRadius(tmp.getRadius() + r);
    return tmp;
}
