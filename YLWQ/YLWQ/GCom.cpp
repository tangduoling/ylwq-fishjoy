#include "main.h"
#include "GCom.h"
//和游戏手柄对接
GCom::GCom(void)
{	
}


GCom::~GCom(void)
{
	if(m_ghcom)
		CloseHandle(m_ghcom);
}


bool GCom::Init(void)
{
	m_ghcom=CreateFile(L"COM1",//COM1口
	GENERIC_READ|GENERIC_WRITE, //允许读和写
	0, //独占方式
	NULL,
	OPEN_EXISTING, //打开而不是创建
	0, //同步方式
	NULL);
	SetupComm(m_ghcom,1024,1024);
	if(m_ghcom==(HANDLE)-1)
	{
		//MessageBox(NULL,L"创建串口失败",L"错误提示",MB_OK); 
		return false;
	}

	m_timeouts.ReadIntervalTimeout=1;//读取两个字符的时间差，假如超过该时间还没读到下一个字符就返回
	m_timeouts.ReadTotalTimeoutMultiplier=1;//设置读取一个字节和等 待下一个字节所需的时间，
	                                        //这样总的超时时间为读取的字节数乘以该值，
	                                        //同样一次读取 操作到达这个时间后，也认为本次读操作己经结束。 
	m_timeouts.ReadTotalTimeoutConstant=10;
	m_timeouts.WriteTotalTimeoutMultiplier=10;
	m_timeouts.WriteTotalTimeoutConstant=100;
	SetCommTimeouts(m_ghcom,&m_timeouts);

	GetCommState(m_ghcom,&m_gdcb);
	m_gdcb.BaudRate=115200;
	m_gdcb.ByteSize=8;
	m_gdcb.Parity=NOPARITY;
	m_gdcb.StopBits=ONESTOPBIT;
	SetCommState(m_ghcom,&m_gdcb);
	return true;
}


bool GCom::GK_Up(DWORD px,BYTE key)
{
	return false;
}


bool GCom::GK_Down(DWORD px,BYTE key1,BYTE key2)
{
	  if((m_gkey[1+px]==key1)&&(m_gkey[12]==key2))
		return true;
	return false;
}


void GCom::UpDataKey(void)
{
	ReadFile(m_ghcom,m_gkey,13,&m_dr,NULL);
}
