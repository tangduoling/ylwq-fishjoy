#include"main.h"
//渲染鱼群
Fish::Fish(void)
{
	m_x=(float)(rand()%1440);
	m_y=(float)(rand()%900);
}
Fish::Fish(hgeSprite***spr,pAnimationData pdata)
{
	m_spr=spr[pdata->id];
    m_pdata=pdata;
	m_effid=pdata->effid;
	if(pdata->effid<13)
		m_effid+=rand()%2;
	if(pdata->id==18||pdata->id==19)
		pdata->cent=hge->Random_Int(40,100);
	else if(pdata->id==7)
		pdata->cent=hge->Random_Int(5,30);
	m_bcanhit=true;
	m_teamhead=NULL;
	for(int i=0;i<6;i++)
		m_playerhit[i]=0;
	m_deadtime=0;
	m_sta=FISH_RUN;
	m_rot=0;
	m_torot=0;
	m_runmode=0;
	m_bchange=true;
	float rot=hge->Random_Float(0,2*PI);
	float r=hge->Random_Float(100,200);
	m_tox=720+cos(rot)*r;
	m_toy=450+sin(rot)*r;
	int dir=rand()%4;
	if(dir<1)
	  {
		  m_x=hge->Random_Float(0,1440);
		  m_y=-m_pdata->h/2;
	  }
	  else if(dir<2)
	  {
	     m_x=hge->Random_Float(0,1440);
	     m_y=900+m_pdata->h/2;
	  }
	  else if(dir<3)
	  {
	      m_y=hge->Random_Float(0,900);
	      m_x=-m_pdata->h/2;
	  }
	  else
	  {
	      m_y=hge->Random_Float(0,900);
	      m_x=1440+m_pdata->h/2;
	  }
}

Fish::~Fish(void)
{

}

void Fish::RenderFishArray1(void)
{
	m_spr[time%m_pdata->frames]->RenderEx(m_x,m_y,PI/2,1,1);
	m_x+=2;
}

void Fish::RenderFishArray2(void)
{
	  m_spr[time%m_pdata->frames]->RenderEx(m_x,m_y,m_rot+PI/2,1,1);
	  m_x+=m_vx;
	  if(m_a==0)
		  m_y+=m_vy;
	  else
		  m_y=m_a*m_x+m_c;
}


void Fish::RenderFishArray0(void)
{
	RenderMode(m_runmode);
}


void Fish::ChangeWay(float x,float y,float vx,float vy)
{
	if(m_bchange)
	{
		m_bchange=false;
		 if(x==m_x)
		   {
				m_a=0;
				m_vx=0;
				if(y>m_y)
				{
					m_rot=PI/2;
					m_vy=vy;
				}
				else if(y<m_y)
				{
					m_vy=-vy;
					m_rot=-PI/2;
				}
				else
					m_vy=0;
			}
		  else
			{
				m_a=(y-m_y)/(x-m_x);
				m_c=m_y-m_a*m_x;
				if(x>m_x)
				 {
					  m_rot=atan(m_a);
					  m_vx=vx;
				 }
				else
				 {
					m_rot=atan(m_a)-PI;
					m_vx=-vx;
				 }
					if(abs(sin(m_rot))>0.7f)
					  {
						 if(y>m_y)
							 m_vy=vy;
						 else
							 m_vy=-vy;
						 m_vx=m_vy/tan(m_rot);
					  }
			}
	}
}

void Fish::ChangeWay()
{
	    m_runmode=1;
		if(m_teamhead!=NULL)
		{
			    m_tox=m_teamhead->m_tox;
				m_toy=m_teamhead->m_toy;
				m_vx=m_teamhead->m_vx;
				m_vy=0;
				if(m_vx>0)
				{
					m_a=-PI/2+m_rot;
					if(m_pdata->id==13)
			         {
						if(cos(m_rot+PI/2)!=0)
				            m_c=(m_tox-m_x)/cos(m_rot+PI/2);
						else
							m_c=(m_toy-m_y)/sin(m_rot+PI/2);
			         }
			        else
			          m_c=m_teamhead->m_c;
				}
				else
				{
					m_a=PI/2+m_rot;
					if(m_pdata->id==13)
			         {
						if(cos(m_rot+PI/2)!=0)
				            m_c=(m_tox-m_x)/cos(m_rot-PI/2);
						else
							m_c=(m_toy-m_y)/sin(m_rot-PI/2);
			         }
			        else
			          m_c=m_teamhead->m_c;
				}
				m_torot=m_teamhead->m_torot;

		}
		else
		{
			int dir=rand()%2;
			m_torot=hge->Random_Float(PI/3,3*PI/2);
			m_c=hge->Random_Float(100,500);
			if(dir==0)//顺时针
			{
			
				  m_tox=m_x+cos(m_rot+PI/2)*m_c;
				  m_toy=m_y+sin(m_rot+PI/2)*m_c;
				  m_a=-PI/2+m_rot;
				  m_vx=abs(asin(5/m_c));
				  m_vy=0;
			}
			else//逆时针
			{
				m_tox=m_x+cos(m_rot-PI/2)*m_c;
				m_toy=m_y+sin(m_rot-PI/2)*m_c;
				m_a=PI/2+m_rot;
			    m_vx=-abs(asin(5/m_c));
				m_vy=0;
			}
		}
}

