#include "main.h"
#include "G_Fish.h"
//µ•∏ˆ”„
G_Fish::G_Fish(void)
{
	for(int i=0;i<5;i++)
	   m_fishnum[i]=0;
	m_fisharray=FISH_ARRAY0;
}

G_Fish::G_Fish(HGE*phge)
{
	for(int i=0;i<5;i++)
	   m_fishnum[i]=0;
	m_bchangesta=true;
	m_bleft=true;
	m_phge=phge;
	m_centx=0;
	m_centy=0;
	m_fisharray=FISH_ARRAY0;
	m_sprfish[0]=new hgeSprite*[9];//∞ﬂ”„
	m_sprfish[1]=new hgeSprite*[13];//∫⁄∞‡”„
	m_sprfish[2]=new hgeSprite*[13];//«Ôµ∂”„
	m_sprfish[3]=new hgeSprite*[36];//¥Ã”„
	m_sprfish[4]=new hgeSprite*[14];//∞◊ˆË”„
	m_sprfish[5]=new hgeSprite*[7];//–°≥Û”„
	m_sprfish[6]=new hgeSprite*[5];//¿∂…´–°”„
	m_sprfish[7]=new hgeSprite*[5];//∫⁄Õ≈
	m_sprfish[8]=new hgeSprite*[4];//ª∆…´–°”„
	m_sprfish[9]=new hgeSprite*[10];//XX”„
	m_sprfish[10]=new hgeSprite*[4];//Œ⁄‘Ù
	m_sprfish[11]=new hgeSprite*[8];//ø◊»∏”„
	m_sprfish[12]=new hgeSprite*[14];//ΩˆË”„
	m_sprfish[13]=new hgeSprite*[11];//–°∫Ï”„
	m_sprfish[14]=new hgeSprite*[8];//∫˚µ˚”„
	m_sprfish[15]=new hgeSprite*[12];//∆’Õ®µ∆”„
	m_sprfish[16]=new hgeSprite*[12];//—€æµµ∆”„
	m_sprfish[17]=new hgeSprite*[12];//ª®Œ∆µ∆”„
	m_sprfish[18]=new hgeSprite*[20];//π⁄æ¸¿∂ˆË”„
	m_sprfish[19]=new hgeSprite*[18];//¿∂ˆË”„
	m_sprfish[20]=new hgeSprite*[9];//≈˚∑Á∫£πÍ
	m_sprfish[21]=new hgeSprite*[7];//”Œ”æ»¶∫£πÍ
	m_sprfish[22]=new hgeSprite*[7];//∆’Õ®∫£πÍ
}

G_Fish::~G_Fish(void)
{
}

