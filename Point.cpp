#include "Point.h"

Point::Point(int x, int y)
{
    this->setX(x);
    this->setY(y);
}

Point::Point(const Point& other)
{
    this->setX(other.m_x);
    this->setY(other.m_y);
}

Point::~Point()
{
}

int Point::getX() const
{
    return this->m_x;
}

int Point::getY() const
{
    return this->m_y;
}

void Point::setX(int x)
{
    this->m_x = x;
}

void Point::setY(int y)
{
    this->m_y = y;
}

void Point::setPoint(int x, int y)
{
    this->setX(x);
    this->setY(y);
}

void Point::setPoint(const Point& other)
{
    this->setX(other.m_x);
    this->setY(other.m_y);
}

bool Point::operator==(const Point& other) const
{
    if (this->getX()==other.getX())
    {
        if (this->getY()==other.getY())
        {
            return true;
        }
    }
    return false;
}

bool Point::operator!=(const Point& other) const
{
    return (!(operator==(other)));
}

Point Point::operator+(int num) const
{
    Point tmpP;
    tmpP.m_x = this->getX() + num;
    tmpP.m_y = this->getY() + num;
    return tmpP;
}

const Point& Point::operator+=(int num)
{
    this->m_x += num;
    this->m_y += num;
    return *this;
}

Point::operator int() const
{
    return m_x + m_y;
}

Point Point::operator+(const Point& other) const
{
    Point tmpP;
    tmpP.m_x = this->getX() + other.getX();
    tmpP.m_y = this->getY() + other.getY();
    return tmpP;
}

Point Point::operator++(int)
{
    Point tmp;
    tmp.m_x = m_x;
    tmp.m_y = m_y;
    this->m_x ++;
    this->m_y ++;
    return tmp;
}

const Point& Point::operator++()
{
    this->m_x++;
    this->m_y++;
    return *this;
}


Point operator*(int num, const Point& other)
{
    Point tmp;
    tmp.m_x  = other.m_x*num;
    tmp.m_y  = other.m_y*num;
    return tmp;
}
