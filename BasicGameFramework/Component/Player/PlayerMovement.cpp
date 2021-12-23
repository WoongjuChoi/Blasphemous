#include "stdafx.h"
#include "PlayerMovement.h"
#include "../CircleComponent.h"

#include "../../Object/GameObject.h"
#include "../../Util/Input.h"
#include "../../Util/Timer.h"

#include "../AnimationComponent.h"
#include "PlayerAnimator.h"

#include <iostream>


void PlayerMovement::Init()
{
	_prevPos = _owner->GetPosition();
	animator = _owner->GetComponent<PlayerAnimator>();
	anim = _owner->GetComponent<AnimationComponent>();
}

void PlayerMovement::Update()
{
	POINT pos = _owner->GetPosition();

	// 점프 시작
	if (Input::GetButtonDown('W') && animator->GetIsMovable())
	{
		_gravity = 500.0f;
		pos.y -= static_cast<LONG>(_gravity * Timer::GetDeltaTime());
	}

	// 점프 중
	if (anim->GetAnimName() == L"Jump" || anim->GetAnimName() == L"JumpForward")
	{
		animator->SetIsMovable(false);
		pos.y -= static_cast<LONG>(_gravity * Timer::GetDeltaTime());
		_gravity -= _velocity * Timer::GetDeltaTime();
	}

	// 점프애니메이션 종료
	if (pos.y >= _prevPos.y && anim->GetIsAnimEnd() && anim->GetAnimName() == L"Jump")
	{
		pos.y = _prevPos.y;
		animator->SetIsMovable(true);
		animator->SetOnGround(true);
	}

	if (pos.y >= _prevPos.y && anim->GetAnimName() == L"JumpForward")
	{
		pos.y = _prevPos.y;
		animator->SetIsMovable(true);
		animator->SetOnGround(true);
	}

	if (Input::GetButton('S'))
	{
		
	}

	// 왼쪽 이동
	if (Input::GetButton('A'))
	{
		SetSpeed(240.0f);

		_inertia = 100.0f;

		if (pos.x < 0)
		{
			pos.x = 0;
		}

		if (pos.x > 510 || g_isMapEnd)
		{
			pos.x -= static_cast<LONG>(_speed * Timer::GetDeltaTime());

			if (480 < pos.x && pos.x < 520)
			{
				g_isMapEnd = false;
			}
		}
	}

	// 오른쪽 이동

	if (Input::GetButton('D'))
	{
		SetSpeed(240.0f);

		_inertia = 100.0f;

		if (pos.x > 1280)
		{
			pos.x = 1280;
		}

		if (pos.x < 490 || g_isMapEnd)
		{
			pos.x += static_cast<LONG>(_speed * Timer::GetDeltaTime());

			if (480 < pos.x && pos.x < 520)
			{
				g_isMapEnd = false;
			}
		}
	}

	// 달리기 멈춘 후 관성
	if (anim->GetIsAnimEnd() == false && anim->GetAnimName() == L"RunStop" && anim->GetIsReverse() == true)
	{
		if (pos.x > 510 || g_isMapEnd)
		{
			pos.x -= static_cast<LONG>(_inertia * Timer::GetDeltaTime());
			_inertia -= _inertia * Timer::GetDeltaTime();
		}
		else
		{
		/*	int x = map->GetX();
			x -= static_cast<LONG>(_inertia * Timer::GetDeltaTime());
			map->SetX(x);
			_inertia -= _inertia * Timer::GetDeltaTime();*/
		}


		anim->SetIsReverse(true);

		if (anim->GetIsAnimEnd())
		{
			//isRunning = false;
		}
	}

	if (anim->GetIsAnimEnd() == false && anim->GetAnimName() == L"RunStop" && anim->GetIsReverse() == false)
	{
		if (pos.x < 490 || g_isMapEnd)
		{
			pos.x += static_cast<LONG>(_inertia * Timer::GetDeltaTime());
			_inertia -= _inertia * Timer::GetDeltaTime();
		}
		else
		{
			/*int x = map->GetX();
			x += static_cast<LONG>(_inertia * Timer::GetDeltaTime());
			map->SetX(x);
			_inertia -= _inertia * Timer::GetDeltaTime();*/
		}
		
		anim->SetIsReverse(false);

		if (anim->GetIsAnimEnd())
		{
			//isRunning = false;
		}
	}

	// 행동 종료 후 Idle
	if (anim->GetIsAnimEnd() && anim->GetAnimName() == L"RunStop")
	{
		//isRunning = false;
		animator->SetIsMovable(true);
		SetSpeed(200.0f);
	}

	cout << "pos.x : " << pos.x << endl;
	_owner->SetPosition(pos);
}

void PlayerMovement::SetSpeed(float speed) noexcept
{
	_speed = speed;
}

float PlayerMovement::GetSpeed() const noexcept
{
	return _speed;
}
