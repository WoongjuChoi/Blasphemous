#pragma once
#include "Component.h"
#include "Image.h"
#include "../Manager/ImageManager.h"

class MapSpriteComponent : public Component
{
public:
	using Component::Component;
	virtual ~MapSpriteComponent() noexcept = default;

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetImage(const wchar_t* fileName, int width = 0, int height = 0, bool isTrans = false, COLORREF transColor = NULL);

	void SetScale(float scale = 1.0f);
	void SetCameraSpeed(int speed);
	void SetCoordinate(int x, int y);
	void SetX(int x);
	void SetY(int y);
	void SetWidth(int width);
	void SetHeight(int height);
	void SetStandard(bool state);

	int  GetX();

private:
	Image* img = nullptr;
	float  scale = 1.0f;
	int  cameraSpeed = 100;
	int	   x = 0;
	int	   y = 0;
	int    printWidth = 1000;
	int	   printHeight = 300;
	bool   isStandard = false;
};

