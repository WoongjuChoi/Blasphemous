#include "stdafx.h"
#include "BrotherhoodBackground1.h"
#include "../Component/MapSpriteComponent.h"

void BrotherhoodBackground1::Init()
{
	SetSize(1280, 720);
	MapSpriteComponent* backgroundImg = new MapSpriteComponent(this);
	backgroundImg->SetImage(L"Image/brotherhood/brotherhood_background1.bmp", GetWidth(), GetHeight(), true, RGB(255, 0, 255));
	backgroundImg->SetCoordinate(150, 300);
	backgroundImg->SetCameraSpeed(70);
	
	SetPivot(Pivot::RightTop);
}