#include "stdafx.h"
#include "MainWnd.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
	
	CMainWndDlg* pMainDlg = new CMainWndDlg();
	pMainDlg->Create(NULL, _T("Demo窗体"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pMainDlg->CenterWindow();
	pMainDlg->ShowModal();

	//CPaintManagerUI::MessageLoop();//进入消息循环

	::CoUninitialize();//退出程序并释放COM库
	return 0;
}

