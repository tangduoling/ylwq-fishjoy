#pragma once
#include"main.h"
class G_Fish;
class GameBack
{
public:
	GameBack(void);
	GameBack(HGE*phge);
	~GameBack(void);
	bool     m_bwave;
	float    m_wavex;
protected:
	HGE* m_phge;
	hgeSprite *m_sprback[3];//±³¾°
	HTEXTURE  m_texback[3];
	hgeSprite *m_sprwater[27];//Ë®²¨
	HTEXTURE  m_texwater[27];
	hgeSprite *m_sprhx[25];//º£ÐÇ
	HTEXTURE m_texhx;
	hgeSprite *m_sprsh0[24];
	hgeSprite *m_sprsh1[24];
	hgeSprite *m_sprsh2[24];
	hgeSprite *m_sprsh3[22];
	hgeSprite *m_sprsh33[22];
	hgeSprite *m_sprsh4[22];
	hgeSprite *m_sprsh5[9];
	HTEXTURE  m_texsh[6];//Éºº÷
	hgeSprite *m_sprwave[2];//º£ÀË
	HTEXTURE  m_texwave;
	hgeSprite *m_sprpp[20];
	HTEXTURE  m_texpp;
	hgeSprite *m_sprsc0[24];
	hgeSprite *m_sprsc01[24];
	hgeSprite *m_sprsc02[24];
	hgeSprite *m_sprsc2[16];
	HTEXTURE  m_texsc[3];
	int      m_sta;
	int      m_pptime;
	int      m_backtime;
	float    m_ppx;
	float    m_ppy;
public:
	void LoadTexture(void);
	void RenderBack(G_Fish*pfish);
	void SetBackSta(int sta){m_sta=sta;}
	void RenderWater(void);
};

