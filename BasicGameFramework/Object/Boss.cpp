#include "stdafx.h"
#include "Boss.h"

#include "../Component/AnimationComponent.h"
#include "../Component/HitBoxComponent.h"

void Boss::Init()
{
	SetPivot(Pivot::Center);

	SetSize(550, 220);

	HitBoxComponent* hitBox = new HitBoxComponent(this, 2);
	hitBox->SetSize(70, 120);
	//hitBox->SetPos(_position.x, _position.y);

	AnimationComponent* boss = new AnimationComponent(this);
	boss->AddAnimation(L"BossIdle", L"Image/Boss/bossIdle.bmp", GetWidth(), GetHeight(), 10, 1, true, RGB(255, 0, 255));

	boss->SetAnim(L"BossIdle");
	boss->SetCameraSpeed(350);
	boss->SetScale(2.0f);

	GameObject::Init();
}
