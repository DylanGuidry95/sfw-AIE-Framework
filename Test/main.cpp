#include "Collision.h"


void main()
{
	sfw::initContext(800,600,"NSFW Draw");
	// load Texture Map
	unsigned f = sfw::loadTextureMap("../res/tonc_font.png", 6, 16);	// test non-square atlas
	unsigned d = sfw::loadTextureMap("../res/fontmap.png",16,16);
	unsigned r = sfw::loadTextureMap("../res/background.jpg",4,1);
	unsigned u = sfw::loadTextureMap("../res/crosshair.png");

	float acc = 0;
	float scroll = 0;
	char c = '\0';

	float animTimer = 0;
	int index = 0;
	int animArray[2] = {1,'a'};

	std::list<AABB<float>> rectList;
	std::list<AABB<float>>::iterator it;
	std::list<AABB<float>> axisList;
	sfw::setBackgroundColor(BLACK);


	float x = 400, y = 300, speed = 200.0f;
	AABB<float> Rect("Dylan",{ x,y }, { -30,-30 }, { 30,30 });
	AABB<float> Rect2("Bob",{ 100,100 }, { -30,-30 }, { 30,30 });
	AABB<float> Rect3("Ted", { 200,400 }, { -30,-30 }, { 30,30 });
	AABB<float> Rect4("Fred", { 500,500 }, { -30,-30 }, { 30,30 });

	Circle<float> circle({ x,y }, 15);
	//Circle<float> circle2({ 100,100 }, 15);

	rectList.push_back(Rect2);
	rectList.push_back(Rect);
	rectList.push_back(Rect3);
	rectList.push_back(Rect4);

	float rot = 0;
	sfw::setMouse(true);
	

	while (sfw::stepContext())
	{
//AABB Tests
		sfw::drawAABB(Rect2.m_Pos, Rect2.Min, Rect2.Max);
//
//		Rect.Movement();
//
//		if (col::AABBvsAABB(Rect, Rect2) == true)
//		{
//			std::cout << "Colliding" << std::endl;
//		}
//		else
//		{
//			system("cls");
//		}
//

//Circle Tests
		circle.Movement();
//		sfw::drawCircle(circle2.m_Pos.xPos, circle2.m_Pos.yPos, circle2.radius);
//
//		if (col::CIRCLEvsCIRCLE(circle, circle2) == true)
//		{
//			std::cout << "Colliding" << std::endl;
//		}
//		else
//		{
//			system("cls");
//		}

//Circle vs AABB test
		//if (col::AABBvsCIRCLE(Rect2, circle) == true)
		//{
		//	std::cout << "Colliding" << std::endl;
		//}
		//else
		//{
		//	system("cls");
		//}
	}

	sfw::termContext();
}