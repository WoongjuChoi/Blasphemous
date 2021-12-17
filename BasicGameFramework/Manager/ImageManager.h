#pragma once
#include "../Util/Singleton.h"

#include <string>
#include <unordered_map>

class Image;
class ImageManager : public Singleton<ImageManager>
{
private:
	std::unordered_map<std::wstring, Image*>	mapImages;

public:
	void Init();
	void Release();

	virtual ~ImageManager() { Release(); }

	Image* AddImage(const wchar_t* fileName, int width = 0, int height = 0, int maxFrameX = 0, int maxFrameY = 0, bool isTrans = false, COLORREF transColor = NULL);

	Image* FindImage(const wchar_t* fileName, int width = 0, int height = 0, int maxFrameX = 0, int maxFrameY = 0, bool isTrans = false, COLORREF transColor = NULL);

	void DeleteImage(const wchar_t* fileName);
};

