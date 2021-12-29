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
		50,          // ��Ʈ�� ����
		0,          // ��Ʈ�� ��
		0,          // ��Ʈ�� ����
		0,          // �� ������ ����
		1,          // ��Ʈ�� �΃�
		0,          // �����ü
		0,          // ����
		0,          // ���뼺
		0,          // ���ڼ�
		0,          // �����Ȯ��
		0,          // Ŭ���� ��Ȯ��
		0,          // ���� ��Ʈ(?)
		0,          // ��Ʈ�� ��ġ�� �׷�
		L"����");        // �۲�
	oldfont = (HFONT)SelectObject(hdc, font);
	TextOut(hdc, posX - 1, posY, text, lstrlen(text)); // �ؽ�Ʈ �׵θ� ��� 
	TextOut(hdc, posX + 1, posY, text, lstrlen(text)); // �ؽ�Ʈ �׵θ� ��� 
	TextOut(hdc, posX, posY - 1, text, lstrlen(text)); // �ؽ�Ʈ �׵θ� ��� 
	TextOut(hdc, posX, posY + 1, text, lstrlen(text)); // �ؽ�Ʈ �׵θ� ��� 
	SetTextColor(hdc, RGB(255, 255, 255));
	TextOut(hdc, posX, posY, text, lstrlen(text)); // �ؽ�Ʈ ��� 
	SelectObject(hdc, oldfont);
	DeleteObject(font);
}

void Layer::SetText(LPCTSTR text, int x, int y)
{
	_text = text;
	_x = x;
	_y = y;
}
