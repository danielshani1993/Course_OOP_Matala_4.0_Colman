#define _CRT_SECURE_NO_WARNINGS

#include "Shape.h"
int Shape::s_totalNumOfShapes = 0;
Shape::Shape(const char* sn)
{
    this->m_centerPoint.setPoint(0, 0);
    this->setName(sn);
    this->s_totalNumOfShapes++;
}

Shape::Shape(const Shape& other)
{ 
    m_centerPoint.setPoint(other.m_centerPoint);
    this->setName(other.m_shapeName);
    this->s_totalNumOfShapes++;
}

Shape::~Shape()
{
    delete[]this->m_shapeName;
    this->s_totalNumOfShapes--;
}

void Shape::setName(const char* name)
{
    this->m_shapeName = new char[strlen(name) + 1];
    strcpy(this->m_shapeName, name);
}

void Shape::setCenter(const Point& p)
{
    this->m_centerPoint.setPoint(p.getX(), p.getY());
}

const char* Shape::getName() const
{
    return m_shapeName;
}

Point Shape::getCenter() const
{
    return m_centerPoint;
}

void Shape::setShape(const char* sn, const Point& other)
{
    this->setName(sn);
    this->m_centerPoint.setPoint(other);
}

int Shape::numOfShapes()
{
    return s_totalNumOfShapes;
}

const Shape& Shape::operator=(const Shape& other)
{
    this->m_centerPoint.setPoint(other.m_centerPoint);
    this->setName(other.m_shapeName);
    return *this;
}
