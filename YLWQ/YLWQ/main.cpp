#include "main.h"

HGE *hge=0;

float timer=0;
float  g_t=0;
Game *game = 0;//创建游戏指针
DWORD time=0;

DWORD WINAPI Thread1(LPVOID lpvoid)
{
	static DWORD musictime0=timeGetTime(),musictime1;
	game->Loading();
	game->g_load->bloading=false;
	while(!game->g_bover)
	{
		game->g_com->UpDataKey();
		musictime1=timeGetTime();
		if(game->g_load->bloadup)
		{
			if(!hge->Channel_IsPlaying(game->g_channel))
			{
				if(musictime1-musictime0>300000)
				{
					musictime0=musictime1;
					game->g_back->m_bwave=true;
					if(game->g_effid<4)
						game->g_effid+=1;
					else
						game->g_effid=1;
					game->g_channel=hge->Effect_PlayEx(game->g_backeff[0],100,0,1,false);
				}
				else
					game->g_channel=hge->Effect_PlayEx(game->g_backeff[game->g_effid],100,0,1,false);
			}
		}
	}
	return 0;
}

DWORD WINAPI Thread2(LPVOID lpvoid)
{
	while(!game->g_bover)
	{
		game->g_com->UpDataKey();
	}
	return 0;
}

bool FrameFunc()
{
	if(KEY_DOWN(HGEK_ESCAPE))
		return true; 
	return false;
}

bool RenderFunc()
{
	// Render graphics to the texture
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0xff04090f);//0xff04090f
	g_t=hge->Timer_GetDelta();
	timer+=g_t*6;
	time=(int)timer;
	game->GameRun();
	hge->Gfx_EndScene();
	time++;
	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    hge=hgeCreate(HGE_VERSION);//使用hgeCreate函数创建HGE接口，参数必须传递正确的HGE_VERSION,它是在hge.h中定义的 
	
	//初始化系统参数
	hge->System_SetState(HGE_LOGFILE, "ylwq.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);//设置逻辑函数为Frame函数 
	hge->System_SetState(HGE_RENDERFUNC,RenderFunc);//设置绘制函数为Render函数 
	hge->System_SetState(HGE_TITLE, "鱼乐无穷");//设置窗口标题为“显示图像”
	hge->System_SetState(HGE_FPS, G_FPS);//设定最大FPS
	hge->System_SetState(HGE_WINDOWED,true);//设置使用窗口模式 //false
	hge->System_SetState(HGE_SCREENWIDTH, G_SCREENWIDTH);//将屏幕宽度设置为1440 
	hge->System_SetState(HGE_SCREENHEIGHT,G_SCREENHEIGHT);//将屏幕高度设置为900 
	//hge->System_SetState(HGE_SCREENBPP, 32);
	hge->System_SetState(HGE_USESOUND,true);
	hge->System_SetState(HGE_ZBUFFER,true);
	hge->System_SetState(HGE_SHOWSPLASH,false);//去除LOGO
	//实例化一个游戏
    game = new Game(hge);
	//初始化错误检测
	if(hge->System_Initiate())//用hge类的System_Initiate()方法，检测初始化是否有错误出现。 
	{  
		game->g_load->LoadTexture();//加载图片
		game->InitFont();//初始化字体
		HANDLE TD1=CreateThread(NULL,0,Thread1,NULL,0,0);//创建线程
		HANDLE TD2=CreateThread(NULL,0,Thread2,NULL,0,0);
		CloseHandle(TD1);
		CloseHandle(TD2);
		hge->System_Start();//如果没有问题，则使用System_Start方法，开始程序。
		game->g_bover=true; //结束声音线程标志
	}
	for(int i=0;i<G_PLAYERNUM;i++)
		game->g_savedata->playercent[i]=game->player[i]->m_cent;
	game->g_save->WriteSaveData("save.dat",game->g_savedata);

	// Clean up and shutdown
	hge->System_Shutdown();//程序停止 
	hge->Release();//释放HGE所占用的内存。

}

