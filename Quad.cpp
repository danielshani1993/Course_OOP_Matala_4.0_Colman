#include "Quad.h"

Quad::Quad(double up, double down, double right, double left, const char* sn)
{
	this->setName(sn);
	m_centerPoint.setPoint(0, 0);
	m_up=up;
	m_down=down;
	m_right=right;
	m_left=left;
}

Quad::Quad(const Quad& other)
{
	this->operator=(other);
	this->m_up = other.m_up;
	this->m_down = other.m_down;
	this->m_left = other.m_left;
	this->m_right = other.m_right;
	
}

Quad::~Quad()
{
}

int Quad::calcArea() const
{
	int area = 0;
	area = (int)(m_right * m_up);
	return  area;
}

int Quad::calcPerimeter() const
{
	int peri = 0;
	peri =(int)( m_up + m_right + m_down + m_left);
	return peri;
}
