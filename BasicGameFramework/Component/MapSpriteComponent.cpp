#include "stdafx.h"
#include "MapSpriteComponent.h"
#include "Object/GameObject.h"
#include "../Util/Input.h"
#include "../Util/Timer.h"

#include <iostream>

void MapSpriteComponent::Update()
{
	

	if (Input::GetButton('A'))
	{
		if (g_isMapEnd == false)
		{
			x -= static_cast<LONG>(cameraSpeed * Timer::GetDeltaTime());
		}

		if (x <= 0)
		{
			x = 0;

			if (isStandard)
			{
				g_isMapEnd = true;
			}
		}
	}

	if (Input::GetButton('D'))
	{
		if (g_isMapEnd == false)
		{
			x += static_cast<LONG>(cameraSpeed * Timer::GetDeltaTime());
		}

		if (x >= _owner->GetWidth() - printWidth - 2)
		{
			x = _owner->GetWidth() - printWidth - 2;

			if (isStandard)
			{
				g_isMapEnd = true;
			}
		}
	}
}

void MapSpriteComponent::Render(HDC hdc)
{
	img->MapRender(hdc, x, y, printWidth, printHeight, scale);
}

void MapSpriteComponent::SetImage(const wchar_t* fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	img = ImageManager::GetInstance()->FindImage(fileName, width, height, 1, 1, isTrans, transColor);
}

void MapSpriteComponent::SetScale(float scale)
{
	this->scale = scale;
}

void MapSpriteComponent::SetCameraSpeed(int speed)
{
	cameraSpeed = speed;
}

void MapSpriteComponent::SetCoordinate(int x, int y)
{
	this->x = x;
	this->y = y;
}

void MapSpriteComponent::SetX(int x)
{
	this->x = x;
}

void MapSpriteComponent::SetY(int y)
{
	this->y = y;
}

void MapSpriteComponent::SetWidth(int width)
{
	printWidth = width;
}

void MapSpriteComponent::SetHeight(int height)
{
	printHeight = height;
}

void MapSpriteComponent::SetStandard(bool state)
{
	isStandard = state;
}

int MapSpriteComponent::GetX()
{
	return x;
}
