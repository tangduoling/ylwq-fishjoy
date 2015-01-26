#include "G_Set.h"
#include"main.h"
const Pos backpos[]={
	{720,450},
	{720,80},
	{720,850},
	{200,80},
};
const Pos menupos[]={
{720,230},
{720,300},
{720,370},
{720,440},
{720,510},
{720,570},
};
const Pos paramer[]={
	{720,155},
	{720,195},
	{720,235},
	{720,275},
	{720,315},//
	{720,360},
	{720,400},
	{720,440},
};

const Pos passwin[]={
	{720,450},
	{720,600},
	{720,450},
	{720,450},
};
const Pos tellpos[]={
   {540,600},
   {605,600},
   {670,600},
   {735,600},
   {800,600},
   {865,600},
   {930,600},
   {995,600},
};
G_Set::G_Set(void)
{
	m_cur=0;
	m_curpos=menupos[m_cur];
}

G_Set::G_Set(HGE*phge)
{
	m_phge=phge;
	m_cur=0;
	m_line=0;
	m_num=0;
	m_codingtime=0;
	m_setwhat=SET_BEGIN;
	m_curpos=menupos[m_cur];
	m_bwin=false;
	m_bcoding=false;
	m_byes=false;
	m_passwin=0;
	for(int i=0;i<10;i++)
		m_sprnum[i]=new hgeSprite*[10];
}
G_Set::~G_Set(void)
{
}


