#pragma once

#include <string>
#include <vector>

#include "../IBehaviour.h"

class Scene;
class GameObject;

class Layer final : IBehaviour
{
public:
	Layer(Scene* scene, const std::wstring& tag, INT32 zOrder);
	virtual ~Layer();

	virtual void		Init() override;
	virtual void		Update() override;
	virtual void		PhysicsUpdate() override;
	virtual void		Render(HDC hdc) override;
	virtual void		Release() override;

	const Scene*		GetScene() const noexcept;
	std::wstring		GetTag() const noexcept;
	INT32				GetZOrder() const noexcept;

	void				AddObject(GameObject* obj);
	void				RemoveObject(const std::wstring& tag);
	GameObject*			FindObject(const std::wstring& tag);

	bool				IsCollision(GameObject* obj1, GameObject* obj2);
	void				PrintText(HDC hdc, LPCTSTR text, int posX, int posY);
	void				SetText(LPCTSTR text, int x, int y);

private:
	Scene*							_scene;
	INT32							_zOrder;
	std::wstring					_tag = L"";
	std::vector<GameObject*>		_objects;
	RECT							_tempRect = {0, 0};
	bool							_isFloorCollision = false;
	LPCTSTR							_text = nullptr;
	int								_x = 0;
	int								_y = 0;
};