#include "TempScene.h"
#include "Layer.h"

#include "../Object/Obstacle.h"

#include "stdafx.h"

void TempScene::Init()
{
	Layer* mainLayer = new Layer(this, L"Main", 1);

	Obstacle* obstacle = new Obstacle(this, mainLayer, L"Obstacle");
	obstacle->SetPosition(700, 400);

	
	Scene::Init();
}