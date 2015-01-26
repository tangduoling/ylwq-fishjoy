#pragma once
#include"main.h"
class GCom
{
public:
	GCom(void);
	~GCom(void);
protected:
	HANDLE m_ghcom;
	DCB m_gdcb;
	COMMTIMEOUTS m_timeouts;
	DWORD m_dr;
	DWORD m_dw;
public:
	BYTE m_gkey[256];
	bool Init(void);
	bool GK_Up(DWORD px,BYTE key);
	bool GK_Down(DWORD px,BYTE key1,BYTE key2);
	void UpDataKey(void);
	int Chek(void);
};

