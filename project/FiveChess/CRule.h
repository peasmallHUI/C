#pragma once

#define _WIN 0x00
#define _LOST 0x01
#define _OTHER 0x02

class CRule
{
public:
	CRule();
	~CRule();
	int Win(int color, int x, int y);		//ʤ���жϽӿں���
	BOOL Ban(int x, int y, int color);		//�����жϽӿں���
private:
	BOOL forbid2(int x, int y);				//�����ӽ����ж�
	BOOL forbid1(int x, int y);				//���ӽ����ж�
};

