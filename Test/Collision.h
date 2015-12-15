//	Dylan Guidry
//	12 / 15 / 2015
#pragma once
#include "ColliderShapes.h"
#include <iostream>
#include <list>

namespace col
{
	template<typename T>
	/*
		Name: AABBvsAABB
		Args: AABB, AABB
		Description: Checks the distance between the min and max points of two rectangles 
		to see if the points lie with each other.
		If max position is greater than the min position of the other they rectangles are
		in collision with one another
	*/
	bool AABBvsAABB(AABB<T> a, AABB<T> b)
	{		
		if (a.Max.xPos > b.Min.xPos && b.Max.xPos > a.Min.xPos &&
			a.Max.yPos > b.Min.yPos && b.Max.yPos > a.Min.yPos)
		{
			return true;
		}
	}

	template<typename T>
	/*
		Name: CIRCLEvsCIRCLE
		Args: Circle, Circle
		Description: Checks the distance between the center points of two circles and compares
		them to both of thier radi added together.
		If the distance between the two points is less than or equal to the radi added together
		the circles are in collision with one another
	*/
	bool CIRCLEvsCIRCLE(Circle<T> a, Circle<T> b)
	{
		if (CalcDis(a.m_Pos, b.m_Pos) <= a.radius + b.radius)
		{
			return true;
		}
	}

	template<typename T>
	/*
		Name:AABBvsCIRCLE
		Args: AABB, Circle
		Description: Checks distance between the center point of a circle and the min and max of
		a rectangle(AABB).
		To check if they are overlapping you need to clamp the position of the circle to the min and max
		of the rectangle(AABB)
		If the position of the circle subtracted by the clamped value less than or equal to the radius squared the
		two shapes are in collision with eachother
	*/
	bool AABBvsCIRCLE(AABB<T> a, Circle<T> b)
	{
		float PCx = b.m_Pos.xPos < a.Min.xPos ? a.Min.xPos : b.m_Pos.xPos > a.Max.xPos ? a.Max.xPos : b.m_Pos.xPos;
		float PCy = b.m_Pos.yPos < a.Min.yPos ? a.Min.yPos : b.m_Pos.yPos > a.Max.yPos ? a.Max.yPos : b.m_Pos.yPos;

		if (((b.m_Pos.xPos - PCx) * (b.m_Pos.xPos - PCx) <= (b.radius * b.radius)) &&
			((b.m_Pos.yPos - PCy) * (b.m_Pos.yPos - PCy) <= (b.radius * b.radius)))
		{
			return true;
		}
	}

	template<typename T>
	/*
		Name: CalcDis
		Args: Vec2, Vec2
		Descritption: Checks the distance between two points in space
	*/
	float CalcDis(sfw::Vec2<T> a, sfw::Vec2<T> b)
	{
		float result = sqrt(((a.xPos - b.xPos) * (a.xPos - b.xPos)) + ((a.yPos - b.yPos) * (a.yPos - b.yPos)));
		return result;
	}

//Sort and Sweep Algorithm
	template<typename T>
	void SortAxis(std::list<AABB<T>> rects)
	{
		for (int i = 1; i < rects.size(); i++)
		{
			
		}
	}
}