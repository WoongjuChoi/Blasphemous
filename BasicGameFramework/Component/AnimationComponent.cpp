#include "stdafx.h"
#include "AnimationComponent.h"
#include "Object/GameObject.h"


void AnimationComponent::Update()
{
	isMaxFrame = (img->GetMaxFrameX() - 1 == frameX) ? true : false;

	elapsedCount++;
	if (elapsedCount >= animSpeed)
	{
		frameX++;
		if (frameX >= img->GetMaxFrameX())
		{
			frameX = 0;
		}

		elapsedCount = 0;
	}
}

void AnimationComponent::Render(HDC hdc)
{
	auto pos = _owner->GetRenderPos();
	img->Render(hdc, pos.x, pos.y, frameX, frameY, scale);
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

void AnimationComponent::SetAnimSpeed(int speed)
{
	animSpeed = speed;
}

bool AnimationComponent::GetIsMaxFrame()
{
	return isMaxFrame;
}

bool AnimationComponent::GetIsReverse()
{
	return img->GetIsReverse();
}

std::wstring AnimationComponent::GetAnimName()
{
	return std::wstring(_animName);
}
