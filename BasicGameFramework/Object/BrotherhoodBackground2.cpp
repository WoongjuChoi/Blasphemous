#include "stdafx.h"
#include "BrotherhoodBackground2.h"
#include "../Component/MapSpriteComponent.h"

void BrotherhoodBackground2::Init()
{
	SetSize(1280, 720);
	MapSpriteComponent* backgroundImg = new MapSpriteComponent(this);
	backgroundImg->SetImage(L"Image/brotherhood/brotherhood_background2.bmp", GetWidth(), GetHeight(), true, RGB(255, 0, 255));
	backgroundImg->SetCoordinate(200, 200);
	backgroundImg->SetCameraSpeed(100);
	backgroundImg->SetWidth(400);
	backgroundImg->SetHeight(400);

	SetPivot(Pivot::LeftTop);
}