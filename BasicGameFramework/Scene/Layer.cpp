#include "Layer.h"
#include "Scene.h"

#include "stdafx.h"
#include "../Object/GameObject.h"

#include "../Component/HitBoxComponent.h"

Layer::Layer(Scene* scene, const std::wstring& tag, INT32 zOrder)
	:
	_scene(scene),
	_tag { tag },
	_zOrder{ zOrder }
{
	_scene->AddLayer(this);
}

Layer::~Layer()
{
	for (auto& obj : _objects)
	{
		delete obj;
		obj = nullptr;
	}
	_objects.clear();
}

void Layer::Init()
{
	for (GameObject* _object : _objects)
	{
		_object->Init();
	}
}

void Layer::Update()
{
	for (GameObject* _object : _objects)
	{
		_object->Update();
	}
}

void Layer::PhysicsUpdate()
{
	for (GameObject* _object : _objects)
	{
		_object->PhysicsUpdate();
	}
}

void Layer::Render(HDC hdc)
{
	for (GameObject* _object : _objects)
	{
		_object->Render(hdc);
	}

	if (_text != nullptr)
	{
		PrintText(hdc, _text, _x, _y);
	}
}

void Layer::Release()
{
	for (GameObject* _object : _objects)
	{
		_object->Release();
	}
}

const Scene* Layer::GetScene() const noexcept
{
	return _scene;
}

std::wstring Layer::GetTag() const noexcept
{
	return _tag;
}

INT32 Layer::GetZOrder() const noexcept
{
	return _zOrder;
}

void Layer::AddObject(GameObject* obj)
{
	_objects.push_back(obj);
}

void Layer::RemoveObject(const wstring& tag)
{
	remove_if(_objects.begin(), _objects.end(),
		[&tag](const GameObject* obj)
		{
			return obj->GetTag() == tag;
		});
}

GameObject* Layer::FindObject(const std::wstring& tag)
{
	auto iter = find_if(_objects.begin(), _objects.end(),
		[&tag](const GameObject* obj)
		{
			return obj->GetTag() == tag;
		});

	if (iter == _objects.end())
	{
		return nullptr;
	}
	else
	{
		return *iter;
	}
}

bool Layer::IsCollision(GameObject* obj1, GameObject* obj2)
{
	RECT* rect1 = obj1->GetComponent<HitBoxComponent>()->GetRect();
	RECT* rect2 = obj2->GetComponent<HitBoxComponent>()->GetRect();

	return IntersectRect(&_tempRect, rect1, rect2);
}

void Layer::PrintText(HDC hdc, LPCTSTR text, int posX, int posY)
{
	HFONT font, oldfont;
	SetBkMode(hdc, 1);
	SetTextColor(hdc, RGB(0, 0, 0));
	font = CreateFont(
		50,          // 폰트의 높이
		0,          // 폰트의 폭
		0,          // 폰트의 각도
		0,          // 각 글자의 각도
		1,          // 폰트의 두꺠
		0,          // 기울임체
		0,          // 밑줄
		0,          // 관통성
		0,          // 문자셋
		0,          // 출력정확도
		0,          // 클리핑 정확도
		0,          // 논리적 폰트(?)
		0,          // 폰트의 피치와 그룹
		L"돋음");        // 글꼴
	oldfont = (HFONT)SelectObject(hdc, font);
	TextOut(hdc, posX - 1, posY, text, lstrlen(text)); // 텍스트 테두리 출력 
	TextOut(hdc, posX + 1, posY, text, lstrlen(text)); // 텍스트 테두리 출력 
	TextOut(hdc, posX, posY - 1, text, lstrlen(text)); // 텍스트 테두리 출력 
	TextOut(hdc, posX, posY + 1, text, lstrlen(text)); // 텍스트 테두리 출력 
	SetTextColor(hdc, RGB(255, 255, 255));
	TextOut(hdc, posX, posY, text, lstrlen(text)); // 텍스트 출력 
	SelectObject(hdc, oldfont);
	DeleteObject(font);
}

void Layer::SetText(LPCTSTR text, int x, int y)
{
	_text = text;
	_x = x;
	_y = y;
}
