#include "Brick.h"

void CBrick::LoadResource()
{
	//load resource
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_MISC, L"Resource\\sprites\\ground_test.png", D3DCOLOR_XRGB(176, 224, 248));

	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 texMisc = textures->Get(ID_TEX_MISC);
	sprites->Add(20001, 0, 0, 768, 32, texMisc);

	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	//Animation ground
	ani = new CAnimation(100);		// brick
	ani->Add(20001);
	animations->Add(601, ani);

	this->AddAnimation(601);
}

void CBrick::Render(int cam_X, int cam_Y)
{
	animations[0]->Render(x - cam_X, y - cam_Y);
	//RenderBoundingBox();
}

void CBrick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	r = x + GROUND_BBOX_WIDTH;
	b = y + GROUND_BBOX_HEIGHT;
}