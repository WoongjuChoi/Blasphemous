#include "stdafx.h"
#include "PlayerMovement.h"
#include "../CircleComponent.h"

#include "../../Object/GameObject.h"
#include "../../Util/Input.h"
#include "../../Util/Timer.h"

#include "../AnimationComponent.h"
#include "PlayerAnimator.h"

#include <iostream>


void PlayerMovement::Update()
{
	POINT pos = _owner->GetPosition();
	PlayerAnimator* animator = _owner->GetComponent<PlayerAnimator>();
	auto anim = _owner->GetComponent<AnimationComponent>();
	Layer* playerLayer = _owner->GetLayer();

	// 점프 시작
	if (Input::GetButtonDown('W'))
	{
		_prevPos = _owner->GetPosition();

		_gravity = 500.0f;
		pos.y -= static_cast<LONG>(_gravity * Timer::GetDeltaTime());
	}

	// 점프 중
	if (anim->GetAnimName() == L"Jump") 
	{
		animator->SetIsMovable(false);
		pos.y -= static_cast<LONG>(_gravity * Timer::GetDeltaTime());
		_gravity -= _velocity * Timer::GetDeltaTime();

		_postPos.y -= static_cast<LONG>(_gravity * Timer::GetDeltaTime()); // 다음 위치 미리 계산
	}

	// 점프애니메이션 종료
	if (pos.y >= _prevPos.y && anim->GetIsAnimEnd() && anim->GetAnimName() == L"Jump")
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
		SetSpeed(200.0f);
		g_pos.x -= static_cast<LONG>(_speed * Timer::GetDeltaTime());

		if (pos.x > 500)
		{
			pos.x -= static_cast<LONG>(_speed * Timer::GetDeltaTime());
		}

		cout << "g_pos.x : " << g_pos.x << endl;
	}

	// 오른쪽 이동

	if (Input::GetButton('D'))
	{
		SetSpeed(200.0f);
		g_pos.x += static_cast<LONG>(_speed * Timer::GetDeltaTime());

		if (pos.x < 500)
		{
			pos.x += static_cast<LONG>(_speed * Timer::GetDeltaTime());
		}

		cout << "g_pos.x : " << g_pos.x << endl;
	}

	// 달리기 멈춘 후 관성
	if (anim->GetIsAnimEnd() == false && anim->GetAnimName() == L"RunStop" && anim->GetIsReverse() == true)
	{
		g_pos.x -= static_cast<LONG>(_speed * Timer::GetDeltaTime());
		_speed -= _inertia * Timer::GetDeltaTime();
		anim->SetIsReverse(true);

		if (anim->GetIsAnimEnd())
		{
			//isRunning = false;
		}
	}

	if (anim->GetIsAnimEnd() == false && anim->GetAnimName() == L"RunStop" && anim->GetIsReverse() == false)
	{
		g_pos.x += static_cast<LONG>(_speed * Timer::GetDeltaTime());
		_speed -= _inertia * Timer::GetDeltaTime();
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
