#include "main.h"
#include "Player.h"
Player::Player(void)
{
}

Player::Player(HGE*phge,int id, GCom * com , SaveData * savedata , SYSTEMTIME * psys)
{
	m_phge = phge;
	m_com = com;
	m_savedata = savedata;
	m_sys = psys;
	m_id = id;
	m_wincent=0;
	m_bgun0=true;
	m_lguntime=0;
	m_blgun=false;
	m_lgunrot=0;
	m_t0=m_t1=0;
	//设置玩家炮筒角度
	m_rot=PI/2;
	m_bullet.id=id;
	m_bullet.time=0;
	m_bullet.sta=BULLET_FIRE;
	m_numbullet=m_numdcoin=0;
	m_gunlevel=1;
	m_cent=m_savedata->playercent[m_id];
	if(m_cent>0)
	    m_benoughcoin=true;
	else
		m_benoughcoin=false;
}
Player::~Player(void)
{
}


void Player::LoadTexture()
{
	//加载UI图片
	m_phge->Resource_AttachPack("PIC\\UI.zip",0);
	m_texCentCircle=m_phge->Texture_Load(cTex[0]);
	m_sprCentCircle=new hgeSprite(m_texCentCircle,m_id*204.0f,0,204,63);
	m_sprCentCircle->SetHotSpot(102,31.5f);
	m_sprCentCircle->SetZ(0.2f);

	m_texnet=m_phge->Texture_Load(cTex[1]);
	m_sprnet=new hgeSprite(m_texnet,m_id*282.0f,0,282,282);
	m_sprnet->SetHotSpot(141,141);
	m_sprnet->SetZ(0.1f);
	m_texnetw=m_phge->Texture_Load(cTex[23]);
	for(int i=0;i<13;i++)
	{
	  m_sprnetw[i]=new hgeSprite(m_texnetw,i*400.0f,0,400,400);
	  m_sprnetw[i]->SetHotSpot(200,200);
	  m_sprnetw[i]->SetZ(0.11f);
	  //m_sprnetw[i]->SetColor(0xaaffffff);
	}
	m_texbullet=m_phge->Texture_Load(cTex[2]);
	m_sprbullet[0]=new hgeSprite(m_texbullet,m_id*48.0f,0,24,39);
	m_sprbullet[1]=new hgeSprite(m_texbullet,m_id*48.0f+24,0,24,39);
	m_sprbullet[0]->SetHotSpot(12,19.5f);
	m_sprbullet[1]->SetHotSpot(12,19.5f);
	m_sprbullet[0]->SetZ(0.1f);
	m_sprbullet[1]->SetZ(0.1f);

	m_texlbullet=m_phge->Texture_Load(cTex[8]);
	m_sprlbullet[0]=new hgeSprite(m_texlbullet,0,0,47,62);
	m_sprlbullet[1]=new hgeSprite(m_texlbullet,47,0,47,62);
	m_sprlbullet[0]->SetHotSpot(23.5f,31);
	m_sprlbullet[1]->SetHotSpot(23.5f,31);
	m_sprlbullet[0]->SetZ(0.1f);
	m_sprlbullet[1]->SetZ(0.1f);

	m_texlnet=m_phge->Texture_Load(cTex[9]);
	m_sprlnet=new hgeSprite(m_texlnet,0,0,300,300);
	m_sprlnet->SetHotSpot(150,150);
	m_sprlnet->SetZ(0.1f);

	m_texcoin=m_phge->Texture_Load(cTex[3]);
	for(int i=0;i<8;i++)
	{
		m_sprcoin[i]=new hgeSprite(m_texcoin,i*39.0f,0,39,39);
		m_sprcoin[i]->SetZ(0.19f);
		m_sprcoin[i]->SetHotSpot(19.5f,19.5f);
	}

	m_texfort=m_phge->Texture_Load(cTex[12+m_id]);
	for(int i=0;i<20;i++)
	 {
		m_sprfort[i]=new hgeSprite(m_texfort,i*94.980f,0,94.98f,188);
		m_sprfort[i]->SetHotSpot(47.5f,94);
		m_sprfort[i]->SetZ(0.11f);
	 }

	m_texgun=m_phge->Texture_Load(cTex[10]);
	m_sprgun[1]=new hgeSprite(m_texgun,0,0,53,110);
	m_sprgun[1]->SetHotSpot(26.5f,75);
	m_sprgun[1]->SetZ(0.1f);
	m_sprgun[0]=new hgeSprite(m_texgun,53,0,53,110);
	m_sprgun[0]->SetHotSpot(26.5f,80);
	m_sprgun[0]->SetZ(0.1f);

	m_texlgunmark=m_phge->Texture_Load(cTex[7]);
	m_texlgun[0]=m_phge->Texture_Load(cTex[27]);
	m_texlgun[1]=m_phge->Texture_Load(cTex[28]);
	m_sprlgun[0]=new hgeSprite(m_texlgun[0],0,0,66,129);
	m_sprlgun[0]->SetHotSpot(33,95);
	m_sprlgun[0]->SetZ(0.1f);
	m_sprlgun[1]=new hgeSprite(m_texlgun[1],0,0,66,129);
	m_sprlgun[1]->SetHotSpot(33,90);
	m_sprlgun[1]->SetZ(0.1f);
	m_sprlgunmark=new hgeSprite(m_texlgunmark,0,0,80,121);
	m_sprlgunmark->SetHotSpot(40,121);
	m_sprlgunmark->SetZ(0.0f);
	m_texgunfire=m_phge->Texture_Load(cTex[11]);
	for(int i=0;i<3;i++)
	{
	     m_sprgunfire[i]=new hgeSprite(m_texgunfire,i*69.0f,0,69,63);
		 m_sprgunfire[i]->SetHotSpot(34.5f,31.5f);
		 m_sprgunfire[i]->SetZ(0.1f);
	}

	m_texnum1=m_phge->Texture_Load(cTex[18]);
	m_texnum2=m_phge->Texture_Load(cTex[19]);
	m_texnum3=m_phge->Texture_Load(cTex[20]);
	m_texnum4=m_phge->Texture_Load(cTex[21]);
	m_texnum5=m_phge->Texture_Load(cTex[22]);
	for(int i=0;i<10;i++)
	{
	  m_sprnum1[i]=new hgeSprite(m_texnum1,i*10.4f,0,10.4f,14);
	  m_sprnum1[i]->SetHotSpot(5.2f,7);
	  m_sprnum1[i]->SetZ(0.1f);
	  m_sprnum2[i]=new hgeSprite(m_texnum2,i*25.0f,0,25,32);
	  m_sprnum2[i]->SetHotSpot(12.5f,16);
	  m_sprnum2[i]->SetZ(0);
	  m_sprnum3[i]=new hgeSprite(m_texnum3,i*16.0f,0,16,23);
	  m_sprnum3[i]->SetHotSpot(8,11.5f);
	  m_sprnum3[i]->SetZ(0);
	  m_sprnum4[i]=new hgeSprite(m_texnum4,i*44.0f,0,44,60);
	  m_sprnum4[i]->SetHotSpot(22,30);
	  m_sprnum4[i]->SetZ(0);
	  m_sprnum5[i]=new hgeSprite(m_texnum5,i*13.0f,0,13,17);
	  m_sprnum5[i]->SetHotSpot(6.5f,8.5f);
	  m_sprnum5[i]->SetZ(0);
	}

	m_texcoinj[0]=m_phge->Texture_Load(cTex[4]);
	m_texcoinj[1]=m_phge->Texture_Load(cTex[5]);
	m_texcoiny=m_phge->Texture_Load(cTex[6]);
	m_texcj=m_phge->Texture_Load(cTex[24]);
	m_texcoind[0]=m_phge->Texture_Load(cTex[25]);
	m_texcoind[1]=m_phge->Texture_Load(cTex[26]);

	for(int i=0;i<18;i++)
	{
	  m_sprcoinj0[i]=new hgeSprite(m_texcoinj[0],82.0f*i,0,82,79);
	  m_sprcoinj0[i]->SetHotSpot(41,39.5f);
	  m_sprcoinj0[i]->SetZ(0.0f);
	}

	for(int i=0;i<7;i++)
	{
	  m_sprcoinj1[i]=new hgeSprite(m_texcoinj[1],82.0f*i,0,82,79);
	  m_sprcoinj1[i]->SetHotSpot(41,39.5f);
	  m_sprcoinj1[i]->SetZ(0.0f);
	}

	for(int i=0;i<6;i++)
	{
	  m_sprcoiny[i]=new hgeSprite(m_texcoiny,55.0f*i,0,55,55);
	  m_sprcoiny[i]->SetHotSpot(22.5f,22.5f);
	  m_sprcoiny[i]->SetZ(0.0f);
	}

	for(int i=0;i<9;i++)
	{
	  m_sprcj[i]=new hgeSprite(m_texcj,288.0f*i,0,288,286);
	  m_sprcj[i]->SetHotSpot(144,143);
	  m_sprcj[i]->SetZ(0.0f);
	}

	for(int i=0;i<4;i++)
	{
	  m_sprcoind[i]=new hgeSprite(m_texcoind[1],36.0f*i,0,36,38);
	  m_sprcoind[i]->SetHotSpot(18,19);
	  m_sprcoind[i]->SetZ(0.0f);
	}
	m_sprcoind[4]=new hgeSprite(m_texcoind[0],0,0,34,7);
	m_sprcoind[4]->SetHotSpot(17,3.5f);
	m_sprcoind[4]->SetZ(0.0f);

	m_phge->Resource_RemoveAllPacks();
}

