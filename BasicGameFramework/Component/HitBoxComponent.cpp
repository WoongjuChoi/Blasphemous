#include "stdafx.h"
#include "HitBoxComponent.h"
#include "../Object/GameObject.h"


void HitBoxComponent::Update()
{
	POINT newPos = _owner->GetRenderPos();

	POINT pos = { newPos.x + _pos.x, newPos.y + _pos.y };

	_rect.left = pos.x;
	_rect.top = pos.y;
	_rect.right = pos.x + _width;
	_rect.bottom = pos.y + _height;
}

void HitBoxComponent::Render(HDC hdc)
{
	MoveToEx(hdc, _rect.left, _rect.top, NULL);
	LineTo(hdc, _rect.left, _rect.bottom);
	LineTo(hdc, _rect.right, _rect.bottom);
	LineTo(hdc, _rect.right, _rect.top);
	LineTo(hdc, _rect.left, _rect.top);
}

void HitBoxComponent::SetSize(int width, int height) noexcept
{
	_width = width;
	_height = height;
}

void HitBoxComponent::SetPos(float x, float y)
{
	_pos.x = x;
	_pos.y = y;
}

RECT* HitBoxComponent::GetRect() noexcept
{
	return &_rect;
}
