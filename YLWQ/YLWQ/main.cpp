#include "main.h"

HGE *hge=0;

float timer=0;
float  g_t=0;
Game *game = 0;//������Ϸָ��
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
    hge=hgeCreate(HGE_VERSION);//ʹ��hgeCreate��������HGE�ӿڣ��������봫����ȷ��HGE_VERSION,������hge.h�ж���� 
	
	//��ʼ��ϵͳ����
	hge->System_SetState(HGE_LOGFILE, "ylwq.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);//�����߼�����ΪFrame���� 
	hge->System_SetState(HGE_RENDERFUNC,RenderFunc);//���û��ƺ���ΪRender���� 
	hge->System_SetState(HGE_TITLE, "��������");//���ô��ڱ���Ϊ����ʾͼ��
	hge->System_SetState(HGE_FPS, G_FPS);//�趨���FPS
	hge->System_SetState(HGE_WINDOWED,true);//����ʹ�ô���ģʽ //false
	hge->System_SetState(HGE_SCREENWIDTH, G_SCREENWIDTH);//����Ļ�������Ϊ1440 
	hge->System_SetState(HGE_SCREENHEIGHT,G_SCREENHEIGHT);//����Ļ�߶�����Ϊ900 
	//hge->System_SetState(HGE_SCREENBPP, 32);
	hge->System_SetState(HGE_USESOUND,true);
	hge->System_SetState(HGE_ZBUFFER,true);
	hge->System_SetState(HGE_SHOWSPLASH,false);//ȥ��LOGO
	//ʵ����һ����Ϸ
    game = new Game(hge);
	//��ʼ��������
	if(hge->System_Initiate())//��hge���System_Initiate()����������ʼ���Ƿ��д�����֡� 
	{  
		game->g_load->LoadTexture();//����ͼƬ
		game->InitFont();//��ʼ������
		HANDLE TD1=CreateThread(NULL,0,Thread1,NULL,0,0);//�����߳�
		HANDLE TD2=CreateThread(NULL,0,Thread2,NULL,0,0);
		CloseHandle(TD1);
		CloseHandle(TD2);
		hge->System_Start();//���û�����⣬��ʹ��System_Start��������ʼ����
		game->g_bover=true; //���������̱߳�־
	}
	for(int i=0;i<G_PLAYERNUM;i++)
		game->g_savedata->playercent[i]=game->player[i]->m_cent;
	game->g_save->WriteSaveData("save.dat",game->g_savedata);

	// Clean up and shutdown
	hge->System_Shutdown();//����ֹͣ 
	hge->Release();//�ͷ�HGE��ռ�õ��ڴ档

}

