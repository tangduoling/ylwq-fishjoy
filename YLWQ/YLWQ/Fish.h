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
	Fish* m_teamhead;   //小鱼队形的队首
	int   m_sta;       //鱼的状态
	int   m_deadtime;  //鱼死亡时的计数
	int   m_effid;    //鱼的声音标识
	int   m_runmode;  //鱼的运动类型
	bool  m_bchange;  //鱼是否改变运动类型
	bool  m_bcanhit;  
	int   m_playerhit[G_PLAYERNUM];//每个玩家分别打了多少下鱼
	float m_x;           //位置
	float m_y;   
	float m_tox;         //直线运动达到某点位置改变方向
	float m_toy;     
	float m_torot;       //曲线运动时达到一定弧度改变方向
	float m_a;           //加速度
	float m_c;       
	float m_vx;          //速度
	float m_vy;
	float m_rot;       //角度  
	void RenderFishArray1(void);
	void RenderFishArray0(void);
	void ChangeWay(float x,float y,float vx,float vy);
	void RenderFishArray2(void);
	void RenderMode(int mode);
	void ChangeWay();
	void RenderDie(void);
	void RenderFishArray3(int mode);
};

