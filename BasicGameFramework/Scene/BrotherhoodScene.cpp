#include "stdafx.h"
#include "BrotherhoodScene.h"
#include "Layer.h"

#include "../Object/Player.h"
#include "../Object/Obstacle.h"
#include "../Object/BrotherhoodBackground.h"
#include "../Object/BrotherhoodBackground1.h"
#include "../Object/BrotherhoodBackground2.h"
#include "../Object/BrotherhoodBackground3.h"
#include "../Object/BrotherhoodBackground4.h"
#include "../Object/BrotherhoodBackground5.h"

void BrotherhoodScene::Init()
{
	Layer* BackgroundLayer = new Layer(this, L"BrotherHoodBackground", 1);
	Layer* MainLayer = new Layer(this, L"BrotherHood", 2);
	Layer* ForegroundLayer = new Layer(this, L"BrotherHoodForeground", 3);

	BrotherhoodBackground* backgroundImg = new BrotherhoodBackground(this, BackgroundLayer, L"BrotherHoodBackground");
	backgroundImg->SetPosition(0, 0);

	BrotherhoodBackground1* backgroundImg1 = new BrotherhoodBackground1(this, BackgroundLayer, L"BrotherHoodBackground1");
	backgroundImg1->SetPosition(0, 0);

	BrotherhoodBackground2* backgroundImg2 = new BrotherhoodBackground2(this, BackgroundLayer, L"BrotherHoodBackground2");
	backgroundImg2->SetPosition(0, 0);

	BrotherhoodBackground3* backgroundImg3 = new BrotherhoodBackground3(this, BackgroundLayer, L"BrotherHoodBackground3");
	backgroundImg3->SetPosition(0, 0);

	BrotherhoodBackground4* backgroundImg4 = new BrotherhoodBackground4(this, BackgroundLayer, L"BrotherHoodBackground4");
	backgroundImg4->SetPosition(0, 0);


	Player* player = new Player(this, MainLayer, L"Player");
	player->SetPosition(500, 500);


	BrotherhoodBackground5* backgroundImg5 = new BrotherhoodBackground5(this, ForegroundLayer, L"BrotherHoodBackground5");
	backgroundImg5->SetPosition(0, 0);



	Scene::Init();
}