void G_Fish::LoadTexture(void)
{
    if(!m_phge->Resource_AttachPack("PIC\\Fishes.zip",0))
	   MessageBox(NULL,L"º”‘ÿÕº∆¨ ß∞‹",L"¥ÌŒÛÃ· æ",MB_OK); 
	for(int i=0;i<38;i++)
	{
		m_texfish[i]=m_phge->Texture_Load(cTex[i]);
		if(!m_texfish[i])
			MessageBox(NULL,L"º”‘ÿÕº∆¨ ß∞‹",L"¥ÌŒÛÃ· æ",MB_OK); 
	}
	//∞ﬂ”„
	for(int i=0;i<9;i++)
	{
		if(i<7)
		{
	      m_sprfish[0][i]=new hgeSprite(m_texfish[0],77.0f*i,0,77,98);
	      m_sprfish[0][i]->SetZ(0.88f);
	      m_sprfish[0][i]->SetHotSpot(33.5f,49);
		}
		else
		{
		  m_sprfish[0][i]=new hgeSprite(m_texfish[1],120.0f*(i-7),0,120,150);
	      m_sprfish[0][i]->SetZ(0.88f);
	      m_sprfish[0][i]->SetHotSpot(60,75);
		}
	}
	m_fishdata[0].id=0;
	m_fishdata[0].frames=7;
	m_fishdata[0].dieframes=2;
	m_fishdata[0].w=77;
	m_fishdata[0].h=98;
	m_fishdata[0].nfc=9;
	m_fishdata[0].cent=9;
	m_fishdata[0].effid=20;
	//∫⁄∞ﬂ”„
	for(int i=0;i<13;i++)
	{
		if(i<9)
		{
	      m_sprfish[1][i]=new hgeSprite(m_texfish[2],145.0f*i,0,145,283);
	      m_sprfish[1][i]->SetZ(0.88f);
	      m_sprfish[1][i]->SetHotSpot(72.5f,141.5f);
		}
		else
		{
		  m_sprfish[1][i]=new hgeSprite(m_texfish[3],139.0f*(i-9),0,139,279);
	      m_sprfish[1][i]->SetZ(0.88f);
	      m_sprfish[1][i]->SetHotSpot(69.5f,139.5f);
		}
	}
	m_fishdata[1].id=1;
	m_fishdata[1].frames=9;
	m_fishdata[1].dieframes=4;
	m_fishdata[1].w=145;
	m_fishdata[1].h=283;
	m_fishdata[1].nfc=3;
	m_fishdata[1].cent=15;
	m_fishdata[1].effid=4;
	//«Ôµ∂”„
	for(int i=0;i<13;i++)
	{
		if(i<10)
		{
	      m_sprfish[2][i]=new hgeSprite(m_texfish[4],184.0f*(i%5),448.0f*(i/5),184,448);
	      m_sprfish[2][i]->SetZ(0.88f);
	      m_sprfish[2][i]->SetHotSpot(92,224);
		}
		else
		{
		  m_sprfish[2][i]=new hgeSprite(m_texfish[5],195.0f*(i-10),0,195,439);
	      m_sprfish[2][i]->SetZ(0.88f);
	      m_sprfish[2][i]->SetHotSpot(97.5f,219.5f);
		}
	}
	m_fishdata[2].id=2;
	m_fishdata[2].frames=10;
	m_fishdata[2].dieframes=3;
	m_fishdata[2].w=184;
	m_fishdata[2].h=448;
	m_fishdata[2].nfc=4;
	m_fishdata[2].cent=18;
	m_fishdata[2].effid=6;

	//¥Ã”„
	for(int i=0;i<36;i++)
	{
		if(i<28)
		{
	      m_sprfish[3][i]=new hgeSprite(m_texfish[6],103.0f*(i%7),129.0f*(i/7),103,129);
	      m_sprfish[3][i]->SetZ(0.88f);
	      m_sprfish[3][i]->SetHotSpot(51.5f,64.5f);
		}
		else
		{
		  m_sprfish[3][i]=new hgeSprite(m_texfish[7],103.0f*((i-28)%3),129.0f*((i-28)/3),103,129);
	      m_sprfish[3][i]->SetZ(0.88f);
	      m_sprfish[3][i]->SetHotSpot(51.5f,64.5f);
		}
	}
	m_fishdata[3].id=3;
	m_fishdata[3].frames=28;
	m_fishdata[3].dieframes=8;
	m_fishdata[3].w=103;
	m_fishdata[3].h=129;
	m_fishdata[3].nfc=8;
	m_fishdata[3].cent=8;
	m_fishdata[3].effid=20;
	//∞◊ˆË”„
	for(int i=0;i<14;i++)
	{
		if(i<10)
		{
	      m_sprfish[4][i]=new hgeSprite(m_texfish[8],250.0f*i,0,250,494);
	      m_sprfish[4][i]->SetZ(0.88f);
	      m_sprfish[4][i]->SetHotSpot(125,247);
		}
		else
		{
		  m_sprfish[4][i]=new hgeSprite(m_texfish[9],258.0f*(i-10),0,258,430);
	      m_sprfish[4][i]->SetZ(0.88f);
	      m_sprfish[4][i]->SetHotSpot(129,215);
		}
	}
	m_fishdata[4].id=4;
	m_fishdata[4].frames=10;
	m_fishdata[4].dieframes=4;
	m_fishdata[4].w=250;
	m_fishdata[4].h=494;
	m_fishdata[4].nfc=5;
	m_fishdata[4].cent=25;
	m_fishdata[4].effid=10;
	//–°≥Û”„
	for(int i=0;i<7;i++)
	{
		if(i<5)
		{
	      m_sprfish[5][i]=new hgeSprite(m_texfish[10],49.0f*i,0,49,123);
	      m_sprfish[5][i]->SetZ(0.88f);
	      m_sprfish[5][i]->SetHotSpot(17.5f,61.5f);
		}
		else
		{
		  m_sprfish[5][i]=new hgeSprite(m_texfish[11],63.0f*(i-5),0,63,100);
	      m_sprfish[5][i]->SetZ(0.88f);
	      m_sprfish[5][i]->SetHotSpot(31.5f,50);
		}
	}
	m_fishdata[5].id=5;
	m_fishdata[5].frames=5;
	m_fishdata[5].dieframes=2;
	m_fishdata[5].w=49;
	m_fishdata[5].h=123;
	m_fishdata[5].nfc=7;
	m_fishdata[5].cent=7;
	m_fishdata[5].effid=20;

	//¿∂…´–°”„
	for(int i=0;i<5;i++)
	{
		if(i<3)
		{
	      m_sprfish[6][i]=new hgeSprite(m_texfish[12],54.0f*i,0,54,49);
	      m_sprfish[6][i]->SetZ(0.88f);
	      m_sprfish[6][i]->SetHotSpot(27,24.5f);
		}
		else
		{
		  m_sprfish[6][i]=new hgeSprite(m_texfish[13],65.0f*(i-3),0,65,69);
	      m_sprfish[6][i]->SetZ(0.88f);
	      m_sprfish[6][i]->SetHotSpot(32.5f,34.5f);
		}
	}
	m_fishdata[6].id=6;
	m_fishdata[6].frames=3;
	m_fishdata[6].dieframes=2;
	m_fishdata[6].w=54;
	m_fishdata[6].h=49;
	m_fishdata[6].nfc=2;
	m_fishdata[6].cent=2;
	m_fishdata[6].effid=20;
	//∫⁄Õ≈
	for(int i=0;i<5;i++)
	{
	  m_sprfish[7][i]=new hgeSprite(m_texfish[14],i*109.0f,0,109,128);
	  m_sprfish[7][i]->SetZ(0.87f);
	  m_sprfish[7][i]->SetHotSpot(54.5f,64);
	}
	m_fishdata[7].id=7;
	m_fishdata[7].frames=5;
	m_fishdata[7].dieframes=0;
	m_fishdata[7].w=109;
	m_fishdata[7].h=128;
	m_fishdata[7].nfc=5;
	m_fishdata[7].cent=10;
	m_fishdata[7].effid=20;

	//ª∆…´–°”„
	for(int i=0;i<4;i++)
	{
	  m_sprfish[8][i]=new hgeSprite(m_texfish[15],i*44.0f,0,44,51);
	  m_sprfish[8][i]->SetZ(0.88f);
	  m_sprfish[8][i]->SetHotSpot(44,51);
	}
	m_fishdata[8].id=8;
	m_fishdata[8].frames=4;
	m_fishdata[8].dieframes=0;
	m_fishdata[8].w=44;
	m_fishdata[8].h=51;
	m_fishdata[8].nfc=3;
	m_fishdata[8].cent=3;
	m_fishdata[8].effid=20;

	//XX”„
	for(int i=0;i<10;i++)
	{
	  m_sprfish[9][i]=new hgeSprite(m_texfish[16],(i%5)*299.0f,(i/5)*225.0f,299,225);
	  m_sprfish[9][i]->SetZ(0.88f);
	  m_sprfish[9][i]->SetHotSpot(149.5f,112.5f);
	}
	m_fishdata[9].id=9;
	m_fishdata[9].frames=10;
	m_fishdata[9].dieframes=0;
	m_fishdata[9].w=299;
	m_fishdata[9].h=225;
	m_fishdata[9].nfc=4;
	m_fishdata[9].cent=20;
	m_fishdata[9].effid=8;

	//Œ⁄‘Ù
	for(int i=0;i<4;i++)
	{
	  m_sprfish[10][i]=new hgeSprite(m_texfish[17],i*93.0f,0,93,114);
	  m_sprfish[10][i]->SetZ(0.88f);
	  m_sprfish[10][i]->SetHotSpot(46.5f,57);
	}
	m_fishdata[10].id=10;
	m_fishdata[10].frames=4;
	m_fishdata[10].dieframes=0;
	m_fishdata[10].w=93;
	m_fishdata[10].h=114;
	m_fishdata[10].nfc=5;
	m_fishdata[10].cent=5;
	m_fishdata[10].effid=20;
	//ø◊»∏”„
	for(int i=0;i<8;i++)
	{
		if(i<5)
		{
	      m_sprfish[11][i]=new hgeSprite(m_texfish[18],76.0f*i,0,76,139);
	      m_sprfish[11][i]->SetZ(0.88f);
	      m_sprfish[11][i]->SetHotSpot(38,69.5f);
		}
		else
		{
		  m_sprfish[11][i]=new hgeSprite(m_texfish[19],114.0f*(i-5),0,114,176);
	      m_sprfish[11][i]->SetZ(0.88f);
	      m_sprfish[11][i]->SetHotSpot(57,88);
		}
	}
	m_fishdata[11].id=11;
	m_fishdata[11].frames=5;
	m_fishdata[11].dieframes=3;
	m_fishdata[11].w=76;
	m_fishdata[11].h=139;
	m_fishdata[11].nfc=6;
	m_fishdata[11].cent=6;
	m_fishdata[11].effid=20;

	//ΩˆË”„
	for(int i=0;i<14;i++)
	{
		if(i<10)
		{
	      m_sprfish[12][i]=new hgeSprite(m_texfish[20],250.0f*i,0,250,494);
	      m_sprfish[12][i]->SetZ(0.88f);
	      m_sprfish[12][i]->SetHotSpot(125,247);
		}
		else
		{
		  m_sprfish[12][i]=new hgeSprite(m_texfish[21],224.0f*(i-10),0,224,430);
	      m_sprfish[12][i]->SetZ(0.88f);
	      m_sprfish[12][i]->SetHotSpot(112,215);
		}
	}
	m_sprmj=new hgeSprite(m_texfish[37],0,0,60,161);
	m_sprmj->SetZ(0.88f);
	m_sprmj->SetHotSpot(30,80.5f);
	m_fishdata[12].id=12;
	m_fishdata[12].frames=10;
	m_fishdata[12].dieframes=4;
	m_fishdata[12].w=250;
	m_fishdata[12].h=494;
	m_fishdata[12].nfc=6;
	m_fishdata[12].cent=30;
	m_fishdata[12].effid=12;

	//–°∫Ï”„
	for(int i=0;i<11;i++)
	{
		if(i<8)
		{
	      m_sprfish[13][i]=new hgeSprite(m_texfish[22],25.0f*i,0,25,60);
	      m_sprfish[13][i]->SetZ(0.88f);
	      m_sprfish[13][i]->SetHotSpot(12.5f,30);
		}
		else
		{
		  m_sprfish[13][i]=new hgeSprite(m_texfish[23],42.0f*(i-8),0,42,85);
	      m_sprfish[13][i]->SetZ(0.88f);
	      m_sprfish[13][i]->SetHotSpot(21,42.5f);
		}
	}
	m_fishdata[13].id=13;
	m_fishdata[13].frames=8;
	m_fishdata[13].dieframes=3;
	m_fishdata[13].w=25;
	m_fishdata[13].h=60;
	m_fishdata[13].nfc=1;
	m_fishdata[13].cent=2;
	m_fishdata[13].effid=20;

	//∫˚µ˚”„
	for(int i=0;i<8;i++)
	{
		if(i<5)
		{
	      m_sprfish[14][i]=new hgeSprite(m_texfish[24],68.0f*i,0,68,68);
	      m_sprfish[14][i]->SetZ(0.88f);
	      m_sprfish[14][i]->SetHotSpot(34,34);
		}
		else
		{
		  m_sprfish[14][i]=new hgeSprite(m_texfish[25],63.0f*(i-5),0,63,68);
	      m_sprfish[14][i]->SetZ(0.88f);
	      m_sprfish[14][i]->SetHotSpot(21,42.5f);
		}
	}
	m_fishdata[14].id=14;
	m_fishdata[14].frames=5;
	m_fishdata[14].dieframes=3;
	m_fishdata[14].w=68;
	m_fishdata[14].h=68;
	m_fishdata[14].nfc=4;
	m_fishdata[14].cent=4;
	m_fishdata[14].effid=20;

	//∆’Õ®µ∆”„
	for(int i=0;i<12;i++)
	{
		if(i<8)
		{
	      m_sprfish[15][i]=new hgeSprite(m_texfish[26],115.0f*(i%4),263.0f*(i/4),115,263);
	      m_sprfish[15][i]->SetZ(0.88f);
	      m_sprfish[15][i]->SetHotSpot(57.5f,131.5f);
		}
		else
		{
		  m_sprfish[15][i]=new hgeSprite(m_texfish[29],123.0f*(i-8),0,123,233);
	      m_sprfish[15][i]->SetZ(0.88f);
	      m_sprfish[15][i]->SetHotSpot(21,42.5f);
		}
	}
	m_fishdata[15].id=15;
	m_fishdata[15].frames=8;
	m_fishdata[15].dieframes=4;
	m_fishdata[15].w=115;
	m_fishdata[15].h=263;
	m_fishdata[15].nfc=3;
	m_fishdata[15].cent=12;
	m_fishdata[15].effid=2;
	
	//—€æµµ∆”„
	for(int i=0;i<12;i++)
	{
		if(i<8)
		{
	      m_sprfish[16][i]=new hgeSprite(m_texfish[27],115.0f*i,0,115,263);
	      m_sprfish[16][i]->SetZ(0.88f);
	      m_sprfish[16][i]->SetHotSpot(57.5f,131.5f);
		}
		else
		{
		  m_sprfish[16][i]=new hgeSprite(m_texfish[29],123.0f*(i-8),0,123,233);
	      m_sprfish[16][i]->SetZ(0.88f);
	      m_sprfish[16][i]->SetHotSpot(21,42.5f);
		}
	}
	m_fishdata[16].id=16;
	m_fishdata[16].frames=8;
	m_fishdata[16].dieframes=4;
	m_fishdata[16].w=115;
	m_fishdata[16].h=263;
	m_fishdata[16].nfc=3;
	m_fishdata[16].cent=12;
	m_fishdata[16].effid=2;
	//ª®Œ∆µ∆”„
	for(int i=0;i<12;i++)
	{
		if(i<8)
		{
	      m_sprfish[17][i]=new hgeSprite(m_texfish[28],112.0f*i,0,112,270);
	      m_sprfish[17][i]->SetZ(0.88f);
	      m_sprfish[17][i]->SetHotSpot(56,135);
		}
		else
		{
		  m_sprfish[17][i]=new hgeSprite(m_texfish[29],123.0f*(i-8),0,123,233);
	      m_sprfish[17][i]->SetZ(0.88f);
	      m_sprfish[17][i]->SetHotSpot(21,42.5f);
		}
	}
	m_fishdata[17].id=17;
	m_fishdata[17].frames=8;
	m_fishdata[17].dieframes=4;
	m_fishdata[17].w=112;
	m_fishdata[17].h=270;
	m_fishdata[17].nfc=3;
	m_fishdata[17].cent=12;
	m_fishdata[17].effid=2;
	//π⁄æ¸¿∂ˆË”„
	for(int i=0;i<20;i++)
	{
		if(i<16)
		{
	      m_sprfish[18][i]=new hgeSprite(m_texfish[30],285.0f*i,0,285,551);
	      m_sprfish[18][i]->SetZ(0.88f);
	      m_sprfish[18][i]->SetHotSpot(142.5f,225.5f);
		}
		else
		{
		  m_sprfish[18][i]=new hgeSprite(m_texfish[32],350.0f*(i-16),0,350,524);
	      m_sprfish[18][i]->SetZ(0.88f);
	      m_sprfish[18][i]->SetHotSpot(175,262);
		}
	}
	m_fishdata[18].id=18;
	m_fishdata[18].frames=16;
	m_fishdata[18].dieframes=4;
	m_fishdata[18].w=285;
	m_fishdata[18].h=551;
	m_fishdata[18].nfc=12;
	m_fishdata[18].cent=60;
	m_fishdata[18].effid=14;
	//¿∂ˆË”„
	for(int i=0;i<20;i++)
	{
		if(i<16)
		{
	      m_sprfish[19][i]=new hgeSprite(m_texfish[31],266.0f*(i%6),515.0f*(i/6),266,515);
	      m_sprfish[19][i]->SetZ(0.88f);
	      m_sprfish[19][i]->SetHotSpot(133,257.5f);
		}
		else
		{
		  m_sprfish[19][i]=new hgeSprite(m_texfish[32],350.0f*(i-16),0,350,524);
	      m_sprfish[19][i]->SetZ(0.88f);
	      m_sprfish[19][i]->SetHotSpot(175,262);
		}
	}
	m_fishdata[19].id=19;
	m_fishdata[19].frames=16;
	m_fishdata[19].dieframes=4;
	m_fishdata[19].w=266;
	m_fishdata[19].h=515;
	m_fishdata[19].nfc=12;
	m_fishdata[19].cent=60;
	m_fishdata[19].effid=14;
	//≈˚∑Á∫£πÍ
	for(int i=0;i<9;i++)
	{
		if(i<8)
		{
	      m_sprfish[20][i]=new hgeSprite(m_texfish[33],155.0f*(i%4),145.0f*(i/4),155,145);
	      m_sprfish[20][i]->SetZ(0.88f);
	      m_sprfish[20][i]->SetHotSpot(77.5f,72.5f);
		}
		else
		{
		  m_sprfish[20][i]=new hgeSprite(m_texfish[36],166.0f*(i-8),0,166,145);
	      m_sprfish[20][i]->SetZ(0.88f);
	      m_sprfish[20][i]->SetHotSpot(83,72.5f);
		}
	}
	m_fishdata[20].id=20;
	m_fishdata[20].frames=8;
	m_fishdata[20].dieframes=1;
	m_fishdata[20].w=155;
	m_fishdata[20].h=145;
	m_fishdata[20].nfc=2;
	m_fishdata[20].cent=10;
	m_fishdata[20].effid=0;

	//”Œ”æ»¶∫£πÍ
	for(int i=0;i<7;i++)
	{
		if(i<6)
		{
	      m_sprfish[21][i]=new hgeSprite(m_texfish[34],166.0f*i,0,166,150);
	      m_sprfish[21][i]->SetZ(0.88f);
	      m_sprfish[21][i]->SetHotSpot(83,75);
		}
		else
		{
		  m_sprfish[21][i]=new hgeSprite(m_texfish[36],166.0f*(i-6),0,166,145);
	      m_sprfish[21][i]->SetZ(0.88f);
	      m_sprfish[21][i]->SetHotSpot(83,72.5f);
		}
	}
	m_fishdata[21].id=21;
	m_fishdata[21].frames=6;
	m_fishdata[21].dieframes=1;
	m_fishdata[21].w=166;
	m_fishdata[21].h=150;
	m_fishdata[21].nfc=2;
	m_fishdata[21].cent=10;
	m_fishdata[21].effid=0;
	//∆’Õ®∫£πÍ
	for(int i=0;i<7;i++)
	{
		if(i<6)
		{
	      m_sprfish[22][i]=new hgeSprite(m_texfish[35],166.0f*i,0,166,150);
	      m_sprfish[22][i]->SetZ(0.88f);
	      m_sprfish[22][i]->SetHotSpot(83,75);
		}
		else
		{
		  m_sprfish[22][i]=new hgeSprite(m_texfish[36],166.0f*(i-6),0,166,145);
	      m_sprfish[22][i]->SetZ(0.88f);
	      m_sprfish[22][i]->SetHotSpot(83,72.5f);
		}
	}
	m_fishdata[22].id=22;
	m_fishdata[22].frames=6;
	m_fishdata[22].dieframes=1;
	m_fishdata[22].w=166;
	m_fishdata[22].h=150;
	m_fishdata[22].nfc=2;
	m_fishdata[22].cent=10;
	m_fishdata[22].effid=0;
	m_phge->Resource_RemoveAllPacks();
}


