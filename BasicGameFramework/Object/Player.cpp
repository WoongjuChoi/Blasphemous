#include "stdafx.h"
#include "Player.h"

#include "../Component/AnimationComponent.h"
#include "../Component/HitBoxComponent.h"
#include "../Component/Player/PlayerMovement.h"

void Player::Init()
{
	PlayerMovement* movement = new PlayerMovement(this, 1);
	movement->SetSpeed(200.0f);

	SetPivot(Pivot::Center);

	SetSize(250, 150);

	HitBoxComponent* hitBox = new HitBoxComponent(this, 2);
	hitBox->SetSize(250, 150);

	AnimationComponent* player = new AnimationComponent(this);
	player->AddAnimation(L"Idle", L"Image/player/idle.bmp", GetWidth(), GetHeight(), 13, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"RunStart", L"Image/player/runStart.bmp", GetWidth(), GetHeight(), 8, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"Running", L"Image/player/running.bmp", GetWidth(), GetHeight(), 14, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"RunStop", L"Image/player/runStop.bmp", GetWidth(), GetHeight(), 8, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"Jump", L"Image/player/jump.bmp", GetWidth(), GetHeight(), 5, 1, true, RGB(255, 0, 255));

	player->SetAnim(L"Idle");
	player->SetScale(1.6f);
}
