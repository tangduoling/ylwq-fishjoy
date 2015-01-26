#include"main.h"

void DrawNums(hgeSprite**spr,int _num,float x,float y,float rot,float hv,float dx,float dy)
{
	if(_num==0)
		spr[0]->RenderEx(x,y,rot,hv,hv);
	else
	{
		float numx=0,numy=0;
		int count=0,j=0;;
		for(int n=_num;n>0;n/=10)
			count++;
		for(int n=_num;n>0;n/=10)
			{
				numx=x+(count/2-j)*dx;
				numy=y+(count/2-j)*dy;
				if(count%2==0)
				{
				  numx-=dx/2;
				  numy-=dy/2;
				}
				int i=n%10;
				j++;
				spr[i]->RenderEx(numx,numy,rot,hv,hv);
			} 
	}
}

void DrawNumsR(hgeSprite**spr,int _num,float x,float y,float rot,float hv,float dx,float dy)
{

	if(_num==0)
		spr[0]->RenderEx(x,y,rot,hv,hv);
	else
	{
		float numx=x,numy=y;
		for(int n=_num;n>0;n/=10)
			{
				int i=n%10;
				spr[i]->RenderEx(numx,numy,rot,hv,hv);
				numx-=dx;
				numy-=dy;
			} 
	}
}