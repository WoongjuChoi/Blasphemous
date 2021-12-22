#include "stdafx.h"
#include "BrotherhoodBackground3.h"
#include "../Component/MapSpriteComponent.h"

void BrotherhoodBackground3::Init()
{
	SetSize(1280, 720);
	MapSpriteComponent* backgroundImg = new MapSpriteComponent(this);
	backgroundImg->SetImage(L"Image/brotherhood/brotherhood_background3.bmp", GetWidth(), GetHeight(), true, RGB(255, 0, 255));
	backgroundImg->SetCoordinate(200, 150);
	backgroundImg->SetCameraSpeed(120);
	backgroundImg->SetWidth(500);
	backgroundImg->SetHeight(500);

	SetPivot(Pivot::Center);
}