void Player::Render(float x, float y,float rot,G_Fish*pfish)
{
	  m_t1=timeGetTime();
	  m_x=x-cos(rot)*20;
	  m_y=y-sin(rot)*20;
	  m_sprfort[time%20]->RenderEx(x,y,rot,1,1);

	  DrawNums(m_sprnum3,m_gunlevel,m_x,m_y,m_rot,0.8f,cos(m_rot)*12,sin(m_rot)*12);
	  m_sprCentCircle->RenderEx(x-sin(rot)*200-cos(rot)*10,y+cos(rot)*200-sin(rot)*10,rot+PI/2,1,1);
	  m_sprcoin[time%8]->RenderEx(x-sin(rot)*130-cos(rot)*10,y+cos(rot)*130-sin(rot)*10,rot,1,1);
	  DrawNumsR(m_sprnum2,m_cent,x-sin(rot)*280-cos(rot)*10,y+cos(rot)*280-sin(rot)*10,rot+PI/2,1,cos(rot+PI/2)*20,sin(rot+PI/2)*20);

	  DrawNums(m_sprnum3,m_gunlevel,m_x,m_y,m_rot,0.8f,cos(m_rot)*12,sin(m_rot)*12);

	  if(m_cent-m_gunlevel>=0&&m_cent>0)
		  m_benoughcoin=true;
	  else
		  m_benoughcoin=false;
	  if(m_blgun)
	  {
	    if(m_lguntime<5)
		{
			m_sprlgunmark->RenderEx(m_lgunmarkx,m_lgunmarky,rot+PI/2,1,1);
			m_sprgun[1]->RenderEx(m_x,m_y,m_rot,1,1);
		}
		else if(m_lguntime<15)
		{
		  m_sprlgunmark->RenderEx(m_lgunmarkx+cos(rot)*50,m_lgunmarky+sin(rot)*50,rot+PI/2,1,1);
		  m_sprgun[1]->RenderEx(m_x,m_y,m_rot,1,1);
		}
		else if(m_lguntime<20)
		{
		   m_sprlgunmark->RenderEx(m_lgunmarkx,m_lgunmarky,rot+PI/2,1,1);
		   m_sprgun[1]->RenderEx(m_x,m_y,m_rot,1,1);
		}
		else if(m_lguntime<35)
		{
		   m_sprlgunmark->RenderEx(m_lgunmarkx+(m_lguntime-20)*(m_x-m_lgunmarkx)/15.0f,
			   m_lgunmarky+(m_lguntime-20)*(m_y-m_lgunmarky)/15.0f,rot+PI/2,1-1.0f/(m_lguntime-15),1-1.0f/(m_lguntime-15));
		   m_sprgun[1]->RenderEx(m_x,m_y,m_rot,1,1);
		}
		else if(m_lguntime<1000)
		{
		   m_sprlgunmark->RenderEx(m_x-sin(rot)*80+cos(rot)*80+cos(m_lgunrot)*3,m_y+cos(rot)*80+sin(rot)*80+sin(m_lgunrot)*3,rot+PI/2,0.7f,0.6f);
		   if(m_lguntime<36)
			   m_phge->Effect_PlayEx(game->g_eff[5],100,0,1.0f,false);
		   if(m_bgun0)
		       m_sprlgun[0]->RenderEx(m_x,m_y,m_rot,1,1);
		   else
			   m_sprlgun[1]->RenderEx(m_x,m_y,m_rot,1,1);
		   m_lgunrot+=3*g_t*PI;
		}
		else
		{
		  m_lguntime=0;
		  m_blgun=false;
		}
		m_lguntime++;
	  }
	  else
	  {
		    if(m_bgun0)
			   m_sprgun[0]->RenderEx(m_x,m_y,m_rot,1,1);
		    else
			   m_sprgun[1]->RenderEx(m_x,m_y,m_rot,1,1);
	  }
	  //接收键盘事件
	  if((m_id==0&&KEY_DOWN('A'))||(m_id==1&&KEY_DOWN(VK_LEFT)))
	  //if(game->g_com->GK_Down(m_id+1,0xf7,0xc2))//
	  {
		  if(m_rot>rot)
		    m_rot-=g_t*PI;
	  }
	  if((m_id==0&&KEY_DOWN('D'))||(m_id==1&&KEY_DOWN(VK_RIGHT)))
	  //if(game->g_com->GK_Down(m_id+1,0xfb,0xce))//
	  {
		  if(m_rot<rot+PI)
		    m_rot+=g_t*PI;
	  }

	  if((m_id==0&&PK_D(HGEK_F1))||(m_id==1&&PK_D(HGEK_F2)))
	   {
		   m_cent+=m_savedata->set.coincent;
		   m_savedata->centin+=m_savedata->set.coincent;
		  //m_savedata->coinin++;
	   }
	  if((m_id==0&&PK_D(HGEK_W))||(m_id==1&&PK_D(HGEK_UP)))
	   {
		  m_gunlevel+=1;
		  if(m_gunlevel>99)
			  m_gunlevel-=99;
		  m_phge->Effect_PlayEx(game->g_eff[6],100,0,1.0f,false);
	   }
	  if((m_id==0&&KEY_DOWN('J'))||(m_id==1&&KEY_DOWN(VK_DOWN)))
	  //if(game->g_com->GK_Down(m_id+1,0xfe,0xcb))//
		  {
			  if(m_t1-m_t0>300)//(t2-t1>350)//控制子连发弹的时间间隔
			  {
				  int num=0;
				  if(m_benoughcoin)
				  {
					  for(int i=0;i<m_numbullet;i++)
					  {
						  if(m_bullets[i].sta==BULLET_RUN)
							  num++;
					  }
					  if(num<15)//控制子弹在屏幕上的数量
					  {
							m_bullets.push_back(m_bullet);
							if(m_blgun)
							{
								m_bullets[m_numbullet].x=x-cos(rot)*20+sin(m_rot)*100;
								m_bullets[m_numbullet].y=y-sin(rot)*20-cos(m_rot)*100;
								m_phge->Effect_PlayEx(game->g_eff[2],50,0,1.0f,false);
							}
							else
							{
								m_bullets[m_numbullet].x=x-cos(rot)*20+sin(m_rot)*80;
								m_bullets[m_numbullet].y=y-sin(rot)*20-cos(m_rot)*80;
								m_phge->Effect_PlayEx(game->g_eff[4],50,0,1.0f,false);
							}
							m_bullets[m_numbullet].rot=m_rot;
							m_bullets[m_numbullet].vx=20*sin(m_rot);
							m_bullets[m_numbullet].vy=-20*cos(m_rot);
							m_bullets[m_numbullet].sta=BULLET_FIRE;
							m_numbullet++;
							m_cent-=m_gunlevel;
					  }
				   }
				  m_t0=m_t1;
			  }
		  }


   //渲染子弹
	  for(int i=0;i<m_numbullet;i++)
	  {
		  switch(m_bullets[i].sta)
		  {
			  case BULLET_FIRE:
				  if(m_bullets[i].time<6)
				  {
					  m_bgun0=false;
					  m_sprgunfire[m_bullets[i].time/2]->
						  RenderEx(m_bullets[i].x,m_bullets[i].y,m_bullets[i].rot,1,1);
					  
					  m_bullets[i].time++;
				  }
				  else
				  {
					  m_bgun0=true;
					  m_bullets[i].sta=BULLET_RUN;
					  m_bullets[i].time=0;
				  }
				  break;
			  case BULLET_RUN:
				  if(m_blgun)
				     m_sprlbullet[time%2]->
						  RenderEx(m_bullets[i].x,m_bullets[i].y,m_bullets[i].rot,1,1);
				  else
					  m_sprbullet[time%2]->
						  RenderEx(m_bullets[i].x,m_bullets[i].y,m_bullets[i].rot,1,1);
				  DrawNums(m_sprnum1,m_gunlevel,m_bullets[i].x,m_bullets[i].y,m_bullets[i].rot,
						  1,cos(m_bullets[i].rot)*8,sin(m_bullets[i].rot)*8);
				  m_bullets[i].x+=m_bullets[i].vx;
				  m_bullets[i].y+=m_bullets[i].vy;
				  if(m_bullets[i].x<20||m_bullets[i].x>1420)
				   {
					  m_bullets[i].vx*=-1;
					  m_bullets[i].rot+=-2*m_bullets[i].rot;
				   }
				  if(m_bullets[i].y<20||m_bullets[i].y>880)
				  {
					  m_bullets[i].vy*=-1;
					  m_bullets[i].rot+=PI-2*m_bullets[i].rot;
				  }
				 if(IsHitFish(pfish,&m_bullets[i],rot))
				 {
					 if(m_blgun)
					     m_phge->Effect_PlayEx(game->g_eff[3],50,0,1.0f,false);
					 else
						 m_phge->Effect_PlayEx(game->g_eff[8],50,0,1.0f,false);
				 }
				  break;
			  case BULLET_HIT:
				  if(m_bullets[i].time<13)
				  {
					  if(m_blgun)
					    m_sprlnet->Render(m_bullets[i].x+m_phge->Random_Float(-2,2),m_bullets[i].y+m_phge->Random_Float(-2,2));
					  else
					    m_sprnet->Render(m_bullets[i].x+m_phge->Random_Float(-2,2),m_bullets[i].y+m_phge->Random_Float(-2,2));
					  m_sprnetw[m_bullets[i].time]->Render(m_bullets[i].x,m_bullets[i].y);
					  m_bullets[i].time++;
				  }
				  else//打中鱼子弹消失，从容器中删除
				  {
					  vector<Bullet>::iterator it0=m_bullets.begin()+i;
					  vector<Bullet>::iterator it1=it0+1;
					  m_bullets.erase(it0,it1);
					  m_numbullet-=1;
					  i--;
				  }
				  break;
		  }
	    
	  }
	  //转盘
	  if(!m_phge->Channel_IsPlaying(m_chnwin))
		   m_wincent=0;
	  else
		 {
			m_sprcj[time%9]->RenderEx(m_x+cos(rot)*222,m_y+sin(rot)*222,rot+PI/2,1,1);
	        DrawNums(m_sprnum4,m_wincent,m_x+cos(rot)*222,m_y+sin(rot)*222,rot+PI/2,1,cos(rot+PI/2)*35,sin(rot+PI/2)*35);
		 }
	//渲染叠币，飞币
	 for(int i=0;i<m_numdcoin;i++)
	  {
		  m_ddcoin[i].time++;
		  //飞币
		  if(m_ddcoin[i].time<30)
		  {
			  float hvs;
			  if(m_ddcoin[i].fcoin[0].bj)
				  hvs=3.0f;
			  else
				  hvs=2;
			  if(m_ddcoin[i].time>7&&m_ddcoin[i].time<23)
				  DrawNums(m_sprnum5,m_ddcoin[i].cent,m_ddcoin[i].fcoin[m_ddcoin[i].fn/2].x+cos(rot)*50,
				  m_ddcoin[i].fcoin[m_ddcoin[i].fn/2].y+sin(rot)*50,
					  rot+PI/2,hvs,cos(rot+PI/2)*10*hvs,sin(rot+PI/2)*10*hvs);
			  else
				  DrawNums(m_sprnum5,m_ddcoin[i].cent,m_ddcoin[i].fcoin[m_ddcoin[i].fn/2].x,
					  m_ddcoin[i].fcoin[m_ddcoin[i].fn/2].y,
					  rot+PI/2,hvs,cos(rot+PI/2)*10*hvs,sin(rot+PI/2)*10*hvs);
		  }
		  else
		  {
			  for(int j=0;j<m_ddcoin[i].fn;j++)
			  {
				  if(m_ddcoin[i].fcoin[j].bfly)
				  {
					  if(m_ddcoin[i].fcoin[j].bj)
						   m_sprcoinj1[time%7]->RenderEx(m_ddcoin[i].fcoin[j].x,m_ddcoin[i].fcoin[j].y,rot+PI/2,1,1);
					  else
						   m_sprcoiny[time%6]->RenderEx(m_ddcoin[i].fcoin[j].x,m_ddcoin[i].fcoin[j].y,rot+PI/2,1,1);
					  bool hr0=abs(m_x-cos(rot)*50-m_ddcoin[i].fcoin[j].x)<=abs(m_ddcoin[i].fcoin[j].vx);
					  bool hr1=abs(m_y-sin(rot)*50-m_ddcoin[i].fcoin[j].y)<=abs(m_ddcoin[i].fcoin[j].vy);
					  if(!hr0)
						 m_ddcoin[i].fcoin[j].x+=m_ddcoin[i].fcoin[j].vx;
					  if(!hr1)
						 m_ddcoin[i].fcoin[j].y+=m_ddcoin[i].fcoin[j].vy;
					  if(hr0&&hr1)
					   {
						  //m_ddcoin[i].fcoin[j].bfly=false;
						   vector<FCoin>::iterator it0=m_ddcoin[i].fcoin.begin()+j;
						   vector<FCoin>::iterator it1=it0+1;
						   m_ddcoin[i].fcoin.erase(it0,it1);
						   m_ddcoin[i].fn--;
						   j--;
						   m_phge->Effect_PlayEx(game->g_eff[7],100,0,1.0f,false);
					   }
				  }
			  }
		  }
		  //叠币
		  if(m_ddcoin[i].id!=i)
			{
				if(m_ddcoin[i].move++==7)
				 {
					m_ddcoin[i].move=0;
					m_ddcoin[i].id=i;
				 }
				else
				{
					m_ddcoin[i].x-=sin(rot)*5;
					m_ddcoin[i].y+=cos(rot)*5;
				}
			 }
			 for(int j=0;j<m_ddcoin[i].dn;j++)
			  {
				  if(j>0&&!m_ddcoin[i].dcoin[j-1].brot)
				  {
					  if(m_ddcoin[i].dcoin[j].brot)
					  {
						  if(m_ddcoin[i].dcoin[j].time++<2)
							  m_sprcoind[m_ddcoin[i].time%4]->RenderEx(m_ddcoin[i].x+cos(rot)*j*7+cos(rot)*12,
							  m_ddcoin[i].y+sin(rot)*j*7+sin(rot)*12,
							  rot+PI/2,1,1);
						  else
							  m_ddcoin[i].dcoin[j].brot=false;
					  }
					  else                                                                                                                                                                                                                                                                                                              
					  {
						 m_sprcoind[4]->RenderEx(m_ddcoin[i].x+cos(rot)*j*7,
							 m_ddcoin[i].y+sin(rot)*j*7,
							 rot+PI/2,1,1);
					  }
				  }
				  m_sprcoind[4]->RenderEx(m_ddcoin[i].x,
					  m_ddcoin[i].y,
					  rot+PI/2,1,1);
			  }
		  if(!m_ddcoin[i].dcoin[m_ddcoin[i].dn-1].brot)
		   {
			  DrawNums(m_sprnum5,m_ddcoin[i].cent,m_ddcoin[i].x+cos(rot)*m_ddcoin[i].dn*7,
					m_ddcoin[i].y+sin(rot)*m_ddcoin[i].dn*7,
					rot+PI/2,1,cos(rot+PI/2)*10,sin(rot+PI/2)*10);
			   if(m_ddcoin[i].id==0&&i==0)
				 {
					 if(m_ddcoin[i].fcoin.size()==0||m_ddcoin[i].time>2000)
					 {
						  vector<DDCoin>::iterator it0=m_ddcoin.begin()+i;
						  vector<DDCoin>::iterator it1=it0+1;
						  m_ddcoin.erase(it0,it1);
						  m_numdcoin--;
						  //i--;
					 }
				 }
		    }
		  
	  }
}


