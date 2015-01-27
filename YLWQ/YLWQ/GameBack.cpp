#include "main.h"
#include "GameBack.h"
//ÓÎÏ·±³¾°äÖÈ¾
GameBack::GameBack(void)
{
	m_sta=BACK_1;
	m_bwave=false;
}

GameBack::GameBack(HGE*phge)
{
	m_phge=phge;
	m_bwave=false;
	m_wavex=1440;
	m_sta=BACK_0;
	m_pptime=0;
	m_ppx=720;
	m_ppy=450;
	m_backtime=0;
}
GameBack::~GameBack(void)
{
	m_phge->Texture_Free(m_texhx);
	for(int i=0;i<3;i++)
	   m_phge->Texture_Free(m_texback[i]);
	for(int i=0;i<25;i++)
		m_phge->Texture_Free(m_texwater[i]);
	m_phge->Texture_Free(m_texhx);
	m_phge->Texture_Free(m_texwave);
	for(int i=0;i<6;i++)
		m_phge->Texture_Free(m_texsh[i]);
}


void GameBack::LoadTexture(void)
{
  m_phge->Resource_AttachPack("..\\resource\\PIC\\Back.zip",0);
  for(int i=0;i<3;i++)
   {
	  m_texback[i]=m_phge->Texture_Load(cTex[i]);
	  m_sprback[i]=new hgeSprite(m_texback[i],0,0,1440,900);
	  m_sprback[i]->SetZ(1.0f);
   }
  //º£ÐÇ
   m_texhx=m_phge->Texture_Load(cTex[4]);
     for(int i=0;i<24;i++)
   {
     m_sprhx[i]=new hgeSprite(m_texhx,i*107.0f,0,107,107);
	 m_sprhx[i]->SetZ(0.9f);
   }
//Éºº÷
   for(int i=0;i<6;i++)
	   m_texsh[i]=m_phge->Texture_Load(cTex[i+5]);
   for(int i=0;i<24;i++)
   {
     m_sprsh0[i]=new hgeSprite(m_texsh[0],i*126.0f,0,126,101);
	 m_sprsh1[i]=new hgeSprite(m_texsh[1],i*117.0f,0,117,154);
	 m_sprsh2[i]=new hgeSprite(m_texsh[2],i*194.0f,0,194,169);
	 m_sprsh0[i]->SetZ(0.9f);
	 m_sprsh1[i]->SetZ(0.9f);
	 m_sprsh2[i]->SetZ(0.9f);
	 
	 if(i<22)
	 {
	   m_sprsh3[i]=new hgeSprite(m_texsh[3],i*80.0f,0,80,95);
	   m_sprsh3[i]->SetZ(0.9f);
	   m_sprsh33[i]=new hgeSprite(m_texsh[3],i*80.0f,0,80,95);
	   m_sprsh33[i]->SetZ(0.9f);
	   m_sprsh4[i]=new hgeSprite(m_texsh[4],i*315.0f,0,315,155);
	   m_sprsh4[i]->SetZ(0.9f);
	 }
   }
   for(int i=0;i<9;i++)
   {
     m_sprsh5[i]=new hgeSprite(m_texsh[5],i*295.0f,0,295,314);
	 m_sprsh5[i]->SetZ(0.9f);
	 
   }
   //²¨ÀË
   m_texwave=m_phge->Texture_Load(cTex[3]);
   m_sprwave[0]=new hgeSprite(m_texwave,0,0,376,900);
   m_sprwave[1]=new hgeSprite(m_texwave,376,0,376,900);
   m_sprwave[0]->SetZ(0.25f);
   m_sprwave[1]->SetZ(0.25f);
   //Ë®²Ý
   for(int i=0;i<3;i++)
	   m_texsc[i]=m_phge->Texture_Load(cTex[11+i]);
   for(int i=0;i<24;i++)
   {
      m_sprsc0[i]=new hgeSprite(m_texsc[0],i*300.0f,0,300,203);
	  m_sprsc0[i]->SetZ(0.9f);
	  m_sprsc01[i]=new hgeSprite(m_texsc[0],i*300.0f,0,300,203);
	  m_sprsc01[i]->SetZ(0.9f);
	  m_sprsc02[i]=new hgeSprite(m_texsc[0],i*300.0f,0,300,203);
	  m_sprsc02[i]->SetZ(0.9f);
   }
   for(int i=0;i<16;i++)
   {
	  m_sprsc2[i]=new hgeSprite(m_texsc[2],i*174.0f,0,174,250);
	  m_sprsc2[i]->SetZ(0.9f);
   }

   //Ë®ÅÝ
   m_texpp=m_phge->Texture_Load(cTex[14]);
   for(int i=0;i<20;i++)
   {
     m_sprpp[i]=new hgeSprite(m_texpp,i*240.0f,0,240,400);
	 m_sprpp[i]->SetZ(0.89f);
	 m_sprpp[i]->SetHotSpot(120,200);
   }
  //Ë®²¨
   m_phge->Resource_AttachPack("..\\resource\\PIC\\Water.zip",0);
   for(int i=0;i<27;i++)
   {
	   m_texwater[i]=m_phge->Texture_Load(cTex[i]);
	   m_sprwater[i]=new hgeSprite(m_texwater[i],0,0,1440,900);
	   m_sprwater[i]->SetZ(0.8f);
	   //m_sprwater[i]->SetColor(0xccffffff);
   }
  m_phge->Resource_RemoveAllPacks();
}


