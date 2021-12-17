#include "stdafx.h"
#include "TitleBackground.h"
#include "../Component/AnimationComponent.h"

void TitleBackground::Init()
{
	SetSize(1280, 720);
	AnimationComponent* backgroundImg = new AnimationComponent(this);
	backgroundImg->SetImage(L"Image/mainMenu/MainMenuBackground_0-side.bmp", GetWidth(), GetHeight());

	SetPivot(Pivot::LeftTop);
}
