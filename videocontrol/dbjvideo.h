// dbjvideo.h : Declaration of the Cdbjvideo

#ifndef __DBJVIDEO_H_
#define __DBJVIDEO_H_

#include "resource.h"       // main symbols
#include <atlctl.h>

#include <comdef.h>


/////////////////////////////////////////////////////////////////////////////
// Cdbjvideo
class ATL_NO_VTABLE Cdbjvideo : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<Cdbjvideo, Idbjvideo, &IID_Idbjvideo, &LIBID_VIDEOCONTROLLib>,
	public CComControl<Cdbjvideo>,
	public IPersistStreamInitImpl<Cdbjvideo>,
	public IOleControlImpl<Cdbjvideo>,
	public IOleObjectImpl<Cdbjvideo>,
	public IOleInPlaceActiveObjectImpl<Cdbjvideo>,
	public IViewObjectExImpl<Cdbjvideo>,
	public IOleInPlaceObjectWindowlessImpl<Cdbjvideo>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<Cdbjvideo>,
	public CComCoClass<Cdbjvideo, &CLSID_dbjvideo>
{
public:
	Cdbjvideo()
	{
		m_bWindowOnly = TRUE;

	}

DECLARE_REGISTRY_RESOURCEID(IDR_DBJVIDEO)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(Cdbjvideo)
	COM_INTERFACE_ENTRY(Idbjvideo)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_PROP_MAP(Cdbjvideo)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY("BorderStyle", DISPID_BORDERSTYLE, CLSID_NULL)
	PROP_ENTRY("BorderWidth", DISPID_BORDERWIDTH, CLSID_NULL)
	PROP_ENTRY("HWND", DISPID_HWND, CLSID_NULL)
	PROP_ENTRY("MouseIcon", DISPID_MOUSEICON, CLSID_StockPicturePage)
	PROP_ENTRY("MousePointer", DISPID_MOUSEPOINTER, CLSID_NULL)
	PROP_ENTRY("Picture", DISPID_PICTURE, CLSID_StockPicturePage)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(Cdbjvideo)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(Cdbjvideo)
	CHAIN_MSG_MAP(CComControl<Cdbjvideo>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
//--------------------------------------------------------------
BEGIN_CATEGORY_MAP(Cdbjvideo)
    IMPLEMENTED_CATEGORY(CATID_SafeForScripting) 
    IMPLEMENTED_CATEGORY(CATID_SafeForInitializing) 
    IMPLEMENTED_CATEGORY(dbjsys::com::CATID_DBJSystems()) 
END_CATEGORY_MAP()
//--------------------------------------------------------------
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* arr[] = 
		{
			&IID_Idbjvideo,
		};
		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// Idbjvideo
public:

	HRESULT OnDrawAdvanced(ATL_DRAWINFO& di)
	{
        ::RECT& rc = *(RECT*)di.prcBounds;
        ::Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

        // center text
        ::SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
        _bstr_t pszText(_T("DBJSystems : VideoControl"));
        ::TextOut(di.hdcDraw, (rc.left + rc.right) / 2, (rc.top + rc.bottom) / 2, 
			(const TCHAR*)pszText, pszText.length() );

        // left edge text
        ::SetTextAlign(di.hdcDraw, TA_LEFT|TA_BASELINE);
        pszText = (_bstr_t)_variant_t(rc.left) ;
        ::TextOut(di.hdcDraw, rc.left + 2, (rc.top + rc.bottom) / 2, 
			(const TCHAR*)pszText, pszText.length() );

        // right edge text
        ::SetTextAlign(di.hdcDraw, TA_RIGHT|TA_BASELINE);
        pszText = (_bstr_t)_variant_t(rc.right) ;
        ::TextOut(di.hdcDraw, rc.right - 2, (rc.top + rc.bottom) / 2, 
			(const TCHAR*)pszText, pszText.length() );

        // top edge text
        ::SetTextAlign(di.hdcDraw, TA_TOP);
        pszText = (_bstr_t)_variant_t(rc.top) ;
        ::TextOut(di.hdcDraw, (rc.right + rc.left) / 2, rc.top + 2, 
			(const TCHAR*)pszText, pszText.length() );

        // bottom edge text
        ::SetTextAlign(di.hdcDraw, TA_BOTTOM );
        pszText = (_bstr_t)_variant_t(rc.bottom ) ;
        ::TextOut(di.hdcDraw, (rc.right + rc.left) / 2, rc.bottom  - 2, 
			(const TCHAR*)pszText, pszText.length() );

		return S_OK;
	}
	LONG m_nBorderStyle;
	LONG m_nBorderWidth;
	CComPtr<IPictureDisp> m_pMouseIcon;
	LONG m_nMousePointer;
	CComPtr<IPictureDisp> m_pPicture;
};

#endif //__DBJVIDEO_H_
