#pragma once
#include"main.h"
class G_Loading
{
 public:
	G_Loading();
	G_Loading(HGE * hge);
	~G_Loading(void);
	HGE * phge;
	HTEXTURE texload[4];
	hgeSprite * sprload[21];//��ͼƬ���в��ʷָ�
	hgeSprite * sprloadcount[17];
	int  loadcount;
	int  loadtime;
	bool bloading;
	bool bloadup;

	void LoadTexture(void);
	void Render(void);
};

