#include "Factory.hpp"


using namespace std;
int main(void)
{
	ShapeFactory shapeFactory;

	Shape* triangle = shapeFactory.GetShape(ShapeFactory::TRIANGLE);
	bool res = true;
	res &=triangle->AddPoint({15,15});
	res &=triangle->AddPoint({23,30});
	res &=triangle->AddPoint({63,34});

	if(res)
		cout<<"Triangle Area \t\t= "      <<triangle->GetArea()<<std::endl;

	res = true;
	Shape* quadrilateral = shapeFactory.GetShape(ShapeFactory::QUADRILATERAL);
	res &= quadrilateral->AddPoint({2,2});
	res &= quadrilateral->AddPoint({4,10});
	res &= quadrilateral->AddPoint({9,7});
	res &= quadrilateral->AddPoint({11,2});
	
	if(res)
		cout<<"Quadrilateral Area \t= "   <<quadrilateral->GetArea()<<std::endl;
}
