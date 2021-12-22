#include "stdafx.h"
#include "PlayerAnimator.h"

#include "../../Object/GameObject.h"
#include "../../Util/Input.h"
#include "../../Util/Timer.h"

#include "../AnimationComponent.h"


void PlayerAnimator::Update()
{
	auto anim = _owner->GetComponent<AnimationComponent>();

	// 행동 종료 후 Idle
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

	// 점프
	// 오른쪽을 보고있는 상태에서 점프 시작
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

	// 오른쪽을 보고있는 상태에서 점프 중
	if (isMovable == false && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == false)
	{
	}

	// 오른쪽을 보고있는 상태에서 점프애니메이션 종료
	if (isOnGround && anim->GetIsAnimEnd() && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == false)
	{
		isMovable = true;
		anim->SetIsLoop(false);
		anim->SetAnim(L"RunStop");
		anim->SetFrameX(0);
		anim->SetIsReverse(false);
		anim->SetAnimSpeed(4);
	}

	// 왼쪽을 보고있는 상태에서 점프 시작
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

	// 왼쪽을 보고있는 상태에서 점프 중
	if (isMovable == false && anim->GetAnimName() == L"Jump" && anim->GetIsReverse() == true)
	{
	}

	// 왼쪽을 보고있는 상태에서 점프애니메이션 종료
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

	// 왼쪽 이동
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


	// 오른쪽 이동
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