void G_Set::LoadTexture(void)
{
	m_phge->Resource_AttachPack("PIC\\Set.zip",0);
	for(int i=0;i<4;i++)
		m_texsetback[i]=m_phge->Texture_Load(cTex[i]);
	m_sprsetback[0]=new hgeSprite(m_texsetback[0],0,0,1260,800);
	m_sprsetback[0]->SetHotSpot(630,400);
	m_sprsetback[1]=new hgeSprite(m_texsetback[1],0,0,1263,74);
	m_sprsetback[1]->SetHotSpot(631.5f,37);
	m_sprsetback[2]=new hgeSprite(m_texsetback[2],0,0,1263,60);
	m_sprsetback[2]->SetHotSpot(631.5f,30);
	m_sprsetback[3]=new hgeSprite(m_texsetback[3],0,0,164,44);
	m_sprsetback[3]->SetHotSpot(82,22);

	for(int i=0;i<2;i++)
		m_texcur[i]=m_phge->Texture_Load(cTex[4+i]);
	m_sprcur[0]=new hgeSprite(m_texcur[0],0,0,175,53);
	m_sprcur[0]->SetHotSpot(87.5f,26.5f);
	m_sprcur[0]->SetColor(0x88888888);
	m_sprcur[1]=new hgeSprite(m_texcur[1],0,0,627,28);
	m_sprcur[1]->SetHotSpot(313.5f,14);
	m_sprcur[1]->SetColor(0x88888888);
  
	for(int i=0;i<6;i++)
		m_texmenu[i]=m_phge->Texture_Load(cTex[6+i]);
	for(int i=0;i<6;i++)
	{
	  m_sprmenu[i]=new hgeSprite(m_texmenu[i],0,0,175,53);
	  m_sprmenu[i]->SetHotSpot(87.5f,26.5f);
	}

	for(int i=0;i<9;i++)
		m_texparamer[i]=m_phge->Texture_Load(cTex[12+i]);
	m_sprparamer=new hgeSprite(m_texparamer[0],0,0,706,318);
	m_sprparamer->SetHotSpot(353,159);

	for(int i=0;i<4;i++)
	{
		m_sprdif[i]=new hgeSprite(m_texparamer[1+i],0,0,108,31);
		m_sprdif[i]->SetHotSpot(54,15.5f);
	}
	for(int i=0;i<4;i++)
	{
	  m_sprmode[i]=new hgeSprite(m_texparamer[5+i],0,0,149,30);
	  m_sprmode[i]->SetHotSpot(74.5f,15);
	}

	m_texaudit=m_phge->Texture_Load(cTex[21]);
	m_spraudit=new hgeSprite(m_texaudit,0,0,649,545);
	m_spraudit->SetHotSpot(324.5f,272.5f);

	for(int i=0;i<9;i++)
		m_texpasswin[i]=m_phge->Texture_Load(cTex[i+22]);

	m_sprpasswin[0]=new hgeSprite(m_texpasswin[0],0,0,614,399);
	m_sprpasswin[0]->SetHotSpot(307,199.5f);

	m_sprpasswin[1]=new hgeSprite(m_texpasswin[1],0,0,553,372);
	m_sprpasswin[1]->SetHotSpot(226.5f,186);

	m_sprpasswin[2]=new hgeSprite(m_texpasswin[2],0,0,514,375);
	m_sprpasswin[2]->SetHotSpot(257,187.5f);

	m_sprpasswin[3]=new hgeSprite(m_texpasswin[3],0,0,614,399);
	m_sprpasswin[3]->SetHotSpot(307,199.5f);

	m_spryesno[0]=new hgeSprite(m_texpasswin[4],0,0,52,49);
	m_spryesno[0]->SetHotSpot(26,24.5f);
	m_spryesno[1]=new hgeSprite(m_texpasswin[5],0,0,41,41);
	m_spryesno[1]->SetHotSpot(20.5f,20.5f);
	m_spryesno[2]=new hgeSprite(m_texpasswin[6],0,0,41,41);
	m_spryesno[2]->SetHotSpot(20.5f,20.5f);

	m_sprnumline[0]=new hgeSprite(m_texpasswin[7],0,0,48,6);
	m_sprnumline[0]->SetHotSpot(24,3);
	m_sprnumline[1]=new hgeSprite(m_texpasswin[8],0,0,32,5);
	m_sprnumline[1]->SetHotSpot(16,2.5f);

	for(int i=0;i<12;i++)
		m_textell[i]=m_phge->Texture_Load(cTex[i+31]);
	for(int i=0;i<5;i++)
	{
		m_sprtell[i]=new hgeSprite(m_textell[i],0,0,501,33);
		m_sprtell[i]->SetHotSpot(250.5f,16.5f);
	}
	for(int i=5;i<9;i++)
	{
	    m_sprtell[i]=new hgeSprite(m_textell[i],0,0,227,32);
		m_sprtell[i]->SetHotSpot(113.5f,16);
	}
	for(int i=9;i<12;i++)
    {
	    m_sprtell[i]=new hgeSprite(m_textell[i],0,0,184,45);
		m_sprtell[i]->SetHotSpot(113.5f,16);
	}

	for(int i=0;i<6;i++)
		m_texhelp[i]=m_phge->Texture_Load(cTex[i+43]);
	for(int i=0;i<3;i++)
	{
	  m_sprhelp[i]=new hgeSprite(m_texhelp[i],0,0,22,22);
	  m_sprhelp[i]->SetHotSpot(11,11);
	}
	for(int i=3;i<6;i++)
	{
	  m_sprhelp[i]=new hgeSprite(m_texhelp[i],0,0,126,27);
	  m_sprhelp[i]->SetHotSpot(63,13.5f);
	}
	m_phge->Resource_RemoveAllPacks();
	m_phge->Resource_AttachPack("PIC\\Num.zip",0);
	for(int i=0;i<10;i++)
		m_texnum[i]=m_phge->Texture_Load(cTex[i]);
	for(int i=0;i<7;i++)
	  for(int j=0;j<10;j++)
		{
		  m_sprnum[i][j]=new hgeSprite(m_texnum[i],j*16.0f,0,16,21);
		  m_sprnum[i][j]->SetHotSpot(8,10.5f);
		}
	  for(int i=0;i<10;i++)
	  {
		m_sprnum[7][i]=new hgeSprite(m_texnum[8],i*24.0f,0,24,34);
		m_sprnum[7][i]->SetHotSpot(12,17);
		m_sprnum[8][i]=new hgeSprite(m_texnum[8],i*24.0f,0,24,34);
		m_sprnum[8][i]->SetHotSpot(12,17);
	  }
	  for(int i=0;i<10;i++)
	  {
		    m_sprnum[9][i]=new hgeSprite(m_texnum[9],i*51.0f,0,51,62);
		    m_sprnum[9][i]->SetHotSpot(25.5f,31);
	  }
}


void G_Set::RenderSet(void)
{
	switch(m_setwhat)
	{
	case SET_BEGIN:
		SetBegin();
		break;
	case SET_PARAMER:
		SetParameter();
		break;
	case SET_PRESSCODE:
		break;
	case SET_AUDIT:
		  Audit();
		break;
    case SET_TELLAUDIT:
		  SetTellAudit();
		break;
	}
}


