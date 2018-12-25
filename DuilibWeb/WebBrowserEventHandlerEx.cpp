#include "stdafx.h"
#include "WebBrowserEventHandlerEx.h"


CWebBrowserEventHandlerEx::CWebBrowserEventHandlerEx()
{
}


CWebBrowserEventHandlerEx::~CWebBrowserEventHandlerEx()
{
}

void CWebBrowserEventHandlerEx::DocumentComplete(IDispatch *pDisp, VARIANT *&url)
{
	//MessageBoxW(NULL, L"Load Complete", L"", MB_OK);

	DUITRACE("CWebBrowserEventHandlerEx::DocumentComplete Enter\r\n");

	return;
}

void CWebBrowserEventHandlerEx::NavigateComplete2(IDispatch *pDisp,VARIANT *&url)
{
	DUITRACE("CWebBrowserEventHandlerEx::NavigateComplete2 Enter\r\n");
	return;
}