#pragma once
#include <afxsock.h>
class CConnect :
	public CAsyncSocket
{
public:
	CConnect();
	~CConnect();

protected:
	virtual void OnAccept(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);

};

