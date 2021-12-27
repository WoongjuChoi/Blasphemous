#include "stdafx.h"
#include "Image.h"

HRESULT Image::Init(int width, int height)
{
	HDC hdc = GetDC(g_hWnd);		// ������ ������ ���� ��������

	// �� ��Ʈ�� ����
	imageInfo = new IMAGE_INFO;
	imageInfo->width = width;
	imageInfo->height = height;
	imageInfo->loadType = ImageLoadType::Empty;
	imageInfo->hBitmap = CreateCompatibleBitmap(hdc, width, height);
	imageInfo->hMemDc = CreateCompatibleDC(hdc);	// ���� ������ DC 
											// �⺻������ Bitmap�� ����Ǿ� �ִ�.
	imageInfo->hOldBit =
		(HBITMAP)SelectObject(imageInfo->hMemDc, imageInfo->hBitmap);

	reverseDc = CreateCompatibleDC(hdc);
	hBitmap1 = CreateCompatibleBitmap(hdc, width, height);
	SelectObject(reverseDc, hBitmap1);

	ReleaseDC(g_hWnd, hdc);

	//if (SUCCEEDED(E_FAIL))
	//{

	//}

	if (imageInfo->hBitmap == NULL)	// ��Ʈ�� ������ �������� ��
	{
		Release();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Image::Init(const wchar_t* fileName, int width, int height, int maxFrameX, int maxFrameY,
	bool isTrans, COLORREF transColor)
{
	HDC hdc = GetDC(g_hWnd);

	imageInfo = new IMAGE_INFO;
	imageInfo->width = width;
	imageInfo->height = height;
	imageInfo->loadType = ImageLoadType::File;
	imageInfo->hBitmap = (HBITMAP)LoadImageW(g_hInstance, fileName, IMAGE_BITMAP, width, height,
		LR_LOADFROMFILE);
	imageInfo->hMemDc = CreateCompatibleDC(hdc);	// ���� ������ DC 
											// �⺻������ Bitmap�� ����Ǿ� �ִ�.
	imageInfo->hOldBit =
		(HBITMAP)SelectObject(imageInfo->hMemDc, imageInfo->hBitmap);

	reverseDc = CreateCompatibleDC(hdc);
	hBitmap1 = (HBITMAP)LoadImage(g_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	SelectObject(reverseDc, hBitmap1);

	ReleaseDC(g_hWnd, hdc);

	this->isTransparent = isTrans;
	this->transColor = transColor;

	imageInfo->maxFrameX = maxFrameX;
	imageInfo->maxFrameY = maxFrameY;
	imageInfo->currFrameX = 0;
	imageInfo->currFrameY = 0;
	imageInfo->frameWidth = width / maxFrameX;
	imageInfo->frameHeight = height / maxFrameY;

	if (imageInfo->hBitmap == NULL)
	{
		Release();
		return E_FAIL;
	}

	return S_OK;
}

void Image::Release()
{
	if (imageInfo)
	{
		SelectObject(imageInfo->hMemDc, imageInfo->hOldBit);
		DeleteObject(imageInfo->hBitmap);
		DeleteDC(imageInfo->hMemDc);

		delete imageInfo;
		imageInfo = nullptr;
	}
}

void Image::Render(HDC hdc, int destX, int destY, int frameX, int frameY, float scale)
{
	// frameX : 0, frameY : 0 => ���� (68 * 0, 0) �󸶳� �����Ұǰ� (68, 104)
	// frameX : 1, frameY : 0 => ���� (68 * 1, 0)  (68, 104)
	// frameX : 2, frameY : 0 => ���� (68 * 2, 0)  (68, 104) 
	// frameX : 3, frameY : 0 => ���� (68 * 3, 0)  (68, 104)

	if (isTransparent)
	{
		if (isReverse)
		{
			StretchBlt(
				reverseDc,
				imageInfo->frameWidth * frameX,
				imageInfo->frameHeight * frameY,
				(imageInfo->frameWidth),
				(imageInfo->frameHeight),
				imageInfo->hMemDc,
				imageInfo->frameWidth * (frameX + 1),
				imageInfo->frameHeight * frameY,
				-imageInfo->frameWidth,
				imageInfo->frameHeight,
				SRCCOPY);

			GdiTransparentBlt(
				hdc,
				destX,
				destY,
				(imageInfo->frameWidth) * scale,
				(imageInfo->frameHeight) * scale,      // ��ü ������ ��

				reverseDc,
				(imageInfo->frameWidth) * frameX,
				(imageInfo->frameHeight) * frameY,
				(imageInfo->frameWidth),
				(imageInfo->frameHeight),
				transColor
			);
		}
		else
		{
			GdiTransparentBlt(
				hdc,
				destX,
				destY,
				imageInfo->frameWidth * scale,
				imageInfo->frameHeight * scale,	// ��ü ������ ��

				imageInfo->hMemDc,
				imageInfo->frameWidth * frameX,
				imageInfo->frameHeight * frameY,
				imageInfo->frameWidth, 
				imageInfo->frameHeight,
				transColor
			);
		}
	}
	else
	{
		BitBlt(hdc,				// ���� ������ DC
			destX,		// ����� ��Ʈ���� ���� ��ġ x
			destY,		// ����� ��Ʈ���� ���� ��ġ y
			imageInfo->frameWidth,	// ���� ������ ���� ũ��
			imageInfo->frameHeight,	// ���� ������ ���� ũ��
			imageInfo->hMemDc,	// ���� DC
			imageInfo->frameWidth * frameX,				// ���� ��Ʈ�� ���� ���� ��ġ x
			imageInfo->frameHeight * frameY,			// ���� ��Ʈ�� ���� ���� ��ġ y
			SRCCOPY);			// ���� �ɼ�
	}
}

void Image::MapRender(HDC hdc, int originX, int originY, int printWidth, int printHeight, int scale)
{
	if (isTransparent)
	{
		GdiTransparentBlt(
			hdc,
			0,
			0,
			imageInfo->width,
			imageInfo->height,

			imageInfo->hMemDc,
			originX,
			originY,
			printWidth * scale,
			printHeight * scale,
			transColor
		);
	}
}

void Image::SetMaxFrameX(int x)
{
	imageInfo->maxFrameX = x;
}

void Image::SetIsReverse(bool reverse)
{
	isReverse = reverse;
}

bool Image::GetIsReverse()
{
	return isReverse;
}
