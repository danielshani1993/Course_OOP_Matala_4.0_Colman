#include "allShapes.h"
#include "Circle.h"
#include "Shape.h"
#include "Quad.h"
#include "Square.h"
#include "Point.h"
#include <typeinfo>
allShapes::allShapes()
{
    m_size = 0;
    m_arr = nullptr;
}

allShapes::allShapes(const allShapes& other)
{
    this->m_size = other.m_size;
    this->m_arr = new Shape * [other.m_size];
    for (size_t i = 0; i < other.m_size; i++)
    {
        m_arr[i] = other.m_arr[i];
    }
}

allShapes::~allShapes()
{
    delete[]m_arr;
}

int allShapes::getSize() const
{
    return this->m_size;
}

void allShapes::addShape(Shape* newShape)
{
    
    Shape** tmparr = new Shape * [m_size + 1];
    for (size_t i = 0; i < m_size; i++)
    {
        tmparr[i] = m_arr[i];
    }
    tmparr[m_size] = newShape;
    /*for (size_t i = 0; i < m_size-1; i++)
    {
        delete m_arr[i];
    }
    delete[]m_arr;*/
    m_arr = new Shape * [m_size+1];
    m_size++;
    for (size_t i = 0; i < m_size; i++)
    {
        m_arr[i] = tmparr[i];
    }
   /* for (size_t i = 0; i < m_size; i++)
    {
        delete tmparr[i];
    }
    delete[]tmparr;*/
}

void allShapes::removeShape(int index)
{
    if ((index + 1) == m_size) {
        delete m_arr[index];
    }
    else
    {
        m_arr[index] = m_arr[m_size - 1];
        m_arr[m_size - 1] = nullptr;
        //delete m_arr[m_size - 1];
    }
    m_size--;
}

int allShapes::totalArea() const
{
    int totalArea = 0;
    for (size_t i = 0; i < m_size; i++)
    {
        totalArea += (int)m_arr[i]->calcArea();
    }
    return totalArea;
}

int allShapes::totalPerimeter() const
{
    int totalPeri = 0;
    for (size_t i = 0; i < m_size; i++)
    {
        totalPeri += (int)this->m_arr[i]->calcPerimeter();
    }
    return totalPeri;
}

int allShapes::totalCircleArea() const
{
    int totalCirc = 0;
    for (size_t i = 0; i < m_size; i++)
    {
        if (dynamic_cast<Circle*>(m_arr[i]))
        {
            totalCirc += m_arr[i]->calcArea();
        }
    }
    return totalCirc;
}

int allShapes::totalSquarePerimeter() const
{
    int totalperi = 0;
    for (size_t i = 0; i < m_size; i++)
    {
        if (dynamic_cast<Square*>(m_arr[i]))
        {
            totalperi += m_arr[i]->calcPerimeter();
        }
    }
    return totalperi;
}

const allShapes& allShapes::operator+=(Shape* newS)
{
    this->addShape(newS);
    return *this;
}

Shape* allShapes::operator[](int ind) const
{
    return m_arr[ind];
}

allShapes allShapes::operator+(const allShapes& other) const
{
    allShapes* tmp = new allShapes;
    int count = 0;
    tmp->m_size = this->m_size + other.m_size;
    tmp->m_arr = new Shape * [tmp->m_size];
    for (size_t i = 0; i < m_size; i++)
    {
        tmp->m_arr[i] = m_arr[i];
    }
    for (size_t i = m_size; i < (m_size+other.m_size); i++)
    {
        tmp->m_arr[i] = other.m_arr[count];
    }
    return *tmp;
}

allShapes::operator int() const
{
    return m_size;
}
