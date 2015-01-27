#include "Game.h"
//控制游戏全局
Game::Game(void)
{
}

Game::Game(HGE*hge)
{
	phge=hge;
	g_bover=false;
	g_playernum=0;
	g_effid=1+rand()%4;
	m_gamesta=GAME_PLAYING;
	g_com=new GCom();//初始化COM1接口
	g_com->Init();
	g_save=new G_Save();
	g_savedata=new SaveData;
	g_save->ReadSaveData("save.dat",g_savedata);
	g_load=new G_Loading(phge);
	g_back=new GameBack(phge);
	g_pfish=new G_Fish(phge);
	g_set=new G_Set(phge);
	g_set->GetSaveSet(g_savedata);
	for(int i=0;i<G_PLAYERNUM;i++)
	  player[i]=new Player(phge,i,g_com,g_savedata,&sys);
	g_toearn=ftoearn[g_savedata->set.dificul];
}
Game::~Game(void)
{
}

void Game::Loading(void)
{		
	for(int i=0;i<30;i++)
	{
		if(i<5)
		   g_backeff[i]=phge->Effect_Load(cEff[i]);
		else if(i<15)
		   g_eff[i-5]=phge->Effect_Load(cEff[i]);
		else
		    g_eff1[i-15]=phge->Effect_Load(cEff1[i-15]);
	}
	g_back->LoadTexture();
	g_load->loadcount++;
	g_pfish->LoadTexture();
	g_load->loadcount++;
	g_set->LoadTexture();
	for(int i=0;i<G_PLAYERNUM;i++)
	{
	  player[i]->LoadTexture();
	  g_load->loadcount++;
	}
}


void Game::GameRun(void)
{
	GetLocalTime(&sys);
	if(!g_load->bloadup)//是否正在加载资源
		g_load->Render();
	else
	{
		g_back->RenderBack(g_pfish);
		if(m_gamesta==GAME_PLAYING)
		{
			g_pfish->Render(g_back);
			g_back->RenderWater();
			int x1,x2,y1,y2;
			x1=G_SCREENWIDTH/6;
			x2=G_SCREENWIDTH*4/6;
			y1=G_SCREENHEIGHT-40;
			y2=y1;
			player[0]->Render(x1,y1,-PI/2,g_pfish);//渲染炮筒位置340,728
			player[1]->Render(x2,y2,-PI/2,g_pfish);//1000,728
			int centout=0;
			int playernum=0;
			for(int i=0;i<G_PLAYERNUM;i++)//玩家数目
			{
				centout+=player[i]->m_cent;
				if(player[i]->m_benoughcoin)
					playernum++;
			}
			g_playernum=playernum;
			g_savedata->centout=centout;
			font->printf(100,100,HGETEXT_LEFT,"%d:%d",sys.wHour,sys.wMinute);
			font->printf(300,200,HGETEXT_LEFT,"CentIn:%d\nCentOut:%d\nToEarn:%f\nEarn:%f",
				g_savedata->centin,g_savedata->centout,g_toearn,
				(float)(g_savedata->centin-g_savedata->centout)/g_savedata->centin);
			font->printf(5,5,HGETEXT_LEFT,"FPS:%d\nJunYue",phge->Timer_GetFPS());
			font->printf(500,500,HGETEXT_LEFT,"PlayerNum:%d",g_playernum);
			if(GK_D(HGEK_F12))//F12设置游戏
				m_gamesta=GAME_SET;
		}
		else if(m_gamesta==GAME_SET)
		{
			g_set->RenderSet();
		}
	}
}


void Game::InitFont(void)
{
	  font=new hgeFont("..\\resource\\PIC\\font1.fnt");
	  font->SetColor(0Xffaaffcc);
	  font->SetZ(0.0f); 
}
