#include "Factory.hpp"


using namespace std;
int main(void)
{
	Shape* triangle 	 = new TriangleShape({15,15},{23,30},{63,34});
	Shape* quadrilateral = new QuadrilateralShape({2,2},{4,10},{9,7},{11,2});
	cout<<"Triangle Area \t\t= "      <<triangle->GetArea()<<std::endl;
	cout<<"Quadrilateral Area \t= "   <<quadrilateral->GetArea()<<std::endl;
}
