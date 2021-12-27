#include "stdafx.h"
#include "AnimationComponent.h"
#include "../Util/Timer.h"

#include "Object/GameObject.h"
#include <iostream>

void AnimationComponent::Update()
{
	// 애니메이션 재생
	isAnimEnd = (img->GetMaxFrameX() - 1 == frameX) ? true : false;

	elapsedCount++;
	if (elapsedCount >= animSpeed)
	{
		frameX++;
		if (frameX >= img->GetMaxFrameX())
		{
			if (isLoop == true)
			{
				frameX = 0;
			}
			else
			{
				frameX--;
			}
		}


		elapsedCount = 0;
	}

	// 플레이어가 아닌 오브젝트 카메라 이동
	if (isPlayer == false)
	{
		if (Input::GetButton('A'))
		{
			if (g_isMapEnd == false)
			{
				x = _owner->GetX();
				x += static_cast<LONG>(cameraSpeed * Timer::GetDeltaTime());
				_owner->SetX(x);
			}

			//if (x <= 10)
			//{
			//	x = 10;
			//}
		}

		if (Input::GetButton('D'))
		{
			if (g_isMapEnd == false)
			{
				x = _owner->GetX();
				x -= static_cast<LONG>(cameraSpeed * Timer::GetDeltaTime());
				_owner->SetX(x);
			}

			/*if (x >= 1260)
			{
				x = 1260;
			}*/
		}

		cout << "Boss X : " << x << endl;
	}
}

void AnimationComponent::Render(HDC hdc)
{
	auto pos = _owner->GetRenderPos();

	if (_animName == L"Attack")
	{
		img->Render(hdc, pos.x - 75, pos.y, frameX, frameY, scale);
	}
	else
	{
		img->Render(hdc, pos.x, pos.y, frameX, frameY, scale);
	}
}

void AnimationComponent::AddAnimation(wstring animName, const wchar_t* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{
	AnimInfo info;
	info.fileName = fileName;
	info.width = width;
	info.height = height;
	info.maxFrameX = maxFrameX;
	info.maxFrameY = maxFrameY;
	info.isTrans = isTrans;
	info.transColor = transColor;

	animations.insert({ animName , info });
}

void AnimationComponent::SetImage(const wchar_t* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{
	img = ImageManager::GetInstance()->FindImage(fileName, width * maxFrameX, height * maxFrameY, maxFrameX, maxFrameY, isTrans, transColor);
}

void AnimationComponent::SetImage(AnimInfo info)
{
	img = ImageManager::GetInstance()->FindImage(info.fileName, info.width * info.maxFrameX, info.height * info.maxFrameY, info.maxFrameX, info.maxFrameY, info.isTrans, info.transColor);
}

void AnimationComponent::SetAnim(wstring animName)
{
	_animName = animName;
	SetImage(animations[animName]);
}

void AnimationComponent::SetIsReverse(bool reverse)
{
	img->SetIsReverse(reverse);
}

void AnimationComponent::SetIsLoop(bool state)
{
	isLoop = state;
}

void AnimationComponent::SetScale(float scale)
{
	this->scale = scale;
}

void AnimationComponent::SetFrameX(int x)
{
	frameX = x;
}

void AnimationComponent::SetFrameY(int y)
{
	frameY = y;
}

void AnimationComponent::SetMaxFrameX(int x)
{
	img->SetMaxFrameX(x);
}

void AnimationComponent::SetAnimSpeed(int speed)
{
	animSpeed = speed;
}

void AnimationComponent::SetCameraSpeed(int speed)
{
	cameraSpeed = speed;
}

void AnimationComponent::SetIsPlayer(bool state)
{
	isPlayer = state;
}

int AnimationComponent::GetFrameX()
{
	return img->GetCurrFrameX();
}

bool AnimationComponent::GetIsAnimEnd()
{
	return isAnimEnd;
}

bool AnimationComponent::GetIsReverse()
{
	return img->GetIsReverse();
}

std::wstring AnimationComponent::GetAnimName()
{
	return std::wstring(_animName);
}
