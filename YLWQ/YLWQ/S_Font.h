#pragma once
#include "main.h";
struct font{
	string name;
	string file_path;
};
class S_Font
{
public:
	font myfont[3];
	hgeFont* reFont;
public:
	S_Font(void);
	S_Font(hgeFont*,int);
	~S_Font(void);
};

