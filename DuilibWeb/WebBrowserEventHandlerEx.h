#pragma once

class CWebBrowserEventHandlerEx : public CWebBrowserEventHandler
{
public:
	CWebBrowserEventHandlerEx();
	~CWebBrowserEventHandlerEx();

	virtual void DocumentComplete(IDispatch *pDisp, VARIANT *&url);
	virtual void NavigateComplete2(IDispatch *pDisp,VARIANT *&url);
};