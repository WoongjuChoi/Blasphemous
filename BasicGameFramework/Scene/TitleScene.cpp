#include "TitleScene.h"

#include "../Object/Text.h"

#include "../Util/Input.h"

#include "../Manager/SceneManager.h"

#include "Layer.h"

#include "../Object/TitleBackground.h"
#include "../Object/TitlePenitentOneAnim.h"

#include "stdafx.h"

void TitleScene::Init()
{
	Layer* backgroundLayer = new Layer(this, L"background", 1);
	Layer* penitentOneLayer = new Layer(this, L"penitentOne_title", 2);

	TitleBackground* backgroundImg = new TitleBackground(this, backgroundLayer, L"backgroundImg");
	backgroundImg->SetPosition(0, 0);

	TitlePenitentOneAnim* penitentOne = new TitlePenitentOneAnim(this, penitentOneLayer, L"penitentOneAnim_title");
	penitentOne->SetPosition(0, 0);

	penitentOneLayer->SetText(L"¼ø·Ê", 1000, 400);

	Scene::Init();
}

void TitleScene::Update()
{
	Scene::Update();

	if (Input::GetButtonDown(VK_SPACE))
	{
		SceneManager::GetInstance()->SetNextScene(L"Brotherhood");
	}
}
