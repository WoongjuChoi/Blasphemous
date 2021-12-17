#pragma once

//class MainScene : public Scene
//{
//public:
//	virtual void Init()
//	{
//		auto farLayer = new Layer(1);
//		auto farBg = new BackGround(farLayer);
//		farBg->GetComponent<SpriteComponent>()->SetImage("bg1.bmp");
//		farBg->GetComponent<ScrollComponent>()->SetSpeed(100.0f);
//
//		auto middleLayer = new Layer(2);
//		auto middleBg = new BackGround(middleLayer);
//		middleBg->GetComponent<SpriteComponent>()->SetImage("bg2.bmp");
//		middleBg->GetComponent<ScrollComponent>()->SetSpeed(200.0f);
//
//		auto closeLayer = new Layer(3);
//
//	}
//};

class Image
{
public:
	enum ImageLoadType
	{
		Resource,		// ���α׷��� ���ԵǴ� ������
		File,			// ���� �ð��� �ܺο��� �ε��ϴ� ������
		Empty,			// �� ��Ʈ�� �̹��� ����
		End
	};

	HDC reverseDc;
	HBITMAP hBitmap1;

	// class�� struct�� �������� ����
	// ���������ڰ� public�̳� private�̳�
	typedef struct tagImageInfo
	{
		HDC hMemDc;		// �̹��� �����͸� �����ϴ� �ڵ�(�޸� ������)
		HBITMAP hBitmap;// �̹��� ������
		HBITMAP hOldBit;// ���� �̹��� ������
		int width;		// ���� ũ��
		int height;		// ���� ũ��
		BYTE loadType;	// �ε� Ÿ��

		// �ִϸ��̼� �� ������
		int maxFrameX;
		int maxFrameY;
		int frameWidth;
		int frameHeight;
		int currFrameX;
		int currFrameY;

		tagImageInfo()
		{
			hMemDc = NULL;
			hBitmap = NULL;
			hOldBit = NULL;
			width = 0;
			height = 0;
			loadType = ImageLoadType::Empty;

			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			currFrameX = 0;
			currFrameY = 0;
		};
	} IMAGE_INFO, * LPIMAGE_INFO;

private:
	LPIMAGE_INFO imageInfo;
	bool isTransparent;
	bool isReverse = false;
	COLORREF transColor;

public:
	HRESULT Init(int width, int height);	// �� ��Ʈ�� �̹��� ����(Empty)
	HRESULT Init(const wchar_t* fileName, int width, int height, int maxFrameX = 1, int maxFrameY = 1, bool isTrans = false, COLORREF transColor = NULL);

	void Release();	// �޸� ����

	void Render(HDC hdc, int destX, int destY, int frameX = 0, int frameY = 0, float scale = 1.0f);	// �̹��� �����͸� ȭ�鿡 ����

	HDC GetMemDC() { if (imageInfo) return imageInfo->hMemDc; return NULL; }

	LPIMAGE_INFO GetImageInfo() { return imageInfo; }

	int GetCurrFrameX() { return imageInfo->currFrameX; }
	void SetCurrFrameX(int frame) { imageInfo->currFrameX = frame; }
	int GetCurrFrameY() { return imageInfo->currFrameY; }
	void SetCurrFrameY(int frame) { imageInfo->currFrameY = frame; }

	int GetMaxFrameX() { return imageInfo->maxFrameX; }
	int GetMaxFrameY() { return imageInfo->maxFrameY; }

	int GetFrameWidth() { return imageInfo->frameWidth; }
	int GetFrameHeight() { return imageInfo->frameHeight; }

	int GetWidth() { return imageInfo->width; }
	int GetHeight() { return imageInfo->height; }

	void SetIsReverse(bool reverse);
	bool GetIsReverse();
};

