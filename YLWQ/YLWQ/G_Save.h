#pragma once
#include "main.h"
class G_Save
{
public:
	G_Save(void);
	~G_Save(void);
	FILE *m_savefile;//�ļ�ָ��
	SaveData m_initdata;//�������ݱ���
	void ReadSaveData(const char* file, SaveData* save);//��ȡ������ļ�
	void WriteSaveData(const char* file, SaveData* save);//���ļ���д����
};

