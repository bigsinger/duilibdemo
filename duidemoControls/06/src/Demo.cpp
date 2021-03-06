#include "stdafx.h"
#include "MainWnd.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);	// 实例句柄与渲染类关联
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath()); // 指定资源路径 
	
	HRESULT Hr = ::CoInitialize(NULL);	// 初始化COM库, 为加载COM库提供支持
	if( FAILED(Hr) ) return 0;

	
	CMainWndDlg* pMainDlg = new CMainWndDlg();	// 创建窗口类
	pMainDlg->Create(NULL, _T("Demo窗体"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);	  // 注册窗口类与创建窗口  
	pMainDlg->CenterWindow();	// 窗口居中显示
	pMainDlg->ShowModal();

	CPaintManagerUI::MessageLoop();	// 处理消息循环

	::CoUninitialize(); // 退出程序并释放COM库
	
	return 0;
}