void GameBack::RenderBack(G_Fish*pfish)
{
	 switch(m_sta)
	 {
	 case BACK_0:
		 if(m_bwave)
		 {
		   //0
		   m_sprback[0]->Render(0,0);
		   m_sprhx[time%24]->Render(490,340);
		   m_sprsh33[time%22]->RenderEx(450,200,3*PI/4,0.8f,0.8f);
		   m_sprsh4[time%22]->Render(210,630);
		   m_sprsh5[time%9]->Render(800,300);

		   //1
		   m_sprback[1]=new hgeSprite(m_texback[1],m_wavex,0,1440-m_wavex,900);
		   m_sprback[1]->SetZ(0.85f);

		   m_sprback[1]->Render(m_wavex,0);
		   if(m_wavex<200)
		   {
			  m_sprsh0[time%24]->SetZ(0.8f);
		      m_sprsh0[time%24]->Render(100,100);
		   }
		   if(m_wavex<900)
		   {
			  m_sprsh1[time%24]->SetZ(0.8f);
		      m_sprsh1[time%24]->Render(800,300);
		   }
		   if(m_wavex<1200)
		   {
			  m_sprsh2[time%24]->SetZ(0.8f);
		      m_sprsh2[time%24]->Render(1100,650);
		   }
		   if(m_wavex<330)
		   {
			  m_sprsh3[time%22]->SetZ(0.8f);
		      m_sprsh3[time%22]->Render(230,650);
		   }
		   //²Ý
		   if(m_wavex<560)
		   {
			  m_sprsc0[time%24]->SetZ(0.8f);
		      m_sprsc0[time%24]->RenderEx(460,800,-PI/2,0.5f,0.5f);
		   }
		   if(m_wavex<780)
		   {
			   m_sprsc2[time%16]->SetZ(0.8f);
			   m_sprsc2[time%16]->Render(680,250);
		   }
		   if(m_wavex<1020)
		   {
			  m_sprsc01[time%24]->SetZ(0.8f);
			  m_sprsc01[time%24]->Render(920,480);
		   }
		   m_sprwave[time%2]->Render(m_wavex-100,0);
		   m_wavex-=12;
		   if(m_wavex<-476)
		   {
			   m_bwave=false;
			   pfish->m_bchangesta=true;
			   pfish->m_fisharray=1+rand()%8;
			   m_sta=BACK_1;
			   m_wavex=1440;
			   m_sprback[1]=new hgeSprite(m_texback[1],0,0,1440,900);
			   m_sprback[1]->SetZ(1.0f);
			   for(int i=0;i<24;i++)
			   {
					m_sprsh0[i]->SetZ(0.9f);
					m_sprsh1[i]->SetZ(0.9f);
					m_sprsh2[i]->SetZ(0.9f);

					if(i<16)
						m_sprsc2[i]->SetZ(0.9f);
					m_sprsc0[i]->SetZ(0.9f);
					m_sprsc01[i]->SetZ(0.9f);
					if(i<22)
					m_sprsh3[i]->SetZ(0.9f);
			   }
		   }
		 }
		 else
		 {
		    m_sprback[0]->Render(0,0);
		    m_sprhx[time%24]->Render(490,340);
		    m_sprsh3[time%22]->RenderEx(450,200,3*PI/4,0.8f,0.8f);
		    m_sprsh4[time%22]->Render(210,630);
		    m_sprsh5[time%9]->Render(800,300);
		 }
		 break;
	 case BACK_1:
		 if(m_bwave)
		 {
		   m_sprback[1]->Render(0,0);

		   m_sprsc0[time%24]->RenderEx(460,800,-PI/2,0.5f,0.5f);
		   m_sprsc2[time%16]->Render(680,250);
		   m_sprsc01[time%24]->Render(920,480);

		   m_sprsh0[time%24]->Render(100,100);
		   m_sprsh1[time%24]->Render(800,300);
		   m_sprsh2[time%24]->Render(1100,650);
		   m_sprsh3[time%22]->Render(230,650);

		   //2
		   m_sprback[2]=new hgeSprite(m_texback[2],m_wavex,0,1440-m_wavex,900);
		   m_sprback[2]->SetZ(0.85f);
		   m_sprback[2]->Render(m_wavex,0);
		   m_sprwave[(time/5)%2]->Render(m_wavex-100,0);
		   m_wavex-=12;

		   if(m_wavex<350)
		   {
			   m_sprsc02[time%24]->SetZ(0.8f);
		       m_sprsc02[time%24]->Render(250,520);
		   }
		   if(m_wavex<-476)
		   {
			   m_bwave=false;
			   pfish->m_bchangesta=true;
			   pfish->m_fisharray=1+rand()%8;
			   m_sta=BACK_2;
			   m_wavex=1440;
			   m_sprback[2]=new hgeSprite(m_texback[2],0,0,1440,900);
			   m_sprback[2]->SetZ(1.0f);

			   for(int i=0;i<24;i++)
				   m_sprsc02[i]->SetZ(0.9f);
		   }
		 }
		 else
		 {

		      m_sprback[1]->Render(0,0);
			  m_sprsc0[time%24]->RenderEx(460,800,-PI/2,0.5f,0.5f);
			  m_sprsc2[time%16]->Render(680,250);
			  m_sprsc01[time%24]->Render(920,480);

		      m_sprsh0[time%24]->Render(100,100);
		      m_sprsh1[time%24]->Render(800,300);
		      m_sprsh2[time%24]->Render(1100,650);
		      m_sprsh3[time%22]->Render(230,650);
		 }
		 break;
	 case BACK_2:
		 if(m_bwave)
		 {
		   //2
		   m_sprback[2]->Render(0,0);
		   m_sprsc02[time%24]->Render(250,520);
		   //0
		   m_sprback[0]=new hgeSprite(m_texback[0],m_wavex,0,1440-m_wavex,900);
		   m_sprback[0]->SetZ(0.85f);
		   m_sprback[0]->Render(m_wavex,0);
		   if(m_wavex<590)
		   {
			  m_sprhx[time%24]->SetZ(0.8f);
		      m_sprhx[time%24]->Render(490,340);
		   }
		   if(m_wavex<550)
		   {
			  m_sprsh3[time%22]->SetZ(0.8f);
		      m_sprsh3[time%22]->RenderEx(450,200,3*PI/4,0.8f,0.8f);
		   }
		   if(m_wavex<310)
		   {
			   m_sprsh4[time%22]->SetZ(0.8f);
		       m_sprsh4[time%22]->Render(210,630);
		   }
		   if(m_wavex<900)
		   {
			   m_sprsh5[time%9]->SetZ(0.8f);
		       m_sprsh5[time%9]->Render(800,300);
		   }
		   
		   m_sprwave[time%2]->Render(m_wavex-100,0);
		   m_wavex-=12;
		   if(m_wavex<-476)
		   {
			   m_bwave=false;
			   pfish->m_bchangesta=true;
			   pfish->m_fisharray=1+rand()%8;
			   m_sta=BACK_0;
			   m_wavex=1440;
			   m_sprback[0]=new hgeSprite(m_texback[0],0,0,1440,900);
			   m_sprback[0]->SetZ(1.0f);
			   for(int i=0;i<24;i++)
			   {
		         m_sprhx[i]->SetZ(0.9f);
				 if(i<22)
				 {
		           m_sprsh33[i]->SetZ(0.9f);
		           m_sprsh4[i]->SetZ(0.9f);
				 }
				   if(i<9)
		           m_sprsh5[i]->SetZ(0.9f);
			   }
		   }
		 }
		 else
		 {
		    m_sprback[2]->Render(0,0);
			m_sprsc02[time%24]->Render(250,520);
		 }
		 break;
	 }
	 if(m_pptime<120)
		{
		   if(m_pptime<60)
		      m_sprpp[m_pptime/3]->Render(m_ppx,m_ppy);
		   m_pptime++;
		}
	  else
		{
		   m_pptime=0;
		   m_ppx=m_phge->Random_Float(400,1000);
		   m_ppy=m_phge->Random_Float(200,700);
		}
}



void GameBack::RenderWater(void)
{
	m_sprwater[(m_backtime/2)%27]->Render(0,0);
	 m_backtime++;
}