void G_Fish::Render(GameBack*gameback)
{
	//∏ƒ±‰”„’Û
	if(m_bchangesta)
	{
	  for(int i=0;i<5;i++)
	  {
	    m_fishes[i].clear();
	    m_fishnum[i]=0;
	  }
	  if(rand()%2==0)
	       m_bleft=true;
	  else
		   m_bleft=false;
	  if(m_fisharray==FISH_ARRAY0)
	      G_Fish::InitFishArray0();
	  else if(m_fisharray==FISH_ARRAY1)
		  G_Fish::InitFishArray1();
	  else if(m_fisharray==FISH_ARRAY2)
		  G_Fish::InitFishArray2();
	  else if(m_fisharray==FISH_ARRAY3)
		  G_Fish::InitFishArray3();
	  else if(m_fisharray==FISH_ARRAY4)
		  G_Fish::InitFishArray4();
	  else if(m_fisharray==FISH_ARRAY5)
		  G_Fish::InitFishArray5();
	  else if(m_fisharray==FISH_ARRAY6)
		  G_Fish::InitFishArray6();
	  else if(m_fisharray==FISH_ARRAY7)
		  G_Fish::InitFishArray7();
	  else
		  G_Fish::InitFishArray8();
	  m_bchangesta=false;
	}
	//≤π≥‰–°”„∂”
	if(m_fisharray==0)
	{
	  for(int i=1;i<5;i++)
	  {
	    if(IsTeamEmpty(i))
			InitFishTeam(i);
	  }
	}
	for(int n=0;n<5;n++)
	 {
		for(int i=0;i<m_fishnum[n];i++)
		 {
			switch(m_fishes[n][i].m_sta)
			{
				case FISH_RUN:
					if(gameback->m_bwave&&m_fishes[n][i].m_x>gameback->m_wavex)
						m_fishes[n][i].m_sta=FISH_DIS;
					else
					{
						switch(m_fisharray)
						 {
							case FISH_ARRAY0:
								      m_fishes[n][i].RenderFishArray0();
								break;
							case FISH_ARRAY1://y=450£¨∑÷◊Û”“
			                            if(m_bleft)
										{
											m_fishes[n][i].m_spr[time%m_fishes[n][i].m_pdata->frames]->RenderEx(
                                                m_fishes[n][i].m_x,m_fishes[n][i].m_y,m_fishes[n][i].m_rot+PI/2,1,1);
											m_fishes[n][i].m_x+=2;
										}
										else
										{
										    m_fishes[n][i].m_spr[time%m_fishes[n][i].m_pdata->frames]->RenderEx(
                                                m_fishes[n][i].m_x,m_fishes[n][i].m_y,m_fishes[n][i].m_rot-PI/2,1,1);
											m_fishes[n][i].m_x-=2;
										}
										m_centy+=2.0f/m_fishnum[n];
										if(m_centy>3000)
										{
											m_bchangesta=true;
											m_fisharray=0;
										}
								break;
							case FISH_ARRAY2://X=-2600,Y=0,≤ª∑÷◊Û”“
										m_fishes[n][i].RenderFishArray2();
										if(i<200)
										{
											if(m_centx>1440)
											{
											  if((abs(m_fishes[n][i].m_tox-m_fishes[n][i].m_x)<=abs(m_fishes[n][i].m_vx))&&
													(abs(m_fishes[n][i].m_toy-m_fishes[n][i].m_y)<=abs(m_fishes[n][i].m_vy)))
												{
												   m_fishes[n][i].m_bchange=true;
												   m_fishes[n][i].m_tox=m_fishes[n][i].m_x;
												   m_fishes[n][i].m_toy=950-(i/100)*1000.0f;
												}

											  m_fishes[n][i].ChangeWay(m_fishes[n][i].m_tox,m_fishes[n][i].m_toy,
											  m_phge->Random_Float(3,5),m_phge->Random_Float(3,5));
											}
											else
											{
												if((abs(m_fishes[n][i].m_tox-m_fishes[n][i].m_x)<=abs(m_fishes[n][i].m_vx))&&
													(abs(m_fishes[n][i].m_toy-m_fishes[n][i].m_y)<=abs(m_fishes[n][i].m_vy)))
												{
												   m_fishes[n][i].m_bchange=true;
												   m_fishes[n][i].m_tox=m_fishes[n][i].m_x;
												   m_fishes[n][i].m_toy=m_fishes[n][i].m_y;
												}
												m_fishes[n][i].ChangeWay(m_fishes[n][i].m_x,m_fishes[n][i].m_y,3,5);
											}
										}

										m_centx+=3.0f/m_fishnum[n];
										if(m_centx>2300)
										{
											m_bchangesta=true;
											m_fisharray=0;
										}
								break;
								case FISH_ARRAY3://≤ª∑÷◊Û”“
										m_fishes[n][i].RenderFishArray3(m_fishes[n][i].m_runmode);
									break;
								case FISH_ARRAY4://X=-750,≤ª∑÷◊Û”“£¨¥”◊Û
											m_fishes[n][i].m_spr[time%m_fishes[n][i].m_pdata->frames]->RenderEx(
                                                m_fishes[n][i].m_x,m_fishes[n][i].m_y,m_fishes[n][i].m_rot+PI/2,1,1);
											m_fishes[n][i].m_x+=2;
										m_centx+=2.0f/m_fishnum[n];
										if(m_centx>2300)
										 {
											m_bchangesta=true;
											m_fisharray=0;
										 }
									break;
								case FISH_ARRAY5://≤ª∑÷◊Û”“,y=450

											m_fishes[n][i].m_spr[time%m_fishes[n][i].m_pdata->frames]->RenderEx(
                                                m_fishes[n][i].m_x,m_fishes[n][i].m_y,m_fishes[n][i].m_rot+PI/2,1,1);
											m_fishes[n][i].m_x+=2;
										m_centy+=2.0f/m_fishnum[n];
										if(m_centy>3200)
										 {
											m_bchangesta=true;
											m_fisharray=0;
										 }
									break;
								case FISH_ARRAY6://≤ª∑÷◊Û”“£¨leftx=-670
											m_fishes[n][i].m_spr[time%m_fishes[n][i].m_pdata->frames]->RenderEx(
                                                m_fishes[n][i].m_x,m_fishes[n][i].m_y,m_fishes[n][i].m_rot+PI/2,1,1);
											m_fishes[n][i].m_x+=2;
										  if(m_fishes[n][i].m_pdata->id==12)
											 m_sprmj->Render(m_fishes[n][i].m_x+210,m_fishes[n][i].m_y);
										m_centx+=2.0f/m_fishnum[n];
										if(m_centx>2300)
										  {
											m_bchangesta=true;
											m_fisharray=0;
										  }
								break;
								case FISH_ARRAY7://≤ª∑÷◊Û”“
									if( m_fishes[n][i].m_pdata->id==7)
									 {
										m_fishes[n][i].m_spr[time% m_fishes[n][i].m_pdata->frames]->Render( m_fishes[n][i].m_x, m_fishes[n][i].m_y);
										m_centy+=3;
										if(m_centy>900)
											m_fishes[n][i].m_sta=FISH_DIS;
									 }
									else
									    m_fishes[n][i].RenderFishArray0();
								break;
								case FISH_ARRAY8:
									if(m_fishes[n][i].m_pdata->id==13)
									{
									  m_fishes[n][i].m_spr[time%m_fishes[n][i].m_pdata->frames]->RenderEx(
                                                m_fishes[n][i].m_x,m_fishes[n][i].m_y,m_fishes[n][i].m_rot+PI/2,1,1);
									  m_fishes[n][i].m_x+=m_fishes[n][i].m_vx;
									  m_fishes[n][i].m_y+=m_fishes[n][i].m_vy;
									  if(m_fishes[n][i].m_y>1100||m_fishes[n][i].m_y<-200)
				                         m_fishes[n][i].m_sta=FISH_DIS;
									}
									else
									{
										m_fishes[n][i].m_spr[time%m_fishes[n][i].m_pdata->frames]->RenderEx(m_fishes[n][i].m_x,
											m_fishes[n][i].m_y,m_fishes[n][i].m_rot+PI/2,1,1);
										m_fishes[n][i].m_x+=m_fishes[n][i].m_vx;
										if(m_fishes[n][i].m_a==0)
											m_fishes[n][i].m_y+=m_fishes[n][i].m_vy;
										else
											m_fishes[n][i].m_y=m_fishes[n][i].m_a*m_fishes[n][i].m_x+m_fishes[n][i].m_c;
										if(m_fishes[n][i].m_x>1800||m_fishes[n][i].m_x<-300||m_fishes[n][i].m_y>1100|| m_fishes[n][i].m_y<-200)
										 {
				                           m_fishes[n][i].m_sta=FISH_DIS;
										   m_centx++;
										 }
									}
									break;
						  }
					}
				break;
				case FISH_DIE:
					m_fishes[n][i].RenderDie();
					if(m_fisharray==8&&m_fishes[n][i].m_sta==FISH_DIS)
						if(m_fishes[n][i].m_pdata->id!=13)
						    m_centx++;
				break;
				case FISH_DIS:  //”„œ˚ ß∫Û≤π≥‰”„£¨≥ˆ”„º∏¬ ‘⁄¥À…Ë÷√
					 if(m_fisharray==0)
						{
							  if(n==0)
							  {
								 int fishid;int kind=rand()%1000;
								 if(kind<10)
									 fishid=16+rand()%5;
								 else if(kind<15)
									 fishid=22;
								 else if(kind<50)
								      fishid=9+rand()%7;
								 else
									 fishid=rand()%9;
							     Fish fish(m_sprfish,&m_fishdata[fish_id[fishid]]);
							     m_fishes[n][i]=fish;
								 if(fish.m_pdata->id==5)
							         m_fishes[n][i].ChangeWay(m_fishes[n][i].m_tox,m_fishes[n][i].m_toy,7,7);
								 else
									 m_fishes[n][i].ChangeWay(m_fishes[n][i].m_tox,m_fishes[n][i].m_toy,4,4);
							  }
							  else
							  {
								  if(i<m_fishnum[n]-1)
								   {
								      m_fishes[n][i+1].m_teamhead=NULL;
									  if(m_fishes[n][i+1].m_sta==FISH_READY)
										  m_fishes[n][i+1].m_sta=FISH_RUN;
								   }
							  }
						  }
						 else if(m_fisharray==3&&i==0)
						  {
								   m_bchangesta=true;
								   m_fisharray=0;
						  }
						 else if(m_fisharray==7&&i==0)
						 {
								m_centy+=3;
								if(m_centy>3000)
								{
								    m_bchangesta=true;
									m_fisharray=0;
								}
								else if(m_centy>1900)
								{
									break;
								}
								else if(m_centy>1800)
								{
                                    if(m_fishes[n][364].m_sta==FISH_READY)
								       m_fishes[n][364].m_sta=FISH_RUN;
									if(m_fishes[n][394].m_sta==FISH_READY)
									   m_fishes[n][394].m_sta=FISH_RUN;
									if(m_fishes[n][424].m_sta==FISH_READY)
									   m_fishes[n][424].m_sta=FISH_RUN;
									if(m_fishes[n][454].m_sta==FISH_READY)
									   m_fishes[n][454].m_sta=FISH_RUN;
									if(m_fishes[n][484].m_sta==FISH_READY)
									   m_fishes[n][484].m_sta=FISH_RUN;
									if(m_fishes[n][514].m_sta==FISH_READY)
									   m_fishes[n][514].m_sta=FISH_RUN;
								}
								else if(m_centy>1400)
								{
								    if(m_fishes[n][184].m_sta==FISH_READY)
								       m_fishes[n][184].m_sta=FISH_RUN;
									if(m_fishes[n][214].m_sta==FISH_READY)
									   m_fishes[n][214].m_sta=FISH_RUN;
									if(m_fishes[n][244].m_sta==FISH_READY)
									   m_fishes[n][244].m_sta=FISH_RUN;
									if(m_fishes[n][274].m_sta==FISH_READY)
									   m_fishes[n][274].m_sta=FISH_RUN;
									if(m_fishes[n][304].m_sta==FISH_READY)
									   m_fishes[n][304].m_sta=FISH_RUN;
									if(m_fishes[n][334].m_sta==FISH_READY)
									   m_fishes[n][334].m_sta=FISH_RUN;
								}
								else
								{
									if(m_fishes[n][4].m_sta==FISH_READY)
								       m_fishes[n][4].m_sta=FISH_RUN;
									if(m_fishes[n][34].m_sta==FISH_READY)
									   m_fishes[n][34].m_sta=FISH_RUN;
									if(m_fishes[n][64].m_sta==FISH_READY)
									   m_fishes[n][64].m_sta=FISH_RUN;
									if(m_fishes[n][94].m_sta==FISH_READY)
									   m_fishes[n][94].m_sta=FISH_RUN;
									if(m_fishes[n][124].m_sta==FISH_READY)
									   m_fishes[n][124].m_sta=FISH_RUN;
									if(m_fishes[n][154].m_sta==FISH_READY)
									   m_fishes[n][154].m_sta=FISH_RUN;
								}
						 }
						else if(m_fisharray==8)
						{
							if(m_fishes[n][i].m_pdata->id==13)
							{
								if(m_centx<20)
								{
									m_fishes[n][i].m_x=hge->Random_Float(0,1440);
									for(int j=0;j<6;j++)
										m_fishes[n][i].m_playerhit[j]=0;
									m_fishes[n][i].m_sta=FISH_RUN;
									if(m_fishes[n][i].m_vy>0)
										m_fishes[n][i].m_y=-100;
									else
										m_fishes[n][i].m_y=1000;
								}
								else
								{
									m_fishes[n][i].m_sta=FISH_READY;
									m_centx++;
									if(m_centx>99)
									{
									   m_bchangesta=true;
									   m_fisharray=0;
									}
								}
							}
						 }

				break;
				case FISH_READY:
					if(m_fisharray==0&&m_fishes[n][i].m_teamhead!=NULL)
					{
						if(m_fishes[n][i].m_pdata->id==14)
						{
						  if(sqrt((m_fishes[n][i].m_teamhead->m_x-m_fishes[n][i].m_x)*(m_fishes[n][i].m_teamhead->m_x-m_fishes[n][i].m_x)+
							(m_fishes[n][i].m_teamhead->m_y-m_fishes[n][i].m_y)*(m_fishes[n][i].m_teamhead->m_y-m_fishes[n][i].m_y))>m_fishes[n][i].m_pdata->h*1.5f)
							m_fishes[n][i].m_sta=FISH_RUN;
						}
						else if(m_fishes[n][i].m_pdata->id==13)
						{
							if(abs(m_fishes[n][i].m_teamhead->m_vy)>=m_phge->Random_Float(0.1f,0.3f)*m_fishes[n][i].m_pdata->h/m_fishes[n][i].m_c)
							  m_fishes[n][i].m_sta=FISH_RUN;
						}
						else
						{
						   if(sqrt((m_fishes[n][i].m_teamhead->m_x-m_fishes[n][i].m_x)*(m_fishes[n][i].m_teamhead->m_x-m_fishes[n][i].m_x)+
							(m_fishes[n][i].m_teamhead->m_y-m_fishes[n][i].m_y)*(m_fishes[n][i].m_teamhead->m_y-m_fishes[n][i].m_y))>m_fishes[n][i].m_pdata->h)
							m_fishes[n][i].m_sta=FISH_RUN;
						}
					}
					else if(m_fisharray==3)
					{
						if(m_fishes[n][i].m_teamhead->m_vy>=(PI/6.5)&&m_fishes[n][i].m_pdata->id==11)
							m_fishes[n][i].m_sta=FISH_RUN;
						else if(m_fishes[n][i].m_teamhead->m_vy>=(PI/12)&&m_fishes[n][i].m_pdata->id==14)
							m_fishes[n][i].m_sta=FISH_RUN;
						else if(m_fishes[n][i].m_teamhead->m_vy>=(PI/20)&&(m_fishes[n][i].m_pdata->id==8||m_fishes[n][i].m_pdata->id==13))
							m_fishes[n][i].m_sta=FISH_RUN;
					}
					else if(m_fisharray==7&&m_fishes[n][i].m_teamhead!=NULL)
					{
						float d=sqrt((m_fishes[n][i].m_teamhead->m_x-m_fishes[n][i].m_x)*(m_fishes[n][i].m_teamhead->m_x-m_fishes[n][i].m_x)+
							(m_fishes[n][i].m_teamhead->m_y-m_fishes[n][i].m_y)*(m_fishes[n][i].m_teamhead->m_y-m_fishes[n][i].m_y));
							 if(m_fishes[n][i].m_pdata->id==14)
							  {
								  if(d>150||m_fishes[n][i].m_teamhead->m_sta==FISH_DIS)
							         m_fishes[n][i].m_sta=FISH_RUN;
							  }
							 else
							 {
								 if(d>m_fishes[n][i].m_pdata->h/4&&m_fishes[n][i].m_teamhead->m_sta!=FISH_READY)
								    m_fishes[n][i].m_sta=FISH_RUN;
							 }
					}
					else if(m_fisharray==8)
					{
						if(m_fishes[n][i].m_pdata->id!=13)
						{
							float d=abs(m_fishes[n][i].m_teamhead->m_x-m_fishes[n][i].m_x);
							if(m_fishes[n][i].m_teamhead->m_sta==FISH_DIS||d>300)
								m_fishes[n][i].m_sta=FISH_RUN;
						}
					}
					break;
			}
		}
	 }
	//‰÷»æ–°”„∂”
	   
}

