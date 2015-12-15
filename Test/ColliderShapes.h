//Dylan Guidry
//12/14/2015
//File to hold all classes that will be used to create commonly used shapes to perform collision checks

#pragma once
#include <sfwdraw.h>
#include <string>

//Class used to create rectangle objects
template <typename T>
class AABB
{
public:
	sfw::Vec2<T> m_Pos; //Center position of the rectangle
	sfw::Vec2<T> Min, Max; //Minimum and Maximum size the rectangle can be on the x Axis

	sfw::Vec2<T> axis[4];

	std::string name;

	//Default constructor
	AABB<T>() 
	{
		name = "Billy Bob";
		m_Pos = { 400, 300 };
		Min = { -30, -30 };
		Max = { 30, 30 };
	}

	//Sets the spawn position of the rectangle and the Min and Max for the size of the rectangles
	AABB<T>(std::string n,sfw::Vec2<T> pos, sfw::Vec2<T> min, sfw::Vec2<T> max)
	{
		name = n;
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
	~AABB<T>() {}
};

template <typename T>
class Circle
{
public:
	sfw::Vec2<T> m_Pos;
	float radius;

	Circle<T>()
	{
		m_Pos = { 400,300 };
		radius = 10;
	}

	Circle<T>(sfw::Vec2<T> pos, float r)
	{
		m_Pos = pos;
		radius = r;
	}

	void Movement()
	{
		sfw::drawCircle(m_Pos.xPos, m_Pos.yPos, radius);
		if (sfw::getKey('W'))
		{
			m_Pos.yPos += 2;
		}

		if (sfw::getKey('A'))
		{
			m_Pos.xPos -= 2;
		}

		if (sfw::getKey('S'))
		{
			m_Pos.yPos -= 2;
		}

		if (sfw::getKey('D'))
		{
			m_Pos.xPos += 2;
		}
	}

	~Circle<T>() {}
};

template <typename T>
class Ray
{
public:
	sfw::Vec2<T> m_Pos;
	sfw::Vec2<T> m_Dir;
	sfw::Vec2<T> m_End;
	float length;

	Ray() 
	{
		m_Pos = { 400,300 };
		m_Dir = { 10, 2 };
		length = 20;
		m_End = m_Dir * length;
	}

	Ray(sfw::Vec2<T> pos, sfw::Vec2<T> dir, float l)
	{
		m_Pos = pos;
		m_Dir = dir;
		length = l;
		m_End = m_Dir * length;
	}

	void Movement()
	{
		sfw::drawLine(m_Pos.xPos, m_Pos.yPos, m_End.xPos, m_End.yPos, 0xfffffff);
		if (sfw::getKey('W'))
		{
			m_Pos.yPos += 2;
			m_End.yPos += 2;
		}

		if (sfw::getKey('A'))
		{
			m_Pos.xPos -= 2;
			m_End.xPos -= 2;
		}

		if (sfw::getKey('S'))
		{
			m_Pos.yPos -= 2;
			m_End.yPos -= 2;
		}

		if (sfw::getKey('D'))
		{
			m_Pos.xPos += 2;
			m_End.xPos += 2;
		}
	}

	~Ray() {}
};