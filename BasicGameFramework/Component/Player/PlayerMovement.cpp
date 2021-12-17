#include "PlayerMovement.h"
#include "../CircleComponent.h"

#include "../../Object/GameObject.h"
#include "../../Util/Input.h"
#include "../../Util/Timer.h"

#include "../AnimationComponent.h"

#include "stdafx.h"

void PlayerMovement::Update()
{
	POINT pos = _owner->GetPosition();
	auto anim = _owner->GetComponent<AnimationComponent>();

	// 점프
	if (Input::GetButtonDown('W') && anim->GetIsReverse() == false) // 왼쪽을 보고있는 상태에서 점프
	{
		isMovable = false;
		_speed = 500.0f;
		pos.y -= static_cast<LONG>(_speed * Timer::GetDeltaTime());

		anim->SetAnim(L"Jump");
		anim->SetFrameX(0);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(10);
	}

	if (anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == false) // 왼쪽을 보고있는 상태에서 점프
	{
		pos.y -= static_cast<LONG>(_speed * Timer::GetDeltaTime());
		_speed -= _gravity * Timer::GetDeltaTime();
	}

	if (anim->GetIsMaxFrame() && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == false) // 왼쪽을 보고있는 상태에서 점프애니메이션 종료
	{
		isMovable = true;
		anim->SetAnim(L"RunStop");
		anim->SetFrameX(0);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(4);
	}

	if (Input::GetButtonDown('W') && anim->GetIsReverse() == true) // 오른쪽을 보고있는 상태에서 점프
	{
		isMovable = false;
		_speed = 500.0f;
		pos.y -= static_cast<LONG>(_speed * Timer::GetDeltaTime());

		anim->SetAnim(L"Jump");
		anim->SetFrameX(0);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(10);
	}

	if (anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == true) // 오른쪽을 보고있는 상태에서 점프
	{
		pos.y -= static_cast<LONG>(_speed * Timer::GetDeltaTime());
		_speed -= _gravity * Timer::GetDeltaTime();
	}

	if (anim->GetIsMaxFrame() && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == true) // 오른쪽을 보고있는 상태에서 점프애니메이션 종료
	{
		isMovable = true;
		anim->SetAnim(L"RunStop");
		anim->SetFrameX(0);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(4);
	}

	if (Input::GetButton('S'))
	{
		
	}

	// 왼쪽 이동
	if (Input::GetButtonDown('A') && isMovable)
	{
		SetSpeed(200.0f);
		pos.x -= static_cast<LONG>(_speed * Timer::GetDeltaTime());

		anim->SetAnim(L"RunStart");
		anim->SetFrameX(0);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(4);
	}

	if (Input::GetButton('A') && isMovable)
	{
		pos.x -= static_cast<LONG>(_speed * Timer::GetDeltaTime());

		if (anim->GetIsMaxFrame() == true && anim->GetAnimName() == L"RunStart")
		{
			anim->SetAnim(L"Running");
			anim->SetIsReverse(true);
			anim->SetAnimSpeed(4);
		}
		
	}

	if (Input::GetButtonUp('A') && isMovable)
	{
		pos.x -= static_cast<LONG>(_speed * Timer::GetDeltaTime());

		if (anim->GetAnimName() == L"Running" || anim->GetAnimName() == L"RunStart")
		{
			anim->SetAnim(L"RunStop");
			anim->SetFrameX(0);
			anim->SetIsReverse(true);
			anim->SetAnimSpeed(4);
		}
	}


	// 오른쪽 이동
	if (Input::GetButtonDown('D') && isMovable)
	{
		SetSpeed(200.0f);
		pos.x -= static_cast<LONG>(_speed * Timer::GetDeltaTime());

		anim->SetAnim(L"RunStart");
		anim->SetFrameX(0);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(4);
	}

	if (Input::GetButton('D') && isMovable)
	{
		pos.x += static_cast<LONG>(_speed * Timer::GetDeltaTime());

		if (anim->GetIsMaxFrame() == true && anim->GetAnimName() == L"RunStart")
		{
			anim->SetAnim(L"Running");
			anim->SetIsReverse(false);
			anim->SetAnimSpeed(4);
		}
	}

	if (Input::GetButtonUp('D') && isMovable)
	{
		pos.x -= static_cast<LONG>(_speed * Timer::GetDeltaTime());

		if (anim->GetAnimName() == L"Running" || anim->GetAnimName() == L"RunStart")
		{
			anim->SetAnim(L"RunStop");
			anim->SetIsReverse(false);
			anim->SetFrameX(0);
			anim->SetAnimSpeed(4);
		}
	}

	// 달리기 멈춘 후 관성
	if (anim->GetIsMaxFrame() == false && anim->GetAnimName() == L"RunStop" && anim->GetIsReverse() == true)
	{
		pos.x -= static_cast<LONG>(_speed * Timer::GetDeltaTime());
		_speed -= _inertia * Timer::GetDeltaTime();
		anim->SetIsReverse(true);
	}

	if (anim->GetIsMaxFrame() == false && anim->GetAnimName() == L"RunStop" && anim->GetIsReverse() == false)
	{
		pos.x += static_cast<LONG>(_speed * Timer::GetDeltaTime());
		_speed -= _inertia * Timer::GetDeltaTime();
		anim->SetIsReverse(false);
	}

	// 행동 종료 후 Idle
	if (anim->GetIsMaxFrame() && anim->GetAnimName() == L"RunStop" && anim->GetIsReverse() == true)
	{
		isMovable = true;

		anim->SetAnim(L"Idle");
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(6);

		SetSpeed(200.0f);
		isMovable = true;
	}
	
	if (anim->GetIsMaxFrame() && anim->GetAnimName() == L"RunStop" && anim->GetIsReverse() == false)
	{
		isMovable = true;

		anim->SetAnim(L"Idle");
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(6);

		SetSpeed(200.0f);
		isMovable = true;
	}

	_owner->SetPosition(pos);
}

void PlayerMovement::SetSpeed(float speed) noexcept
{
	_speed = speed;
}

void PlayerMovement::SetLoop(bool loopInfo) noexcept
{
	isLoop = loopInfo;
}

float PlayerMovement::GetSpeed() const noexcept
{
	return _speed;
}
