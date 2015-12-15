//Dylan Guidry
//12/14/2015
//File to hold all classes that will be used to create commonly used shapes to perform collision checks

#pragma once
#include <sfwdraw.h>


//Class used to create rectangle objects
template <typename T>
class AABB
{
private:

	
public:
	sfw::Vec2<T> m_Pos; //Center position of the rectangle
	sfw::Vec2<T> Min, Max; //Minimum and Maximum size the rectangle can be on the x Axis

	sfw::Vec2<T> axis[4];

	//Default constructor
	AABB<T>() 
	{
		m_Pos = { 400, 300 };
		Min = { -30, -30 };
		Max = { 30, 30 };
	}

	//Sets the spawn position of the rectangle and the Min and Max for the size of the rectangles
	AABB<T>(sfw::Vec2<T> pos, sfw::Vec2<T> min, sfw::Vec2<T> max)
	{
		m_Pos = pos;
		Min = { m_Pos.xPos + min.xPos, m_Pos.yPos + min.yPos };
		Max = { m_Pos.xPos + max.xPos, m_Pos.xPos + max.yPos };
	}

	void Movement()
	{
		sfw::drawAABB(m_Pos, Min, Max);
		if (sfw::getKey('W'))
		{
			m_Pos.yPos += 2;
			Max.yPos += 2;
			Min.yPos += 2;
		}

		if (sfw::getKey('A'))
		{
			m_Pos.xPos -= 2;
			Max.xPos -= 2;
			Min.xPos -= 2;
		}

		if (sfw::getKey('S'))
		{
			m_Pos.yPos -= 2;
			Max.yPos -= 2;
			Min.yPos -= 2;
		}

		if (sfw::getKey('D'))
		{
			m_Pos.xPos += 2;
			Max.xPos += 2;
			Min.xPos += 2;
		}
	}

	//Deconstructor
	~AABB() {}
};