void Fish::RenderMode(int mode)
{
	switch(mode)
	{
		case 0://直线运动
			         m_spr[time%m_pdata->frames]->RenderEx(m_x,m_y,m_rot+PI/2,1,1);
			   m_x+=m_vx;
			   if(m_a==0)
				   m_y+=m_vy;
			   else
				   m_y=m_a*m_x+m_c;

			      if((abs(m_tox-m_x)<=abs(m_vx))&&(abs(m_toy-m_y)<=abs(m_vy)))
					 {
						if(m_pdata->id==5)
						{
						   m_runmode=2;
						   m_torot=hge->Random_Float(-PI/2,PI/2);
						   if(rand()%2==0)
							   m_vx=abs(m_torot)/20;
						   else
							   m_vx=-abs(m_torot)/20;
						   m_vy=0;
						}
						else if(m_pdata->id!=7)	
							ChangeWay();//改曲路径
					  }
				   else if(m_pdata->id==5)
					  {
						  if(abs(m_tox-m_x)<50&&abs(m_vx)>2)
							  m_vx-=m_vx/(5*abs(m_vx));
						  if(abs(m_tox-m_x)<50&&abs(m_vy)>2)
							  m_vy-=m_vy/(5*abs(m_vy));
			           }
				if(m_x>1500+m_pdata->h/2||m_x<-m_pdata->h/2-50||m_y>1000+m_pdata->h/2||m_y<-m_pdata->h/2-50)
				        m_sta=FISH_DIS;
			break;
		case 1://曲线运动,此时m_vx代表转角速度,m_vy代表转过的总度数
			       m_spr[time%m_pdata->frames]->RenderEx(m_x,m_y,m_rot+PI/2,1,1);
			    m_a+=m_vx;
				m_x=m_tox+cos(m_a)*m_c;
				m_y=m_toy+sin(m_a)*m_c;
				m_rot+=m_vx;
				m_vy+=m_vx;
				if(abs(m_vy)>=abs(m_torot))
				   ChangeWay();//曲线路径
				if(m_x>1440+m_pdata->h/2||m_x<-m_pdata->h/2||m_y>900+m_pdata->h/2||m_y<-m_pdata->h/2)
				        m_sta=FISH_DIS;
			break;
		case 2://转弯
			   m_spr[time%m_pdata->frames]->RenderEx(m_x,m_y,m_rot+PI/2,1,1);
			m_rot+=m_vx;
			m_vy+=m_vx;
			if(abs(m_vy)>=abs(m_torot))
			 {
				float r=hge->Random_Float(400,600);
				m_bchange=true;
				m_runmode=0;
				m_a=tan(m_rot);
				m_c=m_y-m_a*m_x;
				m_tox=m_x+cos(m_rot)*r;
				m_toy=m_a*m_tox+m_c;
				ChangeWay(m_tox,m_toy,7,7);//直线
			 }
			break;
	}
}



void Fish::RenderDie(void)
{
	  if(m_pdata->dieframes==0)
	    {
			if(m_deadtime<30)
			{
				m_spr[m_deadtime%m_pdata->frames]->RenderEx(m_x,m_y,m_rot+PI/2,1,1);
				m_deadtime++;
			}
			else
				m_sta=FISH_DIS;
		}
		else
		{
			if(m_deadtime<30)
			{
				if(m_pdata->id>19&&m_pdata->id<23)//乌龟
				{
					m_spr[m_pdata->frames]->RenderEx(m_x,m_y,m_rot+PI/2,1,1);
					m_rot+=PI/5;
				}
				else
					m_spr[m_pdata->frames+m_deadtime%m_pdata->dieframes]->RenderEx(m_x,m_y,m_rot+PI/2,1,1);
				m_deadtime++;
			}
			else
				m_sta=FISH_DIS;
		}
}


void Fish::RenderFishArray3(int mode)
{
	switch(mode)
	{
		case 0://直线运动
			    m_spr[time%m_pdata->frames]->RenderEx(m_x,m_y,m_rot+PI/2,1,1);
			    m_x+=m_vx;
				m_y+=m_vy;
				if(m_x>1500+m_pdata->h/2||m_x<-m_pdata->h/2-50||m_y>1000+m_pdata->h/2||m_y<-m_pdata->h/2-50)
				        m_sta=FISH_DIS;
			break;
		case 1://曲线运动,此时m_vx代表转角速度,m_vy代表转过的总度数
			    m_spr[time%m_pdata->frames]->RenderEx(m_x,m_y,m_rot+PI/2,1,1);
			    m_a+=m_vx;
				m_x=m_tox+cos(m_a)*m_c;
				m_y=m_toy+sin(m_a)*m_c;
				m_rot+=m_vx;
				m_vy+=m_vx;
				if(abs(m_vy)>=abs(m_torot))
				{
					m_runmode=0;
					m_vx=cos(m_rot)*10;
					m_vy=sin(m_rot)*10;
				}
				if(m_x>1440+m_pdata->h/2||m_x<-m_pdata->h/2||m_y>900+m_pdata->h/2||m_y<-m_pdata->h/2)
				        m_sta=FISH_DIS;
			break;
		case 2:
			break;
	}
}
