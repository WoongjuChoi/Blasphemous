#include "stdafx.h"
#include "TitlePenitentOneAnim.h"
#include "../Component/AnimationComponent.h"

void TitlePenitentOneAnim::Init()
{
	SetSize(519, 360);
	AnimationComponent* backgroundImg = new AnimationComponent(this);
	backgroundImg->SetImage(L"Image/mainMenu/MainMenuPenitent-anim.bmp", GetWidth(), GetHeight(), 22, 1, true, RGB(255, 0, 255));
	backgroundImg->SetAnimSpeed(10);
	backgroundImg->SetScale(2.0f);
	SetPivot(Pivot::LeftTop);
}