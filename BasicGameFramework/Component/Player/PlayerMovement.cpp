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

	// ����
	if (Input::GetButtonDown('W') && anim->GetIsReverse() == false) // ������ �����ִ� ���¿��� ����
	{
		isMovable = false;
		_speed = 500.0f;
		pos.y -= static_cast<LONG>(_speed * Timer::GetDeltaTime());

		anim->SetAnim(L"Jump");
		anim->SetFrameX(0);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(10);
	}

	if (anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == false) // ������ �����ִ� ���¿��� ����
	{
		pos.y -= static_cast<LONG>(_speed * Timer::GetDeltaTime());
		_speed -= _gravity * Timer::GetDeltaTime();
	}

	if (anim->GetIsMaxFrame() && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == false) // ������ �����ִ� ���¿��� �����ִϸ��̼� ����
	{
		isMovable = true;
		anim->SetAnim(L"RunStop");
		anim->SetFrameX(0);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(4);
	}

	if (Input::GetButtonDown('W') && anim->GetIsReverse() == true) // �������� �����ִ� ���¿��� ����
	{
		isMovable = false;
		_speed = 500.0f;
		pos.y -= static_cast<LONG>(_speed * Timer::GetDeltaTime());

		anim->SetAnim(L"Jump");
		anim->SetFrameX(0);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(10);
	}

	if (anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == true) // �������� �����ִ� ���¿��� ����
	{
		pos.y -= static_cast<LONG>(_speed * Timer::GetDeltaTime());
		_speed -= _gravity * Timer::GetDeltaTime();
	}

	if (anim->GetIsMaxFrame() && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == true) // �������� �����ִ� ���¿��� �����ִϸ��̼� ����
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

	// ���� �̵�
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


	// ������ �̵�
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

	// �޸��� ���� �� ����
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

	// �ൿ ���� �� Idle
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
