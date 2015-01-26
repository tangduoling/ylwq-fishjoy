#pragma once
#include "main.h"
class G_Save
{
public:
	G_Save(void);
	~G_Save(void);
	FILE *m_savefile;//文件指针
	SaveData m_initdata;//保存数据变量
	void ReadSaveData(const char* file, SaveData* save);//读取保存的文件
	void WriteSaveData(const char* file, SaveData* save);//向文件中写数据
};

