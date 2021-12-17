#include "stdafx.h"
#include "HitBoxComponent.h"
#include "../Object/GameObject.h"


void HitBoxComponent::Update()
{
	POINT newPos = _owner->GetRenderPos();
	Size size = _owner->GetSize();
	Pivot pivot = _owner->GetPivot();

	POINT temp = { _width * pivot.X, _height * pivot.Y };

	POINT pos = { newPos.x - temp.x, newPos.y - temp.y };

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

RECT* HitBoxComponent::GetRect() noexcept
{
	return &_rect;
}