void G_Fish::InitFishTeam(int teamid)
{
	    int fishid=0;
		if(rand()%100<90)
			fishid=rand()%9;
		else
			fishid=9+rand()%6;
		if(fishid==0||fishid==6||fishid==10)
		{
			fishid=0;
			m_fishnum[teamid]=9+rand()%3;
		}
		else if(fishid==3)
			m_fishnum[teamid]=7;
		else
			m_fishnum[teamid]=2+rand()%3;
		Fish fish(m_sprfish,&m_fishdata[fish_id[fishid]]);
		if(fishid==0)
		{
			if(fish.m_x<0||fish.m_x>1440)
			{
				fish.m_tox=fish.m_x;
				fish.m_vy=0;
				fish.m_torot=PI/2;
				fish.m_runmode=1;
				if(fish.m_y<450)
				{
					fish.m_toy=600;
					fish.m_c=600-fish.m_y;
					fish.m_a=-PI/2;
					if(fish.m_x<0)
					{
					  fish.m_rot=0;
					  fish.m_vx=abs(asin(5/fish.m_c));
					}
					else
					{
					   fish.m_rot=-PI;
					   fish.m_vx=-abs(asin(5/fish.m_c));
					}
				}
				else
				{
				    fish.m_toy=300;
					fish.m_c=fish.m_y-300;
					fish.m_a=PI/2;
					if(fish.m_x<0)
					{
					  fish.m_rot=0;
					  fish.m_vx=-abs(asin(5/fish.m_c));
					}
					else
					{
					   fish.m_rot=-PI;
					   fish.m_vx=abs(asin(5/fish.m_c));
					}
				}
			}
		  else
		    {
				fish.m_toy=fish.m_y;
				fish.m_vy=0;
				fish.m_torot=PI/2;
				fish.m_runmode=1;
				if(fish.m_x<720)
				{
				    fish.m_tox=900;
					fish.m_c=900-fish.m_x;
					fish.m_a=PI;
					if(fish.m_y<0)
					{
					  fish.m_vx=-abs(asin(5/fish.m_c));
					  fish.m_rot=PI/2;

					}
					else
					{
					   fish.m_vx=abs(asin(5/fish.m_c));
					   fish.m_rot=-PI/2;
					}
				}
				else
				{
				    fish.m_tox=540;
					fish.m_c=fish.m_x-540;
					fish.m_a=0;
					if(fish.m_y<0)
					{
					   fish.m_rot=PI/2;
					   fish.m_vx=abs(asin(5/fish.m_c));
					}
					else
					{
						fish.m_vx=-abs(asin(5/fish.m_c));
					   fish.m_rot=-PI/2;
					}
				}
		    }
			
		}
		else
		    fish.ChangeWay(fish.m_tox,fish.m_toy,5,5);

		for(int j=0;j<m_fishnum[teamid];j++)
			m_fishes[teamid].push_back(fish);
		for(int j=1;j<m_fishnum[teamid];j++)
		{
			   m_fishes[teamid][j].m_teamhead=&m_fishes[teamid][j-1];
			   m_fishes[teamid][j].m_sta=FISH_READY;
			   if(fishid==0)
				   m_fishes[teamid][j].m_c+=m_phge->Random_Float(-50,50);
		}
}


