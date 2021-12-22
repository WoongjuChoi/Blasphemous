#include "stdafx.h"
#include "BrotherhoodScene.h"
#include "Layer.h"

#include "../Object/Player.h"
#include "../Object/Obstacle.h"
#include "../Object/BrotherhoodBackground.h"

void BrotherhoodScene::Init()
{
	Layer* BrotherhoodBackgroundLayer = new Layer(this, L"BrotherHoodBackground", 1);
	Layer* BrotherhoodLayer = new Layer(this, L"BrotherHood", 2);

	BrotherhoodBackground* backgroundImg = new BrotherhoodBackground(this, BrotherhoodBackgroundLayer, L"BrotherHoodBackground");
	backgroundImg->SetPosition(0, 0);

	Player* player = new Player(this, BrotherhoodLayer, L"Player");
	player->SetPosition(500, 400);

	Obstacle* floor = new Obstacle(this, BrotherhoodLayer, L"Floor");
	floor->SetPosition(640, 580);


	Scene::Init();
}
