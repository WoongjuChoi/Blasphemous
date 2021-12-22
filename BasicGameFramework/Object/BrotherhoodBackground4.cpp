#include "stdafx.h"
#include "BrotherhoodBackground4.h"
#include "../Component/MapSpriteComponent.h"

void BrotherhoodBackground4::Init()
{
	SetSize(1280, 720);
	MapSpriteComponent* backgroundImg = new MapSpriteComponent(this);
	backgroundImg->SetImage(L"Image/brotherhood/brotherhood_background4.bmp", GetWidth(), GetHeight(), true, RGB(255, 0, 255));
	backgroundImg->SetCoordinate(200, 200);
	backgroundImg->SetCameraSpeed(160);
	backgroundImg->SetWidth(500);
	backgroundImg->SetHeight(500);

	SetPivot(Pivot::Center);
}