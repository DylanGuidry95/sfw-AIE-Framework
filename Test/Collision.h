#pragma once
#include "ColliderShapes.h"
#include <iostream>

namespace col
{
	bool AABBvsAABB(AABB<float> a, AABB<float> b)
	{		
		if (a.Max.xPos < b.Min.xPos || b.Max.xPos < a.Min.xPos)
			return false; //not colliding in the x
		if (a.Max.yPos < b.Min.yPos || b.Max.yPos < a.Min.yPos)
			return false; //not colliding in the y

		if (a.Max.xPos > b.Min.xPos && b.Max.xPos > a.Min.xPos && a.Max.yPos > b.Min.yPos && b.Max.yPos > a.Min.yPos)
		{
			return true;
		}
	}
}