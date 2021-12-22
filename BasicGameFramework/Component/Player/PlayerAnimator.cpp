#include "stdafx.h"
#include "PlayerAnimator.h"

#include "../../Object/GameObject.h"
#include "../../Util/Input.h"
#include "../../Util/Timer.h"

#include "../AnimationComponent.h"


void PlayerAnimator::Update()
{
	auto anim = _owner->GetComponent<AnimationComponent>();

	// �ൿ ���� �� Idle
	if (anim->GetIsAnimEnd() && anim->GetAnimName() == L"RunStop" && anim->GetIsReverse() == true)
	{
		isMovable = true;

		anim->SetAnim(L"Idle");
		anim->SetIsLoop(true);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(6);

		isMovable = true;
	}

	if (anim->GetIsAnimEnd() && anim->GetAnimName() == L"RunStop" && anim->GetIsReverse() == false)
	{
		isMovable = true;

		anim->SetAnim(L"Idle");
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(6);

		isMovable = true;
	}

	// ����
	// �������� �����ִ� ���¿��� ���� ����
	if (Input::GetButtonDown('W') && anim->GetIsReverse() == false && isMovable == true)
	{
		isMovable = false;
		isOnGround = false;

		anim->SetAnim(L"Jump");
		anim->SetIsLoop(false);
		anim->SetFrameX(0);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(10);
	}

	// �������� �����ִ� ���¿��� ���� ��
	if (isMovable == false && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == false)
	{
	}

	// �������� �����ִ� ���¿��� �����ִϸ��̼� ����
	if (isOnGround && anim->GetIsAnimEnd() && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == false)
	{
		isMovable = true;
		anim->SetIsLoop(false);
		anim->SetAnim(L"RunStop");
		anim->SetFrameX(0);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(4);
	}

	// ������ �����ִ� ���¿��� ���� ����
	if (Input::GetButtonDown('W') && anim->GetIsReverse() == true && isMovable == true)
	{
		isMovable = false;
		isOnGround = false;

		anim->SetAnim(L"Jump");
		anim->SetIsLoop(false);
		anim->SetFrameX(0);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(10);
	}

	// ������ �����ִ� ���¿��� ���� ��
	if (isMovable == false && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == true)
	{
	}

	// ������ �����ִ� ���¿��� �����ִϸ��̼� ����
	if (isOnGround && anim->GetIsAnimEnd() && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == true)
	{
		isMovable = true;
		anim->SetAnim(L"RunStop");
		anim->SetIsLoop(false);
		anim->SetFrameX(0);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(4);
	}

	if (Input::GetButton('S'))
	{

	}

	// ���� �̵�
	if (Input::GetButtonDown('A'))
	{
		if (isMovable)
		{
			anim->SetAnim(L"RunStart");
			anim->SetIsLoop(false);
			anim->SetFrameX(0);
			anim->SetIsReverse(true);
			anim->SetAnimSpeed(4);
		}
	}

	if (Input::GetButton('A'))
	{
		if (anim->GetIsAnimEnd() == true && anim->GetAnimName() == L"RunStart" && isMovable)
		{
			anim->SetAnim(L"Running");
			anim->SetIsLoop(true);
			anim->SetIsReverse(true);
			anim->SetAnimSpeed(4);
		}

	}

	if (Input::GetButtonUp('A') && isMovable)
	{
		if (anim->GetAnimName() == L"Running" || anim->GetAnimName() == L"RunStart")
		{
			anim->SetAnim(L"RunStop");
			anim->SetIsLoop(false);
			anim->SetFrameX(0);
			anim->SetIsReverse(true);
			anim->SetAnimSpeed(4);
		}
	}


	// ������ �̵�
	if (Input::GetButtonDown('D'))
	{
		if (isMovable)
		{
			anim->SetAnim(L"RunStart");
			anim->SetIsLoop(false);
			anim->SetFrameX(0);
			anim->SetIsReverse(false);
			anim->SetAnimSpeed(4);
		}
	}

	if (Input::GetButton('D'))
	{
		if (anim->GetIsAnimEnd() == true && anim->GetAnimName() == L"RunStart" && isMovable)
		{
			anim->SetAnim(L"Running");
			anim->SetIsLoop(true);
			anim->SetIsReverse(false);
			anim->SetAnimSpeed(4);
		}
	}

	if (Input::GetButtonUp('D') && isMovable)
	{
		if (anim->GetAnimName() == L"Running" || anim->GetAnimName() == L"RunStart")
		{
			anim->SetAnim(L"RunStop");
			anim->SetIsLoop(false);
			anim->SetIsReverse(false);
			anim->SetFrameX(0);
			anim->SetAnimSpeed(4);
		}
	}
}

bool PlayerAnimator::GetIsMovable()
{
	return isMovable;
}

void PlayerAnimator::SetIsMovable(bool state)
{
	isMovable = state;
}

void PlayerAnimator::SetOnGround(bool state)
{
	isOnGround = state;
}
