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
	if (anim->GetIsAnimEnd() && (anim->GetAnimName() == L"RunStop" || anim->GetAnimName() == L"Attack") && anim->GetIsReverse() == true)
	{
		isMovable = true;

		anim->SetFrameX(0);
		anim->SetAnim(L"Idle");
		anim->SetIsLoop(true);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(6);

		isMovable = true;
	}

	if (anim->GetIsAnimEnd() && (anim->GetAnimName() == L"RunStop" || anim->GetAnimName() == L"Attack") && anim->GetIsReverse() == false)
	{
		isMovable = true;

		anim->SetFrameX(0);
		anim->SetAnim(L"Idle");
		anim->SetIsLoop(true);
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

	// ���� �� ������ �Է�
	if (Input::GetButton('D') && isMovable == false && (anim->GetAnimName() == L"Jump" || anim->GetAnimName() == L"JumpForward"))
	{
		anim->SetAnim(L"JumpForward");
		anim->SetIsLoop(false);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(7);
	}

	// �������� �����ִ� ���¿��� ���ڸ� �����ִϸ��̼� ����
	if (isOnGround && anim->GetIsAnimEnd() && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == false)
	{
		isMovable = true;
		anim->SetIsLoop(false);
		anim->SetAnim(L"RunStop");
		anim->SetFrameX(0);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(4);
	}

	// �������� �����ִ� ���¿��� ���� �����ִϸ��̼� ����
	if (Input::GetButton('D') && isOnGround && anim->GetIsAnimEnd() && anim->GetAnimName() == L"JumpForward" && anim->GetIsReverse() == false)
	{
		isMovable = true;
		anim->SetAnim(L"Running");
		anim->SetIsLoop(true);
		anim->SetFrameX(0);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(4);
	}

	if (isOnGround && anim->GetIsAnimEnd() && anim->GetAnimName() == L"JumpForward" && anim->GetIsReverse() == false)
	{
		isMovable = true;
		anim->SetAnim(L"RunStop");
		anim->SetIsLoop(true);
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

	// ���� �� ���� �Է�
	if (Input::GetButton('A') && isMovable == false && (anim->GetAnimName() == L"Jump" || anim->GetAnimName() == L"JumpForward"))
	{
		anim->SetAnim(L"JumpForward");
		anim->SetIsLoop(false);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(7);
	}

	// ������ �����ִ� ���¿��� ���ڸ� �����ִϸ��̼� ����
	if (isOnGround && anim->GetIsAnimEnd() && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == true)
	{
		isMovable = true;
		anim->SetAnim(L"RunStop");
		anim->SetIsLoop(false);
		anim->SetFrameX(0);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(4);
	}

	// ������ �����ִ� ���¿��� ���� �����ִϸ��̼� ����
	if (Input::GetButton('A') && isOnGround && anim->GetIsAnimEnd() && anim->GetAnimName() == L"JumpForward" && anim->GetIsReverse() == true)
	{
		isMovable = true;
		anim->SetAnim(L"Running");
		anim->SetIsLoop(true);
		anim->SetFrameX(0);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(4);
	}

	if (isOnGround && anim->GetIsAnimEnd() && anim->GetAnimName() == L"JumpForward" && anim->GetIsReverse() == true)
	{
		isMovable = true;
		anim->SetAnim(L"RunStop");
		anim->SetIsLoop(false);
		anim->SetFrameX(0);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(4);
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

	// ����
	// ù ���ݽ�
	if (Input::GetButtonDown('K') && anim->GetIsReverse() == false && anim->GetAnimName() != L"Attack") // ������
	{
		isMovable = false;

		anim->SetAnim(L"Attack");
		anim->SetIsLoop(false);
		anim->SetFrameX(0);
		//anim->SetMaxFrameX(6);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(4);
	}

	if (anim->GetFrameX() == 4 && anim->GetAnimName() != L"Attack" && anim->GetIsReverse() == false)
	{
		
	}

	if (Input::GetButtonDown('K') && anim->GetIsReverse() == true && anim->GetAnimName() != L"Attack") // ����
	{
		isMovable = false;

		anim->SetAnim(L"Attack");
		anim->SetIsLoop(false);
		anim->SetFrameX(0);
		//anim->SetMaxFrameX(6);
		anim->SetIsReverse(true);
		anim->SetAnimSpeed(4);
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
