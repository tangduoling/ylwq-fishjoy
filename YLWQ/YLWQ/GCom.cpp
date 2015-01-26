#include "main.h"
#include "GCom.h"
//����Ϸ�ֱ��Խ�
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
	m_ghcom=CreateFile(L"COM1",//COM1��
	GENERIC_READ|GENERIC_WRITE, //�������д
	0, //��ռ��ʽ
	NULL,
	OPEN_EXISTING, //�򿪶����Ǵ���
	0, //ͬ����ʽ
	NULL);
	SetupComm(m_ghcom,1024,1024);
	if(m_ghcom==(HANDLE)-1)
	{
		//MessageBox(NULL,L"��������ʧ��",L"������ʾ",MB_OK); 
		return false;
	}

	m_timeouts.ReadIntervalTimeout=1;//��ȡ�����ַ���ʱ�����糬����ʱ�仹û������һ���ַ��ͷ���
	m_timeouts.ReadTotalTimeoutMultiplier=1;//���ö�ȡһ���ֽں͵� ����һ���ֽ������ʱ�䣬
	                                        //�����ܵĳ�ʱʱ��Ϊ��ȡ���ֽ������Ը�ֵ��
	                                        //ͬ��һ�ζ�ȡ �����������ʱ���Ҳ��Ϊ���ζ��������������� 
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
