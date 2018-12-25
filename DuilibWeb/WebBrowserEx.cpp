#include "stdafx.h"
#include "WebBrowserEx.h"


CWebBrowserEx::CWebBrowserEx()
{
}

CWebBrowserEx::~CWebBrowserEx()
{
}

LPCTSTR CWebBrowserEx::GetClass() const
{
	DUITRACE("★★★CWebBrowserEx::GetClass Enter\r\n");

	return "WebBrowserEx";
}

LPVOID CWebBrowserEx::GetInterface(LPCTSTR pstrName)
{
	DUITRACE("★★★CWebBrowserEx::GetInterface Enter: pstrName : %s\r\n", pstrName);

	if (_tcsicmp(pstrName, _T("Browser")) == 0)
	{
		return static_cast<CWebBrowserEx*>(this);
	}
	return CControlUI::GetInterface(pstrName);
}


STDMETHODIMP CWebBrowserEx::GetExternal(IDispatch** ppDispatch)
{
	DUITRACE("★★★CWebBrowserEx::GetExternal Enter\r\n");

	*ppDispatch = this;
	return(S_OK);
}

//HRESULT STDMETHODCALLTYPE CWebBrowserEx::GetIDsOfNames(__RPC__in REFIID riid, __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames, UINT cNames, LCID lcid, __RPC__out_ecount_full(cNames) DISPID *rgDispId)
STDMETHODIMP CWebBrowserEx::GetIDsOfNames(REFIID riid, OLECHAR **rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)
{
	HRESULT hr = NOERROR;
	UINT    i = 0;
	CString cszName = rgszNames[i];

	DUITRACE("★★★CWebBrowserEx::GetIDsOfNames Enter: rgszNames : %s\r\n", cszName);

	for (i = 0; i < cNames; ++i)
	{
		if (cszName == _T("JavaScriptCallCpp"))
		{
			//rgDispId[i] = 100;
			*rgDispId = 100;
		}
		else  {
			/* 此处很关键，如果没有很容易造成程序崩溃 */
			hr = ResultFromScode(DISP_E_UNKNOWNNAME);
			rgDispId[i] = DISPID_UNKNOWN;
		}
	}

	//return __super::GetIDsOfNames(riid, rgszNames, cNames, lcid, rgDispId);
	return(S_OK);
}

//HRESULT STDMETHODCALLTYPE CWebBrowserEx::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
STDMETHODIMP CWebBrowserEx::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, 
	DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
	DUITRACE("★★★CWebBrowserEx::Invoke Enter: dispIdMember : %d\r\n", dispIdMember);

	if (dispIdMember == 100)
	{
		CString strTemp;

		strTemp.Format("Javascript call cpp : ");

		for (int i = pDispParams->cArgs - 1; i >= 0; i--)
		{
			BSTR bstr;
			bstr = pDispParams->rgvarg[i].bstrVal;

			strTemp += bstr;
			strTemp += L", ";

			//_com_util::ConvertBSTRToString(pDispParams->rgvarg[2].bstrVal);

		}

		MessageBox(NULL, strTemp, "HAHA，DUILIB JS <--> C++", MB_OK);

	}

	return __super::Invoke(dispIdMember, riid, lcid, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);
	//return(S_OK);
}