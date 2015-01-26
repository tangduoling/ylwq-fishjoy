#pragma once
#include"main.h"
typedef struct typDDCoin
{
	vector<FCoin>fcoin;//飞币
	vector<DCoin>dcoin;//叠币
	int   dn;          //叠币数量
	int   fn;          //飞币数量
	int   id;          //ID
	int   time;        //计数器
	int   move;        //叠币移动的次数
	int   cent;        //叠币上的分数
	float x;           //位置
	float y;
}DDCoin,*pddcoin;
class Player
{
public:
	Player(void);
	Player(HGE*phge,int id,GCom*com,SaveData*savedata,SYSTEMTIME* psys);
	~Player(void);
	void LoadTexture();
	float m_rot;
//protected:
	HGE*m_phge;
	HTEXTURE m_texCentCircle;
	HTEXTURE m_texnet;
	HTEXTURE m_texbullet;
	HTEXTURE m_texlbullet;
	HTEXTURE m_texlnet;
	HTEXTURE m_texcoin;
	HTEXTURE m_texfort;
	HTEXTURE m_texgun;
	HTEXTURE m_texlgun[2];
	HTEXTURE m_texlgunmark;
	HTEXTURE m_texgunfire;
	HTEXTURE m_texnum1;//子弹上的数字
	HTEXTURE m_texnum2;//得分数字
	HTEXTURE m_texnum3;//炮的等级数字
	HTEXTURE m_texnum4;//彩金数字
	HTEXTURE m_texnum5;//叠币上的数字
	HTEXTURE m_texnetw;
	HTEXTURE m_texcj;
	HTEXTURE m_texcoinj[2];
	HTEXTURE m_texcoiny;
	HTEXTURE m_texcoind[2];
	HCHANNEL m_chnwin;
	hgeSprite*m_sprCentCircle;
	hgeSprite*m_sprnet;
	hgeSprite*m_sprbullet[2];
	hgeSprite*m_sprlbullet[2];
	hgeSprite*m_sprlnet;
	hgeSprite*m_sprcoin[8];
	hgeSprite*m_sprfort[20];
	hgeSprite*m_sprgun[2];
	hgeSprite*m_sprlgunmark;
	hgeSprite*m_sprlgun[2];
	hgeSprite*m_sprgunfire[3];
	hgeSprite*m_sprnum1[10];
	hgeSprite*m_sprnum2[10];
	hgeSprite*m_sprnum3[10];
	hgeSprite*m_sprnum4[10];
	hgeSprite*m_sprnum5[10];
	hgeSprite*m_sprnetw[13];
	hgeSprite*m_sprcj[9];
	hgeSprite*m_sprcoiny[6];
	hgeSprite*m_sprcoinj0[18];
	hgeSprite*m_sprcoinj1[7];
	hgeSprite*m_sprcoind[5];
	GCom*       m_com;
	SaveData*   m_savedata;
	SYSTEMTIME* m_sys;
	float m_x;
	float m_y;
	float m_lgunmarkx;
	float m_lgunmarky;
	float m_lgunrot;
	DWORD m_t0;
	DWORD m_t1;
	int   m_lguntime;
	bool  m_blgun;
	bool  m_bgun0;
	bool  m_benoughcoin;
	int   m_wincent;
	int   m_id;
	int   m_cent;
	int   m_gunlevel;
	vector<Bullet>m_bullets;
	vector<DDCoin>m_ddcoin;
	Bullet m_bullet;
	int m_numdcoin;
	int m_numbullet;
public:
	void Render(float x, float y,float,G_Fish*pfish);
	bool IsHitFish(G_Fish*gfish,pbullet bullet,float rot);
	void InitCoins(Fish*pfish,float rot);
	bool HitFishJL(Fish*pfish);
	void InitFcoin(Fish*pfish,float rot);
};