bool G_Fish::IsTeamEmpty(int witchteam)
{
	if(m_fishes[witchteam].empty())
		return true;
	for(int i=0;i<m_fishnum[witchteam];i++)
	{
		if(m_fishes[witchteam][i].m_sta!=FISH_DIS)
			return false;
	}
    m_fishes[witchteam].clear();
	return true;
}

void G_Fish::InitFishArray0(void)
{
	for(int i=0;i<30;i++)
	 {
	   Fish fish(m_sprfish,&m_fishdata[fish_id[m_phge->Random_Int(0,8)]]);
	   m_fishes[0].push_back(fish);
	   m_fishes[0][m_fishnum[0]].ChangeWay(m_fishes[0][m_fishnum[0]].m_tox,m_fishes[0][m_fishnum[0]].m_toy,5,5);
	   m_fishnum[0]++;
	 }
	for(int i=1;i<5;i++)
	  InitFishTeam(i);
}


void G_Fish::InitFishArray1() //
{
	if(m_bleft)
	    m_centx=-800;
	else
		m_centx=2300;
	  m_centy=450;
	Fish fish1(m_sprfish,&m_fishdata[12]);//ΩˆË”„
	Fish fish2(m_sprfish,&m_fishdata[6]);// ¿∂…´”„
	Fish fish3(m_sprfish,&m_fishdata[5]);//  –°≥Û”„
	Fish fish4(m_sprfish,&m_fishdata[14]);// ∫˚µ˚”„
	m_fishes[0].push_back(fish1);
	m_fishes[0][0].m_x=m_centx-50;
	m_fishes[0][0].m_y=m_centy;
	m_fishnum[0]++;
	for(int i=0;i<64;i++)
	{
	  m_fishes[0].push_back(fish2);
	  m_fishes[0][1+i].m_x=m_centx-480+(i%16)*60.0f;
	  m_fishes[0][1+i].m_y=m_centy-250+(i/16)*120.0f+(i/32)*150.0f;
	  m_fishnum[0]++;
	}
	for(int i=0;i<26;i++)
	{
	  m_fishes[0].push_back(fish3);
	  if(i<20)
	  {
	     m_fishes[0][65+i].m_x=m_centx-580+(i%10)*120.0f;
	     m_fishes[0][65+i].m_y=m_centy-200+(i/10)*400.0f;
	  }
	  else
	  {
	     m_fishes[0][65+i].m_x=m_centx-580+((i-20)%2)*1080.0f;
	     m_fishes[0][65+i].m_y=m_centy-100+((i-20)%3)*100.0f;
	  }
	  m_fishnum[0]++;
	}
	for(int i=0;i<8;i++)
	{
	   m_fishes[0].push_back(fish4);
	   if(i<4)
	   {
	     m_fishes[0][91+i].m_x=m_centx-390+(i/2)*720.0f;
	     m_fishes[0][91+i].m_y=m_centy-80+(i%2)*160.0f;
	   }
	   else
	   {
	      m_fishes[0][91+i].m_x=m_centx-460+((i-4)%2)*130+((i-4)/2)*720.0f;
	      m_fishes[0][91+i].m_y=m_centy;
	   }
	   m_fishnum[0]++;
	}
}

