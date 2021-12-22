#include "Obstacle.h"

#include "../Component/RectComponent.h"

#include "stdafx.h"

void Obstacle::Init()
{
	RectComponent* rect = new RectComponent(this);
	//rect->SetPen(RGB(255, 0, 0));
	//rect->SetBrush(RGB(128, 128, 128));

	SetPivot(Pivot::Center);
	SetSize(1280, 40);
}
