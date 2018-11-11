#pragma once
#include "GameObject.h"

#define GROUND_BBOX_WIDTH  768
#define GROUND_BBOX_HEIGHT 32

class CBrick : public CGameObject
{
public:
	virtual void LoadResource();
	virtual void Render(int cam_X, int cam_Y);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
};