void G_Set::SetParameter(void)
{
	for(int i=0;i<4;i++)
		m_sprsetback[i]->Render(backpos[i].x,backpos[i].y);
	m_sprmenu[0]->Render(400,80);
	m_sprparamer->Render(700,300);
	m_sprcur[1]->RenderEx(m_curpos.x,m_curpos.y,0,1.2f,1);
	m_sprdif[m_set.dificul]->Render(paramer[0].x+280,paramer[0].y);
	//DrawNumsR(m_sprnum[1],m_set.coin,paramer[0].x+250,paramer[1].y,0,1,15,0);
	DrawNumsR(m_sprnum[1],m_set.ticket,paramer[0].x+290,paramer[1].y,0,1,15,0);
	DrawNumsR(m_sprnum[2],m_set.mincent,paramer[0].x+290,paramer[2].y,0,1,15,0);
	DrawNumsR(m_sprnum[1],m_set.maxcent,paramer[0].x+290,paramer[3].y,0,1,15,0);
	m_sprmode[m_set.mode]->Render(paramer[4].x+260,paramer[4].y);
    switch(m_cur)
	{
	    case 0:
			if(GK_D(HGEK_LEFT))
			  {
				  if(m_set.dificul>0)
				      m_set.dificul--;
				  else
					  m_set.dificul=3;
  			  }
			else if(GK_D(HGEK_RIGHT))
			 {
			     if(m_set.dificul<3)
				      m_set.dificul++;
				  else
					  m_set.dificul=0;
			 }
			else if(GK_D(HGEK_UP))
			{
				m_cur=7;
				m_curpos=paramer[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=paramer[m_cur];
			}
		break;
		case 1:
			if(GK_D(HGEK_LEFT))
			  {
				  if(m_set.ticket>10)
					  m_set.ticket-=10;
				  else
					  m_set.ticket=100;
  			  }
			else if(GK_D(HGEK_RIGHT))
			 {
				 if(m_set.ticket<100)
					 m_set.ticket+=10;
				  else
					  m_set.ticket=10;
			 }
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=paramer[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=paramer[m_cur];
			}
		break;
		case 2:
			if(GK_D(HGEK_LEFT))
			  {
				  if(m_set.mincent>1)
				      m_set.mincent--;
				  else
					  m_set.mincent=10;
  			  }
			else if(GK_D(HGEK_RIGHT))
			 {
			     if(m_set.mincent<10)
				      m_set.mincent++;
				  else
					  m_set.mincent=1;
			 }
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=paramer[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=paramer[m_cur];
			}
		break;
		case 3:
			if(GK_D(HGEK_LEFT))
			  {
				  if(m_set.maxcent>1)
				      m_set.maxcent--;
				  else
					  m_set.maxcent=99;
  			  }
			else if(GK_D(HGEK_RIGHT))
			 {
			     if(m_set.maxcent<99)
				      m_set.maxcent++;
				  else
					  m_set.maxcent=1;
			 }
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=paramer[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=paramer[m_cur];
			}
		break;
		case 4:
			if(GK_D(HGEK_LEFT))
			  {
				  if(m_set.mode>0)
				      m_set.mode--;
				  else
					  m_set.mode=3;
  			  }
			else if(GK_D(HGEK_RIGHT))
			 {
			     if(m_set.mode<3)
				      m_set.mode++;
				  else
					  m_set.mode=0;
			 }
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=paramer[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=paramer[m_cur];
			}
		break;
		case 5:
			if(GK_D(HGEK_ENTER))
			  {
				 m_set.dificul=game->g_savedata->set.dificul;
				 m_set.ticket=game->g_savedata->set.ticket;
				 m_set.mincent=game->g_savedata->set.mincent;
				 m_set.maxcent=game->g_savedata->set.maxcent;
				 m_set.mode=game->g_savedata->set.mode;
  			  }
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=paramer[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=paramer[m_cur];
			}
		break;
		case 6:
			if(GK_D(HGEK_ENTER))
			  {
				   game->g_savedata->set.dificul=m_set.dificul;
				   game->g_savedata->set.ticket=m_set.ticket;
				   game->g_savedata->set.mincent=m_set.mincent;
				   game->g_savedata->set.maxcent=m_set.maxcent;
				   game->g_savedata->set.mode=m_set.mode;
				   game->g_toearn=ftoearn[m_set.dificul];
			       m_setwhat=SET_BEGIN;
				   m_cur=0;
				   m_curpos=menupos[0];
  			  }
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=paramer[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=paramer[m_cur];
			}
		break;
		case 7:
			if(GK_D(HGEK_ENTER))
			  {
			    m_setwhat=SET_BEGIN;
				m_cur=0;
				m_curpos=menupos[0];
  			  }
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=paramer[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur=0;
				m_curpos=paramer[m_cur];
			}
		break;
	}
}


void G_Set::GetSaveSet(SaveData* save)
{
	m_set=save->set;
}


void G_Set::SetBegin(void)
{
	for(int i=0;i<4;i++)
		m_sprsetback[i]->Render(backpos[i].x,backpos[i].y);
	for(int i=0;i<6;i++)
		m_sprmenu[i]->Render(menupos[i].x,menupos[i].y);

	if(m_bwin)
	    PassWord();
	else
		m_sprcur[0]->Render(m_curpos.x,m_curpos.y);
	switch(m_cur)
	{
		case 0://参数调整
			if(GK_D(HGEK_ENTER))
			  {
			    m_setwhat=SET_PARAMER;
				m_cur=0;
				m_curpos=paramer[m_cur];
  			  }
			else if(GK_D(HGEK_UP))
			{
				m_cur=5;
				m_curpos=menupos[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=menupos[m_cur];
			}
			break;
		case 1://解码调整
			if(GK_D(HGEK_ENTER))
				game->m_gamesta=GAME_SET;
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=menupos[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=menupos[m_cur];
			}
			break;
		case 2://查账
			if(GK_D(HGEK_ENTER))
				m_setwhat=SET_AUDIT;
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=menupos[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=menupos[m_cur];
			}
			break;
		case 3://报账
			if(GK_D(HGEK_ENTER))
			{
				m_bwin=true;
				m_cur=6;
				m_passwin=2;
				m_curpos.x=passwin[m_passwin].x+100;
				m_curpos.y=passwin[m_passwin].y;
			}
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=menupos[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=menupos[m_cur];
			}
			break;
		case 4://系统设置
			if(GK_D(HGEK_ENTER))
				game->m_gamesta=GAME_SET;
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=menupos[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur++;
				m_curpos=menupos[m_cur];
			}
			break;
		case 5://退出
			if(GK_D(HGEK_ENTER))
			{
				game->m_gamesta=GAME_PLAYING;
				m_cur=0;
			}
			else if(GK_D(HGEK_UP))
			{
				m_cur--;
				m_curpos=menupos[m_cur];
			}
			else if(GK_D(HGEK_DOWN))
			{
				m_cur=0;
				m_curpos=menupos[m_cur];
			}
			break;
		case 6://否
			if(GK_D(HGEK_ENTER))
			{
				  m_bwin=false;
				  m_cur=3;
				  m_curpos=menupos[3];
			}
			else if(GK_D(HGEK_LEFT)||GK_D(HGEK_RIGHT))
			{
				m_curpos.x-=200;
				m_cur=7;
			}
			break;
		case 7://是
			if(GK_D(HGEK_ENTER))
			 {
				  m_setwhat=SET_TELLAUDIT;
				  m_passwin=1;
				  m_cur=3;
				  m_curpos=menupos[3];
			 }
		    else if(GK_D(HGEK_LEFT)||GK_D(HGEK_RIGHT))
			{
				m_curpos.x+=200;
				m_cur=6;
			}
			break;
	}
}


void G_Set::Audit(void)
{
	int centin=game->g_savedata->centin/game->g_savedata->set.coincent;
	int centout=game->g_savedata->centout/game->g_savedata->set.coincent;
	int this_time_earn=centin-centout+game->g_savedata->coinin-game->g_savedata->coinout;
	int totalearn=this_time_earn+game->g_savedata->lastearn;
	for(int i=0;i<4;i++)
		m_sprsetback[i]->Render(backpos[i].x,backpos[i].y);
	m_sprmenu[2]->Render(400,80);
	m_spraudit->Render(720,400);
	m_sprmenu[5]->Render(1200,800);
	m_sprcur[0]->Render(1200,800);
	DrawNumsR(m_sprnum[2],totalearn,980,153,0,1,15,0);                                       //全部总盈利
	DrawNumsR(m_sprnum[2],game->g_savedata->lastearn,980,196,0,1,15,0);                      //上次总盈利
	DrawNumsR(m_sprnum[2],this_time_earn,980,240,0,1,15,0);                               //本次实际盈利
	DrawNumsR(m_sprnum[3],centin,980,290,0,1,15,0);                                         //总上分，币为单位
	DrawNumsR(m_sprnum[3],centout,980,331,0,1,15,0);                                              //总下分，币为单位
	DrawNumsR(m_sprnum[1],game->g_savedata->coinin,980,378,0,1,15,0);                              //总投币
	DrawNumsR(m_sprnum[1],game->g_savedata->coinout,980,423,0,1,15,0);                              //总退币
	DrawNumsR(m_sprnum[1],game->g_savedata->ticketout,980,471,0,1,15,0);
	DrawNumsR(m_sprnum[5], MachineNum,1000,515,0,1,15,0);
	DrawNumsR(m_sprnum[5], LineNum,1000,558,0,1,15,0);
	DrawNumsR(m_sprnum[5], game->g_savedata->lastcodesys.wMinute,955,605,0,1,15,0); 
	DrawNumsR(m_sprnum[5], game->g_savedata->codetimes,980,649,0,1,15,0);
	if(GK_D(HGEK_ENTER))
		m_setwhat=SET_BEGIN;
}


void G_Set::PassWord()
{
	m_sprpasswin[m_passwin]->Render(passwin[m_passwin].x,passwin[m_passwin].y);
	if(m_passwin==2)
	{
		m_spryesno[0]->Render(m_curpos.x,m_curpos.y);
		m_spryesno[1]->Render(passwin[m_passwin].x+100,passwin[m_passwin].y);
		m_spryesno[2]->Render(passwin[m_passwin].x-100,passwin[m_passwin].y);
	}
	else
	{
		for(int i=0;i<m_num;i++)
	      {
			if(i!=m_line)
				DrawNums(m_sprnum[9],cinnum[i],tellpos[i].x,tellpos[i].y,0,1,0,0);
			else if(time%40<30)
				DrawNums(m_sprnum[9],cinnum[i],tellpos[i].x,tellpos[i].y,0,1,0,0);
	      }
		if(time%40<30)
	      m_sprnumline[0]->Render(tellpos[m_line].x,tellpos[m_line].y+50); 

			for(int i=0;i<8;i++)
			{
			  if(i==m_line)
			  {
				  ScanNum(i);
				  break;
			  }
			}
		if(m_num==8&&GK_D(HGEK_ENTER))
		{
		  m_bcoding=true;
		  m_brightcode=true;
		  m_bwin=false;
		  m_line=0;
		}
		   
	}
}


void G_Set::SetHitCode(void)
{

}

void G_Set::SetTellAudit(void)
{
	for(int i=0;i<3;i++)
		m_sprsetback[i]->Render(backpos[i].x,backpos[i].y);
	m_sprmenu[3]->Render(backpos[3].x,backpos[3].y);
	for(int i=0;i<5;i++)
		m_sprtell[i]->Render(735,150+50.0f*i);
	if(m_bwin)
		PassWord();
	if(m_bcoding)
	{
		m_sprtell[7]->Render(600,450);
		for(int i=0;i<8;i++)
			DrawNumsR(m_sprnum[2],cinnum[i],620+30.0f*i,450,0,2,30,0);
		m_sprtell[8]->Render(600,500);
		if(m_brightcode)
		{
			m_sprtell[6]->Render(600,600);
			DrawNumsR(m_sprnum[2],10-m_codingtime/30,650,600,0,1,15,0);
		}
		else
		{
			m_sprtell[5]->Render(600,600);
			DrawNumsR(m_sprnum[2],10-m_codingtime/30,650,600,0,1,15,0);
		}
		if(m_codingtime<300)
			m_codingtime++;
		else
		 {
			  if(m_brightcode)
			  {
				m_codingtime=0;
				m_bcoding=false;
				m_brightcode=false;
				m_cur=3;
				m_curpos=menupos[3];
				m_setwhat=SET_BEGIN;
				cinnum.clear();
				m_num=0;
			  }
			  else
			  {
				m_codingtime=0;
				m_bwin=true;
				m_bcoding=false;
				cinnum.clear();
				m_num=0;
			  }
		 }
	}
}


void G_Set::ScanNum(int n)
{
	if(GK_D(HGEK_UP))
		{
			if(m_num<=n)
			{
				cinnum.push_back(0);
				m_num++;
			}
			else
			{
			if(cinnum[n]>0)
				cinnum[n]--;
			else 
				cinnum[n]=9;
			}
		}
		else if(GK_D(HGEK_DOWN))
		{
			if(m_num<=n)
			{
				cinnum.push_back(0);
				m_num++;
			}
			else
			{
				if(cinnum[n]<9)
					cinnum[n]++;
				else 
					cinnum[n]=0;
			}
		}
		else if(GK_D(HGEK_LEFT))
		{
			if(n>0)
		      m_line--;
		}
		else if(GK_D(HGEK_RIGHT))
		{
			if(n<m_num&&n<7)
		      m_line++;
		}
}
