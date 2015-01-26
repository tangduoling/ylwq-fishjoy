#include "S_Font.h"


S_Font::S_Font(void)
{
	
}

S_Font::S_Font(hgeFont* f,int n)
{
	//myfont[n].name="";
	//myfont[n].filepath="PIC\\font1.fnt";
	reFont=new hgeFont("PIC\\font1.fnt");
	reFont->SetColor(0Xffaaffcc);
	reFont->SetZ(0.0f); 
}

S_Font::~S_Font(void)
{
	delete reFont;
}
