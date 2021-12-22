#include "stdafx.h"
#include "BrotherhoodBackground.h"
#include "../Component/AnimationComponent.h"

void BrotherhoodBackground::Init()
{
	SetSize(1280, 720);
	AnimationComponent* backgroundImg = new AnimationComponent(this);
	backgroundImg->SetImage(L"Image/brotherhood/brotherhood_background.bmp", GetWidth(), GetHeight());

	SetPivot(Pivot::LeftTop);
}