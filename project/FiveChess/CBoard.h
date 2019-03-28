#pragma once
#include <afxwin.h>
class CBoard :
	public CWnd
{
public:
	CBoard();
	~CBoard();

	void RestoreWait();
	void Clear(BOOL bWait);
	void SetColor(int color);
	int  GetColor() const;
	void SetWait(BOOL bWait);
	void SetData(int x, int y, int color);
	void DrawGame();
	void Draw(int x, int y, int color);
	void Receive();
	void Over(int x, int y);

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

private:
	CImageList m_iml;
	BOOL m_bWait;
	int m_color;
	BOOL m_bOldWait;
};

