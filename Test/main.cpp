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



	sfw::setBackgroundColor(BLACK);


	float x = 400, y = 300, speed = 200.0f;
	AABB<float> Rect({ x,y }, { -30,-30 }, { 30,30 });
	AABB<float> Rect2({ 100,100 }, { -30,-30 }, { 30,30 });
	float rot = 0;
	sfw::setMouse(true);
	

	while (sfw::stepContext())
	{
		sfw::drawAABB(Rect.m_Pos, Rect.Min, Rect.Max);
		sfw::drawAABB(Rect2.m_Pos, Rect2.Min, Rect2.Max);
		sfw::drawCircle( Rect.m_Pos.xPos, Rect.m_Pos.yPos, 2);
		sfw::drawCircle(Rect2.m_Pos.xPos, Rect2.m_Pos.yPos, 2);

		Rect.Movement();

		if (col::AABBvsAABB(Rect, Rect2) == true)
		{
			std::cout << "Colliding" << std::endl;
		}
		else
		{
			system("cls");
		}
		
		//sfw::drawTexture(u, x, y, sfw::getTextureWidth(u) / 2.5, sfw::getTextureHeight(u) / 2.5, rot, true, 0, 0x88ffffff);

	}

	sfw::termContext();
}