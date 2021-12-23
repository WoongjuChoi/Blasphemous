#include "stdafx.h"
#include "BrotherhoodBackground5.h"
#include "../Component/MapSpriteComponent.h"

void BrotherhoodBackground5::Init()
{
	SetSize(1280, 720);
	MapSpriteComponent* backgroundImg = new MapSpriteComponent(this);
	backgroundImg->SetImage(L"Image/brotherhood/brotherhood_background5.bmp", GetWidth(), GetHeight(), true, RGB(255, 0, 255));
	backgroundImg->SetCoordinate(200, 200);
	backgroundImg->SetCameraSpeed(160);
	backgroundImg->SetWidth(500);
	backgroundImg->SetHeight(500);
	backgroundImg->SetStandard(true);

	SetPivot(Pivot::Center);
}