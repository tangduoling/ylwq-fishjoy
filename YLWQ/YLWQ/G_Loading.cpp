#include "main.h"
//游戏启动前加载

G_Loading::G_Loading(void)
{
}

G_Loading::G_Loading(HGE*hge)
{
	phge=hge;
	bloadup=false;
	bloading=true;
	loadtime=0;
	loadcount=0;
}

G_Loading::~G_Loading(void)
{
}

//加载首页面资源
void G_Loading::LoadTexture(void)
{
      texload[0]=phge->Texture_Load("..\\resource\\Loading\\0.png");
	  texload[1]=phge->Texture_Load("..\\resource\\Loading\\1.png");
	  texload[2]=phge->Texture_Load("..\\resource\\Loading\\2.png");
	  texload[3]=phge->Texture_Load("..\\resource\\Loading\\3.png");
	  sprload[0]=new hgeSprite(texload[0],0.0f,0,69,81);
	  sprload[1]=new hgeSprite(texload[0],69.0f,0,78,81);
	  sprload[2]=new hgeSprite(texload[0],147.0f,0,75,81);
	  sprload[3]=new hgeSprite(texload[0],222.0f,0,78,81);

	  sprload[4]=new hgeSprite(texload[1],0,0,363,35);
	  sprload[5]=new hgeSprite(texload[2],0,0,105,107);

	  for(int i=0;i<17;i++)
	    sprloadcount[i]=new hgeSprite(texload[1],0,0,i*21.0f,35);

	  for(int i=0;i<21;i++)
	    sprload[i+6]=new hgeSprite(texload[3],i*430.0f,0,430,253);
}

//渲染加载资源界面
void G_Loading::Render(void)
{
	  int centerx=G_SCREENWIDTH/2;
	  int centery=G_SCREENHEIGHT/2;
	  if(bloading)
		{
		   sprload[0]->Render(centerx-183,centery-81/2-80);
		   sprload[1]->Render(centerx-61,centery-81/2-80);
		   sprload[2]->Render(centerx+61,centery-81/2-80);
		   sprload[3]->Render(centerx+183,centery-81/2-80);
		   sprloadcount[loadcount]->Render(550,450);
		}
		else
		{
			if(loadtime<75)
			   sprload[6+loadtime/5]->Render(550,250);
			else
				sprload[21]->Render(550,250);
			sprload[4]->Render(670,480);
			loadtime++;
			if(loadtime>100)
			{
		       bloadup=true;
			   game->g_channel=hge->Effect_PlayEx(game->g_backeff[game->g_effid],100,0,1.0f,false);
			}
		}
}
