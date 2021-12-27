#include "stdafx.h"
#include "Player.h"

#include "../Component/AnimationComponent.h"
#include "../Component/HitBoxComponent.h"
#include "../Component/Player/PlayerMovement.h"
#include "../Component/Player/PlayerAnimator.h"

void Player::Init()
{
	PlayerMovement* movement = new PlayerMovement(this, 1);
	movement->SetSpeed(200.0f);

	SetPivot(Pivot::Center);

	SetSize(250, 150);

	HitBoxComponent* hitBox = new HitBoxComponent(this, 2);
	hitBox->SetSize(70, 120);
	hitBox->SetPos(160, 120);

	AnimationComponent* player = new AnimationComponent(this);
	player->AddAnimation(L"Idle", L"Image/player/idle.bmp", GetWidth(), GetHeight(), 13, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"RunStart", L"Image/player/runStart.bmp", GetWidth(), GetHeight(), 8, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"Running", L"Image/player/running.bmp", GetWidth(), GetHeight(), 14, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"RunStop", L"Image/player/runStop.bmp", GetWidth(), GetHeight(), 8, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"Jump", L"Image/player/jump.bmp", GetWidth(), GetHeight(), 5, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"JumpForward", L"Image/player/jumpForward.bmp", GetWidth(), GetHeight(), 13, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"Dodge", L"Image/player/dodge.bmp", GetWidth(), GetHeight(), 13, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"Attack", L"Image/player/attack.bmp", 350, GetHeight(), 28, 1, true, RGB(255, 0, 255));
	player->AddAnimation(L"AttackEffect", L"Image/player/attack_effect.bmp", GetWidth(), GetHeight(), 9, 1, true, RGB(255, 0, 255));

	player->SetAnim(L"Idle");
	player->SetScale(1.6f);
	player->SetIsPlayer(true);

	PlayerAnimator* animator = new PlayerAnimator(this);

	GameObject::Init();
}
