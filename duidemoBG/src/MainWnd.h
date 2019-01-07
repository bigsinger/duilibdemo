#pragma once

class CMainWndDlg : public CWindowWnd, public INotifyUI
{
public:
	CMainWndDlg(void);
	~CMainWndDlg(void);

public:

	LPCTSTR GetWindowClassName() const;
	
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	void Notify(TNotifyUI& msg); 

	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

protected:
	CPaintManagerUI m_PaintManager;		//与控件绘制和消息处理关联起来

};