bool Player::IsHitFish(G_Fish*gfish,pbullet bullet,float rot)
{
	for(int fn=0;fn<5;fn++)
	{
		for(int i=0;i<gfish->m_fishnum[fn];i++)
		{
			float k,c;//,k1;
			float x,y;//,x1,y1;
			float r,dr;//
			float w,dw;//
			w=gfish->m_fishes[fn].at(i).m_pdata->w/3.5f;
			r=gfish->m_fishes[fn].at(i).m_pdata->h/2*gfish->m_fishes[fn].at(i).m_pdata->h/2;
			if(r<1500)
				r=1500;
			if(w<40)
				w=40;
			dr=(bullet->y-gfish->m_fishes[fn].at(i).m_y)*(bullet->y-gfish->m_fishes[fn].at(i).m_y)+
				(bullet->x-gfish->m_fishes[fn].at(i).m_x)*(bullet->x-gfish->m_fishes[fn].at(i).m_x);//两点距离
			x=gfish->m_fishes[fn].at(i).m_x+sin(gfish->m_fishes[fn].at(i).m_rot+PI/2)*gfish->m_fishes[fn].at(i).m_pdata->h/2;
			y=gfish->m_fishes[fn].at(i).m_y-cos(gfish->m_fishes[fn].at(i).m_rot+PI/2)*gfish->m_fishes[fn].at(i).m_pdata->h/2;
			//x1=pfish->at(i).m_x+cos(pfish->at(i).m_rot+PI/2)*pfish->at(i).m_pdata->w/2;
			//y1=pfish->at(i).m_y+sin(pfish->at(i).m_rot+PI/2)*pfish->at(i).m_pdata->w/2;

			if(x-gfish->m_fishes[fn].at(i).m_x==0)
			{
				dw=abs(bullet->x-x);
			}
			else
			{
				k=(y-gfish->m_fishes[fn].at(i).m_y)/(x-gfish->m_fishes[fn].at(i).m_x);
				c=y-k*x;
				dw=abs(k*bullet->x-bullet->y+c)/sqrt(k*k+1);
			}
			//
			 if(dw<w&&dr<r&&gfish->m_fishes[fn].at(i).m_sta==FISH_RUN)
				{
					bullet->sta=BULLET_HIT;
					if(gfish->m_fishes[fn].at(i).m_bcanhit)
					{
					   gfish->m_fishes[fn].at(i).m_playerhit[m_id]+=1;
					  if(HitFishJL(&gfish->m_fishes[fn].at(i)))
					    {
					      m_cent+=gfish->m_fishes[fn].at(i).m_pdata->cent*m_gunlevel;
						  gfish->m_fishes[fn].at(i).m_sta=FISH_DIE;
						  m_phge->Effect_PlayEx(game->g_eff[0],100,0,1.0f,false);
						  if(gfish->m_fishes[fn].at(i).m_effid<15)
							  m_phge->Effect_PlayEx(game->g_eff1[gfish->m_fishes[fn].at(i).m_effid],100,0,1.0f,false);
						  InitCoins(&gfish->m_fishes[fn].at(i),rot);
					    }
					  }
				   return true;
				 }
			//
		}
	 }
	return false;
}

