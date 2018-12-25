#pragma once

#include "WebBrowserEx.h"
#include "WebBrowserEventHandlerEx.h"

class  CHelloDuilibWnd: public WindowImplBase
{
public:
	CHelloDuilibWnd();
	~CHelloDuilibWnd();
	DUI_DECLARE_MESSAGE_MAP()

	virtual void Notify(TNotifyUI& msg);
	virtual void OnClick(TNotifyUI& msg);
	virtual void OnWindowInitialized(TNotifyUI& msg);

	virtual void InitWindow();

	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	void OnPrepare(TNotifyUI& msg);

protected:

	virtual CDuiString GetSkinFolder() { return _T("skin"); };
	virtual CDuiString GetSkinFile()  { return _T("HelloDuilib.xml"); };
	virtual LPCTSTR GetWindowClassName(void) const { return _T("HelloDuilib_Wnd"); };

private:

	CButtonUI*				m_pbtnGo;
	CButtonUI*				m_pbtnCallJS;

	CEditUI*				m_peditURL;

	CWebBrowserEventHandlerEx	 m_CWBEventHandler;
	CWebBrowserEx*			m_pWebBrowserEx;
};