#pragma once

#define _WIN 0x00
#define _LOST 0x01
#define _OTHER 0x02

class CRule
{
public:
	CRule();
	~CRule();
	int Win(int color, int x, int y);		//胜负判断接口函数
	BOOL Ban(int x, int y, int color);		//禁手判断接口函数
private:
	BOOL forbid2(int x, int y);				//非连子禁手判断
	BOOL forbid1(int x, int y);				//连子禁手判断
};

