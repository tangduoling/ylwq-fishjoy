
#include "main.h"

G_Save::G_Save(void)
{
	SYSTEMTIME nowsys;//系统时间
	GetLocalTime(&nowsys);//获取系统时间
	m_initdata.centin=0;
	m_initdata.centout=0;
	m_initdata.coinin=0;
	m_initdata.coinout=0;
	m_initdata.ticketout=0;
	m_initdata.lastearn=0;
	m_initdata.codetimes=0;
	m_initdata.lastcodesys=nowsys;
	for(int i=0;i<6;i++)
	   m_initdata.playercent[i]=0;
	m_initdata.set.coin=1;
	m_initdata.set.dificul=0;
	m_initdata.set.maxcent=99;
	m_initdata.set.mincent=1;
	m_initdata.set.mode=0;
	m_initdata.set.ticket=10;
	m_initdata.set.coincent=10;
	m_initdata.set.bplace=false;
	m_initdata.set.bshow=false;
	m_initdata.set.codetime=5;
}

G_Save::~G_Save(void)
{
}

void G_Save::ReadSaveData(const char* file, SaveData* save)
{
  m_savefile=fopen(file,"rb+");
  //如果文件为空则写入文件
  if(!m_savefile)
   {
	  WriteSaveData(file,&m_initdata);
      m_savefile=fopen(file,"rb+");
   }
  fread(save,sizeof(SaveData),1,m_savefile);
  fclose(m_savefile);
}

void G_Save::WriteSaveData(const char* file, SaveData* save)
{
	m_savefile=fopen(file,"wb+");
    fwrite(save,sizeof(SaveData),1,m_savefile);
    fclose(m_savefile);
}

/*FILE*file=fopen("save.dat","r+b");
	fread(&save,sizeof(SaveData),1,file);
	while(run)
	{
		cin>>coinin;
		save.coinin+=coinin;
		cout<<abs((int)save.coinin)<<endl;
		//run=false;
	}
	//save.coinin=abs((int)save.coinin);
	fclose(file);
	FILE*savefile=fopen("save.dat","w+b");
	fwrite(&save,sizeof(SaveData),1,savefile);
	fclose(savefile);*/