#pragma once
#include "ColliderShapes.h"
#include <iostream>

namespace col
{
	bool AABBvsAABB(AABB<float> a, AABB<float> b)
	{
		bool collision;
		Vec2<float> topRight1 = { a.xMax + a.m_Pos.xPos, a.yMax + a.m_Pos.yPos };
		Vec2<float> botLeft1 = { a.xMin + a.m_Pos.xPos, a.yMin + a.m_Pos.yPos };

		Vec2<float> topRight2 = { b.xMax + b.m_Pos.xPos, b.yMax + b.m_Pos.yPos };
		Vec2<float> botLeft2 = { b.xMin + b.m_Pos.xPos, b.yMin + b.m_Pos.yPos };

		if(topRight1.xPos >= botLeft2.xPos && topRight2.xPos >= botLeft1.xPos && 
		   topRight1.yPos >= botLeft2.yPos && topRight2.yPos >= botLeft1.yPos)
		{
			collision = true;
			std::cout << "Collider" << std::endl;
		}
		return collision;
	}
}