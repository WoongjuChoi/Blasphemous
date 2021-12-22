#include "stdafx.h"
#include "MapSpriteComponent.h"
#include "Object/GameObject.h"
#include "../Util/Input.h"
#include "../Util/Timer.h"

void MapSpriteComponent::Update()
{
	POINT pos = _owner->GetPosition();

	if (Input::GetButton('A'))
	{
		x -= static_cast<LONG>(cameraSpeed * Timer::GetDeltaTime());

		if (x <= 0)
		{
			x = 0;
			pos.x -= static_cast<LONG>(200 * Timer::GetDeltaTime());
			_owner->SetPosition(pos);
		}
	}

	if (Input::GetButton('D'))
	{
		x += static_cast<LONG>(cameraSpeed * Timer::GetDeltaTime());

		if (x >= _owner->GetWidth() - printWidth - 2)
		{
			x = _owner->GetWidth() - printWidth - 2;
			pos.x += static_cast<LONG>(200 * Timer::GetDeltaTime());
			_owner->SetPosition(pos);
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

void MapSpriteComponent::SetWidth(int width)
{
	printWidth = width;
}

void MapSpriteComponent::SetHeight(int height)
{
	printHeight = height;
}
