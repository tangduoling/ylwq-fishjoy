class G_Set;
#pragma once
#include "main.h"
#include"G_Set.h"

class Game
{
public:
	Game(void);
	Game(HGE *hge);
	~Game(void);

    HGE *phge;

	G_Loading * g_load;
	SYSTEMTIME sys;
	SaveData * g_savedata;
	G_Save*   g_save;
    G_Set*    g_set;
	HEFFECT   g_backeff[5];
	HEFFECT   g_eff[10];
	HEFFECT   g_eff1[15];
	HCHANNEL  g_channel;
	bool      g_bover;
	hgeFont* font;
	GCom  *g_com;
	GameBack *g_back;
	Player   *player[6];//Íæ¼ÒÊýÄ¿6
	G_Fish   *g_pfish;
	int      m_gamesta;
	int      g_effid;
	int      g_playernum;
	float    g_toearn;      
	void Loading(void);
	void GameRun(void);
	void InitFont(void);
};