void G_Fish::InitFishArray2()
{
	m_centx=-2600;
	m_centy=0;
	//–°∫Ï”„
	for(int i=0;i<200;i++)
	{
	   Fish fish(m_sprfish,&m_fishdata[13]);
	   m_fishes[0].push_back(fish);
	   m_fishes[0][m_fishnum[0]].m_x=(i%100)*15.0f+m_phge->Random_Float(-20,20);
	   if(i<100)
		   m_fishes[0][m_fishnum[0]].m_y=-300+m_phge->Random_Float(0,300);
	   else
		   m_fishes[0][m_fishnum[0]].m_y=1200.0f-m_phge->Random_Float(0,300);
	   m_fishes[0][m_fishnum[0]].m_toy=150+600.0f*(i/100)+m_phge->Random_Float(-15,15);
	   m_fishes[0][m_fishnum[0]].m_tox=m_fishes[0][m_fishnum[0]].m_x;
       m_fishes[0][m_fishnum[0]].ChangeWay(m_fishes[0][m_fishnum[0]].m_x,m_fishes[0][m_fishnum[0]].m_toy,3,3);
	   m_fishnum[0]++;
	}
	//ΩˆË”„
	   Fish jfish(m_sprfish,&m_fishdata[12]);
	   m_fishes[0].push_back(jfish);
	   m_fishes[0][m_fishnum[0]].m_x=-250.0f;
	   m_fishes[0][m_fishnum[0]].m_y=570;
	   m_fishes[0][m_fishnum[0]].m_a=0;
	   m_fishes[0][m_fishnum[0]].m_vy=0;
	   m_fishes[0][m_fishnum[0]].m_vx=3;
	   m_fishnum[0]++;

	//∫£πÍ
	for(int i=0;i<4;i++)
	{
	   Fish fish(m_sprfish,&m_fishdata[22]);
	   m_fishes[0].push_back(fish);
	   m_fishes[0][m_fishnum[0]].m_x=-i*250.0f-600;
	   m_fishes[0][m_fishnum[0]].m_y=570;
	   m_fishes[0][m_fishnum[0]].m_a=0;
	   m_fishes[0][m_fishnum[0]].m_vy=0;
	   m_fishes[0][m_fishnum[0]].m_vx=3;
	   m_fishnum[0]++;
	}
	//∞ﬂ”„
	for(int i=0;i<4;i++)
	{
	   Fish fish(m_sprfish,&m_fishdata[0]);
	   m_fishes[0].push_back(fish);
	   m_fishes[0][m_fishnum[0]].m_x=-i*150.0f-1600;
	   m_fishes[0][m_fishnum[0]].m_y=585;
	   m_fishes[0][m_fishnum[0]].m_a=0;
	   m_fishes[0][m_fishnum[0]].m_vy=0;
	   m_fishes[0][m_fishnum[0]].m_vx=3;
	   m_fishnum[0]++;
	}
	//ª∆…´–°”„
	for(int i=0;i<4;i++)
	{
	   Fish fish(m_sprfish,&m_fishdata[8]);
	   m_fishes[0].push_back(fish);
	   m_fishes[0][m_fishnum[0]].m_x=-i*100.0f-2200;
	   m_fishes[0][m_fishnum[0]].m_y=620;
	   m_fishes[0][m_fishnum[0]].m_a=0;
	   m_fishes[0][m_fishnum[0]].m_vy=0;
	   m_fishes[0][m_fishnum[0]].m_vx=3;
	   m_fishnum[0]++;
	}
	
	//“¯ˆË”„
	   Fish fish(m_sprfish,&m_fishdata[4]);
	   m_fishes[0].push_back(fish);
	   m_fishes[0][m_fishnum[0]].m_x=1690.0f;
	   m_fishes[0][m_fishnum[0]].m_y=330;
	   m_fishes[0][m_fishnum[0]].m_a=0;
	   m_fishes[0][m_fishnum[0]].m_rot=-PI;
	   m_fishes[0][m_fishnum[0]].m_vy=0;
	   m_fishes[0][m_fishnum[0]].m_vx=-3;
	   m_fishnum[0]++;
	//—€æµµ∆”„
	for(int i=0;i<4;i++)
	{
	   Fish fish(m_sprfish,&m_fishdata[15]);
	   m_fishes[0].push_back(fish);
	   m_fishes[0][m_fishnum[0]].m_x=2040+i*250.0f;
	   m_fishes[0][m_fishnum[0]].m_y=330;
	   m_fishes[0][m_fishnum[0]].m_a=0;
	    m_fishes[0][m_fishnum[0]].m_rot=-PI;
	   m_fishes[0][m_fishnum[0]].m_vy=0;
	   m_fishes[0][m_fishnum[0]].m_vx=-3;
	   m_fishnum[0]++;
	}
	//ø◊»∏”„
	for(int i=0;i<4;i++)
	{
	   Fish fish(m_sprfish,&m_fishdata[11]);
	   m_fishes[0].push_back(fish);
	   m_fishes[0][m_fishnum[0]].m_x=3040+i*150.0f;
	   m_fishes[0][m_fishnum[0]].m_y=330;
	   m_fishes[0][m_fishnum[0]].m_a=0;
	    m_fishes[0][m_fishnum[0]].m_rot=-PI;
	   m_fishes[0][m_fishnum[0]].m_vy=0;
	   m_fishes[0][m_fishnum[0]].m_vx=-3;
	   m_fishnum[0]++;
	}
	//¿∂…´–°”„
	for(int i=0;i<4;i++)
	{
	   Fish fish(m_sprfish,&m_fishdata[6]);
	   m_fishes[0].push_back(fish);
	   m_fishes[0][m_fishnum[0]].m_x=3640+i*100.0f;
	   m_fishes[0][m_fishnum[0]].m_y=330;
	   m_fishes[0][m_fishnum[0]].m_a=0;
	    m_fishes[0][m_fishnum[0]].m_rot=-PI;
	   m_fishes[0][m_fishnum[0]].m_vy=0;
	   m_fishes[0][m_fishnum[0]].m_vx=-3;
	   m_fishnum[0]++;
	}
}

