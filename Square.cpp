#include "Square.h"

Square::Square(double up, double down, double right, double left, const char* sn):Quad(up,down,right,left,sn)
{

}

Square::~Square()
{
}

void Square::shiftX(int x)
{
	getCenter().setX(this->getCenter().getX() + x);
}

void Square::shiftY(int y)
{
	getCenter().setY(this->getCenter().getY()+y);
}
