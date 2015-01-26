#pragma once
#include"main.h"
class G_Set
{
public:
	G_Set(void);
	G_Set(HGE*phge);
	~G_Set(void);
	HGE* m_phge;
	HTEXTURE m_texsetback[4];
	HTEXTURE m_texcur[2];
	HTEXTURE m_texmenu[6];
	HTEXTURE m_texparamer[10];
	HTEXTURE m_texaudit;
	HTEXTURE m_texnum[10];
	HTEXTURE m_texhelpline[3];
	HTEXTURE m_texhelp[6];
	HTEXTURE m_texpasswin[9];
	HTEXTURE m_textell[12];
	hgeSprite* m_sprsetback[4];
	hgeSprite* m_sprcur[2];
	hgeSprite* m_sprmenu[6];
	hgeSprite* m_sprparamer;
	hgeSprite* m_sprdif[4];
	hgeSprite* m_sprmode[4];
	hgeSprite* m_spraudit;
	hgeSprite** m_sprnum[10];
	hgeSprite*  m_sprhelp[6];
	hgeSprite*  m_sprhelpline[3];
	hgeSprite*  m_sprpasswin[4];
	hgeSprite*  m_spryesno[3];
	hgeSprite*  m_sprnumline[2];
	hgeSprite*  m_sprtell[12];
	Pos  m_curpos;
	bool m_bwin;
	bool m_bcoding;
	bool m_brightcode;
	bool m_byes;
	int  m_passwin;
	int  m_cur;     //光标位置
	int  m_line;    //输入密码下划线位置
	int  m_num;
	int  m_setwhat;
	int  m_codingtime;
	vector<int>cinnum;
	SaveSet m_set;
	void LoadTexture(void);
	void RenderSet(void);
	void SetParameter(void);
	void GetSaveSet(SaveData* save);
	void SetBegin(void);
	void SetHitCode(void);
	void Audit(void);
	void PassWord(void);
	void SetTellAudit(void);
	void ScanNum(int n);
};

