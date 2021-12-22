#include "stdafx.h"
#include "ImageManager.h"
#include "Component/Image.h"

void ImageManager::Init()
{
}

void ImageManager::Release()
{
	for (auto& elem : mapImages)
	{
		SAFE_RELEASE(elem.second);
	}
	mapImages.clear();
}

 Image* ImageManager::AddImage(const wchar_t* fileName, int width, int height,	int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
 {
 	Image* img = new Image;
 	if (FAILED(img->Init(fileName, width, height, maxFrameX,
 		maxFrameY, isTrans, transColor)))
 	{
 		SAFE_RELEASE(img);
 		return nullptr;
 	}

 	mapImages.insert(make_pair(fileName, img));

 	return img;
 }

 Image* ImageManager::FindImage(const wchar_t* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
 {
 	unordered_map<wstring, Image*>::iterator it = mapImages.find(fileName);
 	if (it == mapImages.end())
 	{
 		return AddImage(fileName, width, height, maxFrameX, maxFrameY, isTrans, transColor);
 	}

 	return it->second;
 }

 void ImageManager::DeleteImage(const wchar_t* fileName)
 {
 	unordered_map<wstring, Image*>::iterator it = mapImages.find(fileName);
 	if (it == mapImages.end())
 	{
 		return;
 	}

 	SAFE_RELEASE(it->second);	// Image*	// Image 동적할당 해제
 	mapImages.erase(it);		// 맵에서 노드 삭제
 }