void G_Fish::InitFishArray3()
{
	m_centy=0;
	Fish fish1(m_sprfish,&m_fishdata[9]);
	Fish fish2(m_sprfish,&m_fishdata[11]);
	Fish fish3(m_sprfish,&m_fishdata[14]);
	Fish fish4(m_sprfish,&m_fishdata[8]);
	Fish fish5(m_sprfish,&m_fishdata[13]);
	m_fishes[0].push_back(fish1);
	m_fishes[0][0].m_runmode=1;
	m_fishes[0][0].m_torot=7*PI+m_phge->Random_Float(0,PI);
	m_fishes[0][0].m_c=0;
	m_fishes[0][0].m_x=720;
	m_fishes[0][0].m_y=450;
	m_fishes[0][0].m_tox=720;
	m_fishes[0][0].m_toy=450;
	m_fishes[0][0].m_rot=0;
	m_fishes[0][0].m_a=0;
	m_fishes[0][0].m_vx=abs(asin(1.0f/50));
	m_fishes[0][0].m_vy=0;
	m_fishnum[0]++;
	for(int i=0;i<13;i++)
	{
		m_fishes[0].push_back(fish2);
		m_fishes[0][1+i].m_runmode=1;
		m_fishes[0][1+i].m_torot=7*PI-2*PI/13*i;
		m_fishes[0][1+i].m_c=220;
		m_fishes[0][1+i].m_x=940;
		m_fishes[0][1+i].m_y=450;
		m_fishes[0][1+i].m_tox=720;
		m_fishes[0][1+i].m_toy=450;
		m_fishes[0][1+i].m_rot=PI/2;
		m_fishes[0][1+i].m_a=0;
		m_fishes[0][1+i].m_vx=abs(asin(1.0f/50));
		m_fishes[0][1+i].m_vy=0;
		m_fishnum[0]++;
	}

	for(int i=0;i<24;i++)
	{
		m_fishes[0].push_back(fish3);
		m_fishes[0][14+i].m_runmode=1;
		m_fishes[0][14+i].m_torot=6*PI-PI/12*i+3*PI/4;
		m_fishes[0][14+i].m_c=280;
		m_fishes[0][14+i].m_x=1000;
		m_fishes[0][14+i].m_y=450;
		m_fishes[0][14+i].m_tox=720;
		m_fishes[0][14+i].m_toy=450;
		m_fishes[0][14+i].m_rot=PI/2;
		m_fishes[0][14+i].m_a=0;
		m_fishes[0][14+i].m_vx=abs(asin(1.0f/50));
		m_fishes[0][14+i].m_vy=0;
		m_fishnum[0]++;
	}

	for(int i=0;i<40;i++)
	{
		m_fishes[0].push_back(fish4);
		m_fishes[0][38+i].m_runmode=1;
		m_fishes[0][38+i].m_torot=6*PI-PI/20*i+PI/2;
		m_fishes[0][38+i].m_c=345;
		m_fishes[0][38+i].m_x=1065;
		m_fishes[0][38+i].m_y=450;
		m_fishes[0][38+i].m_tox=720;
		m_fishes[0][38+i].m_toy=450;
		m_fishes[0][38+i].m_rot=PI/2;
		m_fishes[0][38+i].m_a=0;
		m_fishes[0][38+i].m_vx=abs(asin(1.0f/50));
		m_fishes[0][38+i].m_vy=0;
		m_fishnum[0]++;
	}

	for(int i=0;i<40;i++)
	{
		m_fishes[0].push_back(fish5);
		m_fishes[0][78+i].m_runmode=1;
		m_fishes[0][78+i].m_torot=6*PI-PI/20*i+PI/4;
		m_fishes[0][78+i].m_c=440;
		m_fishes[0][78+i].m_x=1160;
		m_fishes[0][78+i].m_y=450;
		m_fishes[0][78+i].m_tox=720;
		m_fishes[0][78+i].m_toy=450;
		m_fishes[0][78+i].m_rot=PI/2;
		m_fishes[0][78+i].m_a=0;
		m_fishes[0][78+i].m_vx=abs(asin(1.0f/50));
		m_fishes[0][78+i].m_vy=0;
		m_fishnum[0]++;
	}
	for(int i=0;i<13;i++)
	{
		if(i<1)
			m_fishes[0][1+i].m_bcanhit=false;
		else
		{
		  m_fishes[0][1+i].m_sta=FISH_READY;
		  m_fishes[0][1+i].m_teamhead=&m_fishes[0][i];
		}
	}
	for(int i=0;i<24;i++)
	{
		if(i<1)
			m_fishes[0][14+i].m_bcanhit=false;
		else
		{
			m_fishes[0][14+i].m_sta=FISH_READY;
			m_fishes[0][14+i].m_teamhead=&m_fishes[0][13+i];
		}
	}
	for(int i=0;i<40;i++)
	{
		if(i<1)
			m_fishes[0][38+i].m_bcanhit=false;
		else
		{
			m_fishes[0][38+i].m_sta=FISH_READY;
			m_fishes[0][38+i].m_teamhead=&m_fishes[0][37+i];
		}
	}
	for(int i=0;i<40;i++)
	{
		if(i<1)
			m_fishes[0][78+i].m_bcanhit=false;
		else
		{
			m_fishes[0][78+i].m_sta=FISH_READY;
			m_fishes[0][78+i].m_teamhead=&m_fishes[0][77+i];
		}
	}
}


void G_Fish::InitFishArray4(void)
{
	m_centx=-750;
	m_centy=450;
	Pos  A={m_centx-900,450};
	Pos  B={A.x+600,100};
	Pos  C={A.x+620,450};
	Pos  D={A.x+600,800};
	Fish fish1(m_sprfish,&m_fishdata[18]);//π⁄æ¸
	Fish fish2(m_sprfish,&m_fishdata[9]);//xx
	Fish fish3(m_sprfish,&m_fishdata[13]);//–°∫Ï”„
	m_fishes[0].push_back(fish1);
	m_fishes[0][0].m_x=m_centx;
	m_fishes[0][0].m_y=m_centy;
	m_fishnum[0]++;
	for(int i=0;i<5;i++)
	{
		m_fishes[0].push_back(fish2);
		if(i<3)
		  m_fishes[0][1+i].m_x=m_centx+i*200;
		else
		  m_fishes[0][1+i].m_x=m_centx-(i-4)*200;
		  m_fishes[0][1+i].m_y=m_centy+(i-2)*150;
		m_fishnum[0]++;
	}
	for(int i=0;i<150;i++)
	{
		m_fishes[0].push_back(fish3);
		if(i<110)
		{
			Pos pos={m_fishes[0][i+6].m_x,m_fishes[0][i+6].m_y};

			do
			 {
				 pos.x=m_phge->Random_Float(A.x,C.x);
				 pos.y=m_phge->Random_Float(B.y,D.y);
			 }while(!IsInPolygun(pos,A,B,C,D));
			m_fishes[0][i+6].m_x=pos.x;
			m_fishes[0][i+6].m_y=pos.y;
			m_fishnum[0]++;
		}
		else if(i<130)
		{
		    m_fishes[0][i+6].m_x=m_phge->Random_Float(m_centx-300,m_centx);
			m_fishes[0][i+6].m_y=m_phge->Random_Float(m_centy-50,m_centy-320);
			m_fishnum[0]++;
		}
		else
		{
		    m_fishes[0][i+6].m_x=m_phge->Random_Float(m_centx-300,m_centx);
			m_fishes[0][i+6].m_y=m_phge->Random_Float(m_centy+50,m_centy+320);
			m_fishnum[0]++;
		}
	}
}


bool G_Fish::IsInPolygun(Pos pos, Pos A, Pos B, Pos C,Pos D)
{
	float ka,kb,kc,kd;
	float ca,cb,cc,cd;
	bool  ba=false,bb=false,bc=false,bd=false;
	if(A.x==B.x)
	{
		ka=0;
		if(pos.x>A.x)
			ba=true;
	}
	else
	{
	    ka=(B.y-A.y)/(B.x-A.x);
		ca=A.y-ka*A.x;
		if(pos.y>(ka*pos.x+ca))
			ba=true;
	}
	if(C.x==B.x)
	{
		kb=0;
		if(pos.x<B.x)
			bb=true;
	}
	else
	{
	    kb=(C.y-B.y)/(C.x-B.x);
		cb=B.y-kb*B.x;
		if(pos.y>(kb*pos.x+cb))
			bb=true;
	}
	if(D.x==C.x)
	{
		kc=0;
		if(pos.x<C.x)
			bc=true;
	}
	else
	{
	    kc=(D.y-C.y)/(D.x-C.x);
		cc=C.y-kc*C.x;
		if(pos.y<(kc*pos.x+cc))
			bc=true;
	}
	if(D.x==A.x)
	{
		kd=0;
		if(pos.x<D.x)
			bd=true;
	}
	else
	{
	    kd=(D.y-A.y)/(D.x-A.x);
		cd=D.y-kd*D.x;
		if(pos.y<(kd*pos.x+cd))
			bd=true;
	}

	 if(ba&&bc&&bb&&bd)
		return true;
	return false;
}


void G_Fish::InitFishArray5(void)
{
	m_centx=-720;
	m_centy=450;
	Fish fish1(m_sprfish,&m_fishdata[20]);//∫£πÍ
	Fish fish2(m_sprfish,&m_fishdata[17]);// —€æµ”„
	Fish fish3(m_sprfish,&m_fishdata[6]);//¿∂…´–°”„
	Fish fish4(m_sprfish,&m_fishdata[8]);//ª∆…´–°”„
	Fish fish5(m_sprfish,&m_fishdata[13]);//∫Ï…´–°”„
	m_fishes[0].push_back(fish1);
	m_fishes[0][0].m_x=m_centx;
	m_fishes[0][0].m_y=m_centy-70;
	m_fishnum[0]++;
	m_fishes[0].push_back(fish2);
	m_fishes[0][1].m_x=m_centx;
	m_fishes[0][1].m_y=m_centy+70;
	m_fishnum[0]++;

	//–°∫Ï”„
	float rot;
	float r;
	for(int i=0;i<60;i++)
	{
		m_fishes[0].push_back(fish5);
		  r=600-(i/20)*60.0f;
		  rot=asin(400/r);
		  m_fishes[0][2+i].m_x=m_centx+cos(PI-rot+(i%20)*rot/10.0f)*r;
		  m_fishes[0][2+i].m_y=m_centy+sin(PI-rot+(i%20)*rot/10.0f)*r;
		m_fishnum[0]++;
	}
	for(int i=0;i<60;i++)
	{
		m_fishes[0].push_back(fish5);
		  r=600-(i/20)*60.0f;
		  rot=asin(400/r);
		  m_fishes[0][62+i].m_x=m_centx+cos(-rot+(i%20)*rot/10.0f)*r;
		  m_fishes[0][62+i].m_y=m_centy+sin(-rot+(i%20)*rot/10.0f)*r;
		m_fishnum[0]++;
	}

	//¿∂…´–°”„
	for(int i=0;i<81;i++)
	{
	  m_fishes[0].push_back(fish3);
	  m_fishes[0][122+i].m_x=m_centx-300+(i%9)*70.0f;
	  m_fishes[0][122+i].m_y=m_centy-300+(i/9)*70.0f;
	  m_fishnum[0]++;
	}
	m_fishes[0][122].m_x+=280;
	m_fishes[0][122].m_y-=70;

	m_fishes[0][130].m_x+=70;
	m_fishes[0][130].m_y+=280;

	m_fishes[0][194].m_x-=70;
	m_fishes[0][194].m_y-=280;

	m_fishes[0][202].m_x-=280;
	m_fishes[0][202].m_y+=70;
	//ª∆…´–°”„
	for(int i=0;i<81;i++)
	{
	  m_fishes[0].push_back(fish4);
	  m_fishes[0][203+i].m_x=m_centx-285+(i%9)*70.0f;
	  m_fishes[0][203+i].m_y=m_centy-245+(i/9)*70.0f;
	  m_fishnum[0]++;
	}
	m_fishes[0][203].m_x+=280;
	m_fishes[0][203].m_y-=70;

	m_fishes[0][211].m_x+=70;
	m_fishes[0][211].m_y+=280;

	m_fishes[0][275].m_x-=70;
	m_fishes[0][275].m_y-=280;

	m_fishes[0][283].m_x-=280;
	m_fishes[0][283].m_y+=70;
	Pos A={m_centx-200,m_centy};
	Pos B={m_centx,m_centy-200};
	Pos C={m_centx+200,m_centy};
	Pos D={m_centx,m_centy+200};
	for(int i=122;i<284;i++)
	{
		Pos pos={m_fishes[0][i].m_x,m_fishes[0][i].m_y};
		if(IsInPolygun(pos,A,B,C,D))
			m_fishes[0][i].m_sta=FISH_DIS;
	}
}


