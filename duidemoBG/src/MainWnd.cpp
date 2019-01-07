#include "stdAfx.h"
#include "MainWnd.h"

CMainWndDlg::CMainWndDlg(void)
{
}

CMainWndDlg::~CMainWndDlg(void)
{
}

LPCTSTR CMainWndDlg::GetWindowClassName() const
{
	return _T("UIMainWnd");
}

LRESULT CMainWndDlg::HandleMessage( UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	LRESULT lRes = 0;
	BOOL bHandled = TRUE;

	switch( uMsg ) 
	{
	case WM_CREATE:        
		lRes = OnCreate(uMsg, wParam, lParam, bHandled);
		break;

	case WM_NCACTIVATE:    
		lRes = OnNcActivate(uMsg, wParam, lParam, bHandled);
		break;

	case WM_NCCALCSIZE:   
		lRes = OnNcCalcSize(uMsg, wParam, lParam, bHandled);

	case WM_NCPAINT:      
		lRes = OnNcPaint(uMsg, wParam, lParam, bHandled);
		break;
	case WM_NCHITTEST:    
		lRes = OnNcHitTest(uMsg, wParam, lParam, bHandled); 
		break;

	default:
		bHandled = FALSE;
	}

	if( bHandled ) return lRes;
	if( m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes) ) return lRes;

	return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}

LRESULT CMainWndDlg::OnCreate( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
	m_PaintManager.Init(m_hWnd);

	CDialogBuilder builder;
	CControlUI* pRoot = builder.Create(_T("DemoSkin.xml"), (UINT)0, NULL, &m_PaintManager);   // DemoSkin.xml需要放到exe目录下
	ASSERT(pRoot && "Failed to parse XML");

	m_PaintManager.AttachDialog(pRoot);
	m_PaintManager.AddNotifier(this);   // 添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理

	return 0;
}

LRESULT CMainWndDlg::OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if( ::IsIconic(*this) ) bHandled = FALSE;

	return (wParam == 0) ? TRUE : FALSE;
}

LRESULT CMainWndDlg::OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0;
}

LRESULT CMainWndDlg::OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return 0;
}

LRESULT CMainWndDlg::OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	POINT pt; pt.x = GET_X_LPARAM(lParam); pt.y = GET_Y_LPARAM(lParam);
	::ScreenToClient(*this, &pt);

	RECT rcClient;
	::GetClientRect(*this, &rcClient);

	RECT rcCaption = m_PaintManager.GetCaptionRect();
	if( pt.x >= rcClient.left + rcCaption.left && pt.x < rcClient.right - rcCaption.right \
		&& pt.y >= rcCaption.top && pt.y < rcCaption.bottom ) {
			CControlUI* pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(pt));
			if( pControl && _tcscmp(pControl->GetClass(), _T("ButtonUI")) != 0 && 
				_tcscmp(pControl->GetClass(), _T("OptionUI")) != 0 &&
				_tcscmp(pControl->GetClass(), _T("TextUI")) != 0 )
				return HTCAPTION;
	}

	return HTCLIENT;
}

void CMainWndDlg::Notify( TNotifyUI& msg )
{
	if( msg.sType == _T("windowinit") ) {
		
	}
	else if( msg.sType == _T("click") ) {
		
	}
	else {
		
	}
}
