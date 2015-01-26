#pragma once
#include"main.h"
class Fish
{
public:
	Fish(void);
	Fish(hgeSprite***spr,pAnimationData pdata);
	~Fish(void);
public:
	hgeSprite**m_spr;
	pAnimationData m_pdata;
	Fish* m_teamhead;   //С����εĶ���
	int   m_sta;       //���״̬
	int   m_deadtime;  //������ʱ�ļ���
	int   m_effid;    //���������ʶ
	int   m_runmode;  //����˶�����
	bool  m_bchange;  //���Ƿ�ı��˶�����
	bool  m_bcanhit;  
	int   m_playerhit[G_PLAYERNUM];//ÿ����ҷֱ���˶�������
	float m_x;           //λ��
	float m_y;   
	float m_tox;         //ֱ���˶��ﵽĳ��λ�øı䷽��
	float m_toy;     
	float m_torot;       //�����˶�ʱ�ﵽһ�����ȸı䷽��
	float m_a;           //���ٶ�
	float m_c;       
	float m_vx;          //�ٶ�
	float m_vy;
	float m_rot;       //�Ƕ�  
	void RenderFishArray1(void);
	void RenderFishArray0(void);
	void ChangeWay(float x,float y,float vx,float vy);
	void RenderFishArray2(void);
	void RenderMode(int mode);
	void ChangeWay();
	void RenderDie(void);
	void RenderFishArray3(int mode);
};

