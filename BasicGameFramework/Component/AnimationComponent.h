#pragma once
#include "Component.h"
#include "Image.h"
#include "../Manager/ImageManager.h"

#include <string>
#include <unordered_map>

class AnimationComponent : public Component
{
public:
	using Component::Component;
	virtual ~AnimationComponent() noexcept = default;

	struct AnimInfo
	{
		const wchar_t* fileName;
		int width = 0;
		int height = 0;
		int maxFrameX = 1;
		int maxFrameY = 1;
		bool isTrans = false;
		COLORREF transColor = NULL;
	};

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void AddAnimation(std::wstring animName, const wchar_t* fileName, int = 0, int height = 0, int maxFrameX = 1, int maxFrameY = 1, bool isTrans = false, COLORREF transColor = NULL);

	void SetImage(const wchar_t* fileName, int width = 0, int height = 0, int maxFrameX = 1, int maxFrameY = 1, bool isTrans = false, COLORREF transColor = NULL);
	void SetImage(AnimInfo info);
	void SetAnim(std::wstring animName);
	void SetIsReverse(bool reverse);
	void SetIsLoop(bool state);

	void SetScale(float scale = 1.0f);
	void SetFrameX(int x);
	void SetFrameY(int y);
	void SetAnimSpeed(int speed);

	bool GetIsAnimEnd();
	bool GetIsReverse();
	std::wstring GetAnimName();

private:
	Image* img = nullptr;
	int elapsedCount = 0;
	int frameX = 0;
	int frameY = 0;
	int animSpeed = 6;
	float scale = 1.0f;
	bool isAnimEnd = false;
	bool isLoop = true;
	std::unordered_map<std::wstring, AnimInfo> animations;
	std::wstring _animName;
};

