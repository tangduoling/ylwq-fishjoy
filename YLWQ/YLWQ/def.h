class Game;
#ifndef _DEF_H_
#define _DEF_H_
#define G_FPS   30  //���FPS

#define G_PLAYERNUM 2 //�����Ŀ
#define G_SCREENWIDTH 1366 //��Ļ��
#define G_SCREENHEIGHT 768 //��Ļ��


#define PI    4*atan(1.0f)  
#define KEY_DOWN(vk_code)((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define PK_D(vk_code) (GetAsyncKeyState(vk_code) &1)
#define GK_D(vk_code) hge->Input_KeyDown(vk_code)
#define GK_U(vk_code) hge->Input_KeyUp(vk_code)
#define GAME_SET            0
#define GAME_PLAYING        1
#define GAME_OUTOFTIME      2
#define FISH_RUN     0
#define FISH_DIE     1
#define FISH_DIS     2
#define FISH_READY   3

#define FISH_ARRAY0     0
#define FISH_ARRAY1     1
#define FISH_ARRAY2     2
#define FISH_ARRAY3     3
#define FISH_ARRAY4     4
#define FISH_ARRAY5     5
#define FISH_ARRAY6     6
#define FISH_ARRAY7     7
#define FISH_ARRAY8     8

#define BULLET_FIRE     0
#define BULLET_RUN      1
#define BULLET_HIT      2

#define FCOIN_RUN       3
#define FCOIN_DIS       4
#define DCOIN_ROT       5
#define DCOIN_NROT      6

#define BACK_0  0
#define BACK_1  1
#define BACK_2  2

#define G_DIFFICUL0     0
#define G_DIFFICUL1     1
#define G_DIFFICUL2     2
#define G_DIFFICUL3     3

#define SET_BEGIN       0
#define SET_PARAMER     1
#define SET_PRESSCODE   2
#define SET_AUDIT       3
#define SET_TELLAUDIT   4
struct Pos
{
	float x;
	float y;
};
struct SysInfo
{
	string sysVersion;
	int pWidth;
	int pHeight;
};
typedef struct typBullet
{
  float x;         //�ӵ�������
  float y;
  float vx;        //�ӵ����ٶ�
  float vy;   
  float rot;       //�ӵ��ķ���
  int   id;        //��ʶ�ӵ�������һ�����
  int   sta;      //�ӵ�״̬
  int   time;     //��Ⱦ�ӵ�״̬�ļ�����
}Bullet,*pbullet;

typedef struct typAnimationData
{
  int id;           //�������
  int frames;      //���ζ�ʱ����֡��
  int dieframes;   //������ʱ����֡��
  int  nfc;        //��������Ľ������
  int cent;        //��ķ�ֵ
  float w;         //��Ŀ��
  float h;         //��ĳ���
  int effid;
}AnimationData,*pAnimationData;

typedef struct typFCoin
{
	bool  bfly;//�ɱҵ�״̬
	bool  bj; //�ɱ��ǽ�����
	float vx; //�ɱҵ��ٶ�
	float vy;
	float x; //�ɱҵ�λ��
	float y;
}FCoin,*pFCoin;
typedef struct typDCoin
{
	bool  brot;  //���ҵ�״̬
	int   time;  //������
}DCoin,*pDCoin;

struct SaveSet//��̨����������Ϣ
{
	int dificul;
	int coin;
	int ticket;
	int mincent;
	int maxcent;
	int mode;
	int coincent;
	bool bplace;
	int  codetime;
	bool bshow;
};
struct SaveData//��̨����������Ϣ
{
  int centin;      //���Ϸ�
  int centout;     //���·�
  int coinin;     //�ܽ���
  int coinout;    //���˱�
  int ticketout;
  int lastearn;   //�ϴ���ӯ��
  int codetimes;  //�������
  SYSTEMTIME lastcodesys;//
  int playercent[6];//��ұ���Ŀ
  SaveSet set;
};
extern HGE*  hge;
extern Game* game;
extern float timer;
extern DWORD time;
extern float g_t;
extern char*cTex[];
extern char*cEff[];
extern char*cEff1[];
const float ftoearn[]={0.025f,0.05f,0.075f,0.1f};//�����Ѷ�ϵ��
const int fish_id[]={13,6,8,14,10,11,5,3,0,22,21,20,15,16,17,1,9,2,4,12,19,18,7};
const int LineNum=267;
const int MachineNum=81123584;
#endif