void G_Fish::InitFishArray6(void)
{
	m_centx=-670;
	m_centy=500;
	Fish fish1(m_sprfish,&m_fishdata[12]);//ΩˆË”„
	Fish fish2(m_sprfish,&m_fishdata[6]);// ¿∂…´”„
	Fish fish3(m_sprfish,&m_fishdata[22]);//”Œ”æ»¶∫£πÍ
	Fish fish4(m_sprfish,&m_fishdata[8]);// ª∆…´”„
	Fish fish5(m_sprfish,&m_fishdata[11]);// kongque
	Fish fish6(m_sprfish,&m_fishdata[15]);// —€æµ”„
	Fish fish7(m_sprfish,&m_fishdata[13]);// ∫Ï…´”„
	m_fishes[0].push_back(fish1);
	m_fishes[0][0].m_x=m_centx;
	m_fishes[0][0].m_y=m_centy-30;
	m_fishnum[0]++;
	//∫£πÍ
	m_fishes[0].push_back(fish3);
	m_fishes[0][1].m_x=m_centx+350;
	m_fishes[0][1].m_y=m_centy-30;
	m_fishnum[0]++;

	m_fishes[0].push_back(fish3);
	m_fishes[0][2].m_x=m_centx-300;
	m_fishes[0][2].m_y=m_centy-30;
	m_fishnum[0]++;
	//—€æµ”„
	m_fishes[0].push_back(fish6);
	m_fishes[0][3].m_x=m_centx+600;
	m_fishes[0][3].m_y=m_centy-100;
	m_fishnum[0]++;

	m_fishes[0].push_back(fish6);
	m_fishes[0][4].m_x=m_centx+600;
	m_fishes[0][4].m_y=m_centy+80;
	m_fishnum[0]++;
	for(int i=0;i<36;i++)
	{
	   m_fishes[0].push_back(fish2);
	   m_fishes[0][5+i].m_x=m_centx-400+(i%18)*50.0f;
	   if(i>3&&i<14)
		   m_fishes[0][5+i].m_y=m_centy-280;
	   else if(i==3||i==14)
		   m_fishes[0][5+i].m_y=m_centy-180;
	   else
	       m_fishes[0][5+i].m_y=m_centy-150+(i/18)*250.0f;
	   m_fishnum[0]++;
	}

	for(int i=0;i<14;i++)
	{
	   m_fishes[0].push_back(fish2);
	   if(i==6)
	   {
	     m_fishes[0][41+i].m_x=m_centx-215;
		 m_fishes[0][41+i].m_y=m_centy-225;
	   }
	   else if(i==13)
	   {
	     m_fishes[0][41+i].m_x=m_centx+265;
		 m_fishes[0][41+i].m_y=m_centy-225;
	   }
	   else
	   {
		 m_fishes[0][41+i].m_x=m_centx-450+(i/7)*950;
		 m_fishes[0][41+i].m_y=m_centy-150+(i%7)*50.0f;
	   }
	   m_fishnum[0]++;
	}
	for(int i=0;i<3;i++)
	{
	   m_fishes[0].push_back(fish5);
	   m_fishes[0][55+i].m_x=m_centx-120+i*120;
	   m_fishes[0][55+i].m_y=m_centy-200;
	    m_fishnum[0]++;
	}
	for(int i=0;i<5;i++)
	{
	   m_fishes[0].push_back(fish4);
	   m_fishes[0][58+i].m_x=m_centx-400;
	   m_fishes[0][58+i].m_y=m_centy-170-i*50.0f;
	    m_fishnum[0]++;
	}
	for(int i=0;i<50;i++)
	{
	   m_fishes[0].push_back(fish7);
	   m_fishes[0][63+i].m_x=hge->Random_Float(m_centx-300+(i/25)*600.0f,m_centx-200+(i/25)*600.0f);
	   m_fishes[0][63+i].m_y=hge->Random_Float(m_centy+120,m_centy+240);
	   m_fishnum[0]++;
	}
}


void G_Fish::InitFishArray7(void)
{
	m_centx=720;
	m_centy=450;
	Fish fish1(m_sprfish,&m_fishdata[7]);//∫⁄Õ≈
	Fish fish2(m_sprfish,&m_fishdata[14]);//∫˚µ˚”„
	Fish fish3(m_sprfish,&m_fishdata[8]);//ª∆…´”„
	Fish fish4(m_sprfish,&m_fishdata[6]);// ¿∂…´”„
	Fish fish5(m_sprfish,&m_fishdata[13]);// ∫Ï…´”„

	m_fishes[0].push_back(fish1);
	m_fishes[0][0].m_x=m_centx;
	m_fishes[0][0].m_y=m_centy;
	m_fishnum[0]++;

	float rot=hge->Random_Float(0,2*PI);
	float r=1500;
	for(int i=0;i<3;i++)
	{
	  m_fishes[0].push_back(fish2);
	  m_fishes[0][1+i].m_rot+=rot;
	  m_fishes[0][1+i].m_x=m_centx;
	  m_fishes[0][1+i].m_y=m_centy;
	  m_fishes[0][1+i].m_tox=cos(rot)*r;
	  m_fishes[0][1+i].m_toy=sin(rot)*r;
	  rot+=hge->Random_Float(PI/3,2*PI/3);
	  m_fishes[0][1+i].ChangeWay(m_fishes[0][1+i].m_tox,m_fishes[0][1+i].m_toy,3,3);
	  m_fishnum[0]++;
	}

	for(int i=0;i<540;i++)
	{
	  rot=-PI/3+hge->Random_Float(0,PI/6)+(i/30)*PI/3;
	  if(i<180)
	     m_fishes[0].push_back(fish3);
	  else if(i<360)
		  m_fishes[0].push_back(fish4);
	  else
		  m_fishes[0].push_back(fish5);

	  m_fishes[0][4+i].m_rot=rot;
	  m_fishes[0][4+i].m_x=m_centx;
	  m_fishes[0][4+i].m_y=m_centy;
	  m_fishes[0][4+i].m_tox=m_fishes[0][4+i].m_x+cos(rot)*r;
	  m_fishes[0][4+i].m_toy=m_fishes[0][4+i].m_y+sin(rot)*r;
	  m_fishes[0][4+i].ChangeWay(m_fishes[0][4+i].m_tox,m_fishes[0][4+i].m_toy,hge->Random_Float(3,5),hge->Random_Float(3,5));
	  m_fishnum[0]++;
	}
	for(int i=1;i<3;i++)
	{
		m_fishes[0][1+i].m_teamhead=&m_fishes[0][i];
		m_fishes[0][1+i].m_sta=FISH_READY;
	}
	for(int i=0;i<540;i++)
	 {
		if(i%30==0)
			m_fishes[0][4+i].m_teamhead=NULL;
		else
		    m_fishes[0][4+i].m_teamhead=&m_fishes[0][3+i];
		m_fishes[0][4+i].m_sta=FISH_READY;
	 }
}


void G_Fish::InitFishArray8(void)
{
	m_centx=0;
	m_centy=0;
	Fish fish1(m_sprfish,&m_fishdata[13]);// ∫Ï…´”„
	for(int i=0;i<80;i++)
	{
		m_fishes[0].push_back(fish1);
		fish1.m_x=hge->Random_Float(0,1440);
		fish1.m_y=-100+(i/40)*1100.0f;
		fish1.m_rot=PI/2+(i/40)*PI;
		fish1.m_vx=0;
		if(i<40)
		    fish1.m_vy=hge->Random_Float(2,5);
		else
			fish1.m_vy=hge->Random_Float(-5,-2);
		m_fishnum[0]++;
	}
	for(int i=0;i<20;i++)
	{
	  Fish fish(m_sprfish,&m_fishdata[fish_id[18+rand()%3]]);
	  m_fishes[0].push_back(fish);
	  m_fishes[0][80+i].m_y=hge->Random_Float(-100,1000);
	  if(m_fishes[0][80+i].m_y>450)
		 m_fishes[0][80+i].m_toy=hge->Random_Float(0,450);
	  else
		 m_fishes[0][80+i].m_toy=hge->Random_Float(450,900);;
	  if(m_bleft)
	  {
		  m_fishes[0][80+i].m_x=-300;
		  m_fishes[0][80+i].m_tox=1800;
	  }
	  else
	  {
	     m_fishes[0][80+i].m_x=1800;
		 m_fishes[0][80+i].m_tox=-300;
	  }
	  m_fishes[0][80+i].ChangeWay(m_fishes[0][80+i].m_tox,m_fishes[0][80+i].m_toy,hge->Random_Float(3,5),hge->Random_Float(3,5));
	  m_fishnum[0]++;
	}
	for(int i=1;i<20;i++)
	{
		m_fishes[0][80+i].m_teamhead=&m_fishes[0][79+i];
		m_fishes[0][80+i].m_sta=FISH_READY;
	}
}