void Player::InitCoins(Fish*pfish,float rot)
{
	FCoin fc;
	DCoin dc;
	DDCoin ddc;
	ddc.x=m_x+sin(rot)*(100+35*m_numdcoin)-cos(rot)*20;
	ddc.y=m_y-cos(rot)*(100+35*m_numdcoin)-sin(rot)*20;
	ddc.fn=pfish->m_pdata->nfc;
	ddc.cent=pfish->m_pdata->cent*m_gunlevel;
	ddc.time=0;
	ddc.id=m_numdcoin;
	ddc.move=0;
	if(ddc.cent<100)
		ddc.dn=m_phge->Random_Int(5,10);
	else if(ddc.cent<500)
		ddc.dn=m_phge->Random_Int(10,17);
	else if(ddc.cent<1500)
		ddc.dn=m_phge->Random_Int(17,25);
	else
		ddc.dn=m_phge->Random_Int(25,35);

	float x=m_x-cos(rot)*50;//+sin(rot)*(i-pfish->m_pdata->nfc/2)*25.0f;
	float y=m_y-sin(rot)*50;//+cos(rot)*(i-pfish->m_pdata->nfc/2)*25.0f;
	for(int i=0;i<ddc.fn;i++)
	{
		fc.x=pfish->m_x+sin(rot)*(i-pfish->m_pdata->nfc/2)*60.0f-cos(rot)*m_phge->Random_Float(-20,20);
		fc.y=pfish->m_y+cos(rot)*(i-pfish->m_pdata->nfc/2)*60.0f-sin(rot)*m_phge->Random_Float(-20,20);
		fc.bfly=true;
		fc.bj=pfish->m_pdata->cent>9;
		if(fc.x==x)
		{
			fc.vx=0;
			if(y>fc.y)
				fc.vy=15;
			else
				fc.vy=-15;
		}
		else
		{
			if(x>fc.x)
				fc.vx=15;
			else
				fc.vx=-15;
			fc.vy=fc.vx*(y-fc.y)/(x-fc.x)*1.0f;
			if(abs(sin((y-fc.y)/sqrt((x-fc.x)*(x-fc.x)+(y-fc.y)*(y-fc.y))))>0.7f)
			 {
				if(y>fc.y)
				   fc.vy=15;
			    else
				   fc.vy=-15;
				fc.vx=fc.vy/((y-fc.y)/(x-fc.x))*1.0f;
			 }
		}
		ddc.fcoin.push_back(fc);
	}
	for(int i=0;i<ddc.dn;i++)
	{
		if(i==0)
		    dc.brot=false;
		else
			dc.brot=true;
		dc.time=0;
		ddc.dcoin.push_back(dc);
	}
	if(pfish->m_pdata->id==18||pfish->m_pdata->id==19)
	{
		m_wincent=ddc.cent;
		m_chnwin=m_phge->Effect_PlayEx(game->g_eff[9],100,0,1,false);
	}
	m_ddcoin.push_back(ddc);
	m_numdcoin++;
}

