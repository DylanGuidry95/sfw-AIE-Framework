//Dylan Guidry
//12/14/2015
//File to hold all classes that will be used to create commonly used shapes to perform collision checks

#pragma once
#include <sfwdraw.h>

//Positional values 
template <typename T>
struct Vec2
{
	T xPos;
	T yPos;
};

//Class used to create rectangle objects
template <typename T>
class AABB
{
private:
	Vec2<T> m_Pos; //Center position of the rectangle
	float xMin, xMax; //Minimum and Maximum size the rectangle can be on the x Axis
	float yMin, yMax; //Minimum and Maximum size the rectangle can be on th ey Axis

public:
	//Default constructor
	AABB<T>() 
	{
		m_Pos = { 400, 300 };
		xMax = 10;
		yMax = 10;
		xMin = 20;
		yMin = 20;
	}

	//Sets the spawn position of the rectangle and the Min and Max for the size of the rectangles
	AABB<T>(Vec2<T> pos, float maxX, float maxY, float minX, float minY)
	{
		m_Pos = pos;
		yMax = maxY;
		xMax = maxX;
		xMin = minX;
		yMin = minY;
	}

	//Deconstructor
	~AABB() {}
};
