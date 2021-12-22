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

	// ���� ����
	if (Input::GetButtonDown('W'))
	{
		_prevPos = _owner->GetPosition();

		_gravity = 500.0f;
		pos.y -= static_cast<LONG>(_gravity * Timer::GetDeltaTime());
	}

	// ���� ��
	if (anim->GetAnimName() == L"Jump") 
	{
		animator->SetIsMovable(false);
		pos.y -= static_cast<LONG>(_gravity * Timer::GetDeltaTime());
		_gravity -= _velocity * Timer::GetDeltaTime();

		_postPos.y -= static_cast<LONG>(_gravity * Timer::GetDeltaTime()); // ���� ��ġ �̸� ���
	}

	// �����ִϸ��̼� ����
	if (pos.y >= _prevPos.y && anim->GetIsAnimEnd() && anim->GetAnimName() == L"Jump")
	{
		pos.y = _prevPos.y;
		animator->SetIsMovable(true);
		animator->SetOnGround(true);
	}

	if (Input::GetButton('S'))
	{
		
	}

	// ���� �̵�
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

	// ������ �̵�

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

	// �޸��� ���� �� ����
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

	// �ൿ ���� �� Idle
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
