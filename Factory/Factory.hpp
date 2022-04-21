//! Factory Implementation
#include <cstring>
#include <cmath>
#include <iostream>
#include <cassert>
class CartesianPoint
{

public:
	enum CoordLabels
	{
		X,
		Y
	};

	CartesianPoint();
	CartesianPoint(const double c);
	CartesianPoint(const double x,const double y);
	CartesianPoint(const double* coords);
	CartesianPoint(const CartesianPoint &point);
	CartesianPoint(const std::pair<double,double> &coords);

	double GetX() const { return GetCoordinate(X);}
	double GetY() const { return GetCoordinate(Y);}
	double GetCoordinate(const CoordLabels label) const { return coordinates[label];}

private:
	double coordinates[2];

};

CartesianPoint::CartesianPoint()
{
	coordinates[X] = 0.0;
	coordinates[Y] = 0.0;
}

CartesianPoint::CartesianPoint(double c)
{
	coordinates[X] = c;
	coordinates[Y] = c;
}

CartesianPoint::CartesianPoint(const double x,const double y)
{
	coordinates[X] = x;
	coordinates[Y] = y;
}

CartesianPoint::CartesianPoint(const double* coords)
{
	memcpy(coordinates,coords,2*sizeof(double));
}

CartesianPoint::CartesianPoint(const std::pair<double,double> &coords)
{
	coordinates[X] = coords.first;
	coordinates[Y] = coords.second;
}

CartesianPoint::CartesianPoint(const CartesianPoint &point)
{
	memcpy(coordinates,point.coordinates,2*sizeof(double));
}

//! Shape
class Shape
{
public:

	Shape(const uint8_t numOfPoints);
	virtual ~Shape();
	virtual double GetArea() const = 0;
	
	bool AddPoint(const std::pair<double,double>& pt);

protected:

	uint8_t 	     pointsNum;
	CartesianPoint** points;
};

Shape::Shape(const uint8_t numOfPoints):pointsNum(numOfPoints)
{
	points = nullptr;
	if(pointsNum)
	{
		points = new CartesianPoint*[pointsNum];
		for(uint8_t i=0;i<pointsNum;i++)
			points[i] = nullptr;
	}
}

Shape::~Shape()
{
	for(uint8_t i=0;i<pointsNum;i++)
	{
		delete points[i];
	}
	delete[] points;
}

bool Shape::AddPoint(const std::pair<double,double>& pt)
{
	uint8_t i=0;
	while(i<pointsNum)
	{
		if(!points[i])
		{
			points[i] = new CartesianPoint(pt);
			return true;
		}
		i++;
	}
	return false;
}

//! Triangle
class TriangleShape : public Shape
{
public:
	TriangleShape();
	TriangleShape(const std::pair<double,double>& p0,
				  const std::pair<double,double>& p1,
				  const std::pair<double,double>& p2);

	virtual double GetArea() const override;
private:

};

TriangleShape::TriangleShape()
	:Shape(3)
{}

TriangleShape::TriangleShape(const std::pair<double,double>& p0,
							 const std::pair<double,double>& p1,
							 const std::pair<double,double>& p2) :Shape(3)
{
	points[0] = new CartesianPoint(p0);
	points[1] = new CartesianPoint(p1);
	points[2] = new CartesianPoint(p2);
}

double TriangleShape::GetArea() const
{
	return fabs(points[0]->GetX()*(points[1]->GetY()-points[2]->GetY())+
				points[1]->GetX()*(points[2]->GetY()-points[0]->GetY())+
				points[2]->GetX()*(points[0]->GetY()-points[1]->GetY()))/2.0;
}

//! Rectangle
class QuadrilateralShape : public Shape
{
public:
	QuadrilateralShape();

	QuadrilateralShape(const std::pair<double,double>& p0,
					   const std::pair<double,double>& p1,
					   const std::pair<double,double>& p2,
					   const std::pair<double,double>& p3);

	virtual double GetArea() const override;
private:

};

QuadrilateralShape::QuadrilateralShape()
	:Shape(4)
{}

QuadrilateralShape::QuadrilateralShape(const std::pair<double,double>& p0,
									   const std::pair<double,double>& p1,
							  		   const std::pair<double,double>& p2,
									   const std::pair<double,double>& p3) :Shape(4)
{
	points[0] = new CartesianPoint(p0);
	points[1] = new CartesianPoint(p1);
	points[2] = new CartesianPoint(p2);
	points[3] = new CartesianPoint(p3);
}

double QuadrilateralShape::GetArea() const
{
	return fabs((points[0]->GetX()*points[1]->GetY()-points[0]->GetY()*points[1]->GetX())+
				(points[1]->GetX()*points[2]->GetY()-points[1]->GetY()*points[2]->GetX())+
				(points[2]->GetX()*points[3]->GetY()-points[2]->GetY()*points[3]->GetX())+
				(points[3]->GetX()*points[0]->GetY()-points[3]->GetY()*points[0]->GetX()))/2.0;
}

//! ShapeFactory
class ShapeFactory
{
	public:
	enum ShapeType
	{
		TRIANGLE,
		QUADRILATERAL
	};

	ShapeFactory() = default;

	Shape* GetShape(const ShapeType& s) const;
};


Shape* ShapeFactory::GetShape(const ShapeType& s) const 
{
	switch (s)
	{
		case TRIANGLE:
			return new TriangleShape();
		case QUADRILATERAL:
			return new QuadrilateralShape();
		default:
			assert(0);
	}
	return nullptr;
}