bool Player::HitFishJL(Fish*pfish)
{
	int allhit=0;
	float min,max;
	bool lgunjl=false;
	int playercoin=0;//所有玩家手上的分数
	int allin=0,allout=0;
	float percent=0;
	if(m_sys->wHour < 10)
		game->g_toearn=ftoearn[3];
	else
		game->g_toearn=ftoearn[game->g_savedata->set.dificul];
	for(int i=0;i<G_PLAYERNUM;i++)
		playercoin+=game->player[i]->m_cent/game->g_savedata->set.coincent;
	allin=game->g_savedata->coinin+game->g_savedata->centin;
	allout=playercoin+game->g_savedata->coinout+game->g_savedata->centout;
	percent=(float)(allin-allout)/allin;
	if(m_blgun)
	{
	   max=m_phge->Random_Float(pfish->m_pdata->cent*0.6f,pfish->m_pdata->cent*0.8f);
	   min=pfish->m_pdata->cent*0.4f;
	}
	else
	{
	  if(percent<0)//加难
		{
		  max=pfish->m_pdata->cent*1.0f;
		  min=m_phge->Random_Float(max*0.7f,max*0.9f);
		  lgunjl=rand()%500<1;
		}
		else if(percent<game->g_toearn)//正常
		{
	
		  max=pfish->m_pdata->cent*0.9f;
		  min=m_phge->Random_Float(max*0.5f,max*0.9f);
		  lgunjl=rand()%300<1;
		}
		else//放水
		{
			if((m_sys->wMinute/10)%6==m_id)
			{
		       max=pfish->m_pdata->cent*0.8f;
			   min=m_phge->Random_Float(max*0.4f,max*0.8f);
			}
			else
			{
		      max=pfish->m_pdata->cent*0.9f;
			  min=m_phge->Random_Float(max*0.5f,max*0.9f);
			}
		  lgunjl=rand()%200<1;
		}
	}
	for(int i=0;i<G_PLAYERNUM;i++)
		allhit+=pfish->m_playerhit[i];

	if(allhit<min)
		return false;
	else if(allhit<max)
	{
		if(percent>game->g_toearn)//已达盈率要求，可以送分
		{
		  if(lgunjl)
		   {
			  m_lgunmarkx=pfish->m_x;
			  m_lgunmarky=pfish->m_y;
			  m_blgun=true;
			  m_lguntime=0;
			  m_phge->Effect_PlayEx(game->g_eff[1],100,0,1.0f,false);
			}
		  return true;
		}
		else//没达到盈利要求，吃大赔小
		{
		   int allhitcent=0;
		   for(int i=0;i<G_PLAYERNUM;i++)
			   allhitcent+=game->player[i]->m_gunlevel*pfish->m_playerhit[i];
		   if(m_gunlevel*pfish->m_playerhit[m_id]<allhitcent*0.5f)
		     {
			    if(lgunjl)
				  {
					  m_lgunmarkx=pfish->m_x;
					  m_lgunmarky=pfish->m_y;
					  m_blgun=true;
					  m_lguntime=0;
					  m_phge->Effect_PlayEx(game->g_eff[1],100,0,1.0f,false);
				  }
				   return true;
		      }
		   return false;
		}
	}

	if(lgunjl)
	{
		m_lgunmarkx=pfish->m_x;
		m_lgunmarky=pfish->m_y;
		m_blgun=true;
		m_lguntime=0;
		m_phge->Effect_PlayEx(game->g_eff[1],100,0,1.0f,false);
	}
	return true;
}



