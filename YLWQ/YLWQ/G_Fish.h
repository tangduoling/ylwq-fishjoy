#pragma once
#include"main.h"
class GameBack;
class G_Fish
{
public:
	G_Fish(void);
	G_Fish(HGE*phge);
	~G_Fish(void);
	HGE*         m_phge;
	HTEXTURE     m_texfish[38];//�������
	hgeSprite**  m_sprfish[23];//��Ķ�����
	hgeSprite*   m_sprmj;     //�������ī��
	AnimationData   m_fishdata[23];//�������
	vector<Fish> m_fishes[5];//��
	int  m_fishnum[5];//�������
	int  m_fisharray;//������Ⱦ�ĸ�����
	float m_centx;
	float m_centy;
	bool m_bchangesta;//�Ƿ�ı䱳����
	bool m_bleft;     
	void Render(GameBack*gameback);
	void LoadTexture(void);
	void InitFishArray1();
	void InitFishArray0(void);
	void InitFishArray2();
	void InitFishTeam(int teamnum);
	bool IsTeamEmpty(int witchteam);
	void InitFishArray3();
	void InitFishArray4(void);
	bool IsInPolygun(Pos pos, Pos A, Pos B, Pos C,Pos D);
	void InitFishArray5(void);
	void InitFishArray6(void);
	void InitFishArray7(void);
	void InitFishArray8(void);
};

