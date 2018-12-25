// prjTest_CPP_JS_Inter_Call_In_DuiLib.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HelloDuilibWnd.h"

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR lpCmdLine,int ShowCmd)

//int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
//					   _In_opt_ HINSTANCE hPrevInstance,
//					   _In_ LPTSTR    lpCmdLine,
//					   _In_ int       nCmdShow)
{
#if defined(WIN32) && !defined(UNDER_CE)
	HRESULT Hr = ::CoInitialize(NULL);
#else
	HRESULT Hr = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
#endif

	CPaintManagerUI::SetInstance(hInstance);// ����XML��ʱ����Ҫʹ�øþ��ȥ��λEXE��·�������ܼ���XML��·��

#if 1

	CHelloDuilibWnd wnd; // ���ɶ���

	wnd.Create(NULL, NULL, UI_WNDSTYLE_DIALOG, 0); // ����DLG����
	wnd.CenterWindow(); // ���ھ���
	wnd.ShowModal(); // ��ʾ

#else

	CHelloDuilibWnd* wnd = new CHelloDuilibWnd; // ���ɶ���

	wnd->Create(NULL, NULL, UI_WNDSTYLE_DIALOG, 0); // ����DLG����
	wnd->CenterWindow(); // ���ھ���
	wnd->ShowWindow(); // ��ʾ

	CPaintManagerUI::MessageLoop(); // ��Ϣѭ��

	delete wnd; // ɾ������

#endif

	::CoUninitialize();
	return 0;
}