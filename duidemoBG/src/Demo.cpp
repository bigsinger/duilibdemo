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
	pMainDlg->Create(NULL, _T("Demo����"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pMainDlg->CenterWindow();
	pMainDlg->ShowModal();

	//CPaintManagerUI::MessageLoop();//������Ϣѭ��

	::CoUninitialize();//�˳������ͷ�COM��
	return 0;
}

