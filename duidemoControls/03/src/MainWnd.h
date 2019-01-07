#pragma once
#include <exdisp.h>
#include <comdef.h>

class CMainWndDlg : public CWindowWnd, public INotifyUI, public CWebBrowserEventHandler
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

	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	void Init();

	void OnWindowInit();

	void OnLBtnClick(CControlUI *pControl);

protected:
	CPaintManagerUI m_PaintManager;		//与控件绘制和消息处理关联起来

private:
	CButtonUI* m_pCloseBtn;		
	CButtonUI* m_pMaxBtn;
	CButtonUI* m_pRestoreBtn;
	CButtonUI* m_pMinBtn;

	CProgressUI* m_pProgress;	// 进度条控件

	CListUI* m_pList;			// List控件
};
