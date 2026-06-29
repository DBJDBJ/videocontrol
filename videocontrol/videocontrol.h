

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Wed Jun 15 14:41:02 2005
 */
/* Compiler settings for .\videocontrol.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __videocontrol_h__
#define __videocontrol_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __Idbjvideo_FWD_DEFINED__
#define __Idbjvideo_FWD_DEFINED__
typedef interface Idbjvideo Idbjvideo;
#endif 	/* __Idbjvideo_FWD_DEFINED__ */


#ifndef ___IdbjvideoEvents_FWD_DEFINED__
#define ___IdbjvideoEvents_FWD_DEFINED__
typedef interface _IdbjvideoEvents _IdbjvideoEvents;
#endif 	/* ___IdbjvideoEvents_FWD_DEFINED__ */


#ifndef __dbjvideo_FWD_DEFINED__
#define __dbjvideo_FWD_DEFINED__

#ifdef __cplusplus
typedef class dbjvideo dbjvideo;
#else
typedef struct dbjvideo dbjvideo;
#endif /* __cplusplus */

#endif 	/* __dbjvideo_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __Idbjvideo_INTERFACE_DEFINED__
#define __Idbjvideo_INTERFACE_DEFINED__

/* interface Idbjvideo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_Idbjvideo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7C33DB15-3DA6-4C52-B6E1-8F0D9FD73DCD")
    Idbjvideo : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderStyle( 
            /* [in] */ long style) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderStyle( 
            /* [retval][out] */ long *pstyle) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderWidth( 
            /* [in] */ long width) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderWidth( 
            /* [retval][out] */ long *width) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Window( 
            /* [retval][out] */ long *phwnd) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MousePointer( 
            /* [in] */ long pointer) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MousePointer( 
            /* [retval][out] */ long *ppointer) = 0;
        
        virtual /* [id][propputref] */ HRESULT STDMETHODCALLTYPE putref_MouseIcon( 
            /* [in] */ IPictureDisp *pMouseIcon) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MouseIcon( 
            /* [in] */ IPictureDisp *pMouseIcon) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MouseIcon( 
            /* [retval][out] */ IPictureDisp **ppMouseIcon) = 0;
        
        virtual /* [id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Picture( 
            /* [in] */ IPictureDisp *pPicture) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Picture( 
            /* [in] */ IPictureDisp *pPicture) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Picture( 
            /* [retval][out] */ IPictureDisp **ppPicture) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IdbjvideoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Idbjvideo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Idbjvideo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Idbjvideo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Idbjvideo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Idbjvideo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Idbjvideo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Idbjvideo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderStyle )( 
            Idbjvideo * This,
            /* [in] */ long style);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderStyle )( 
            Idbjvideo * This,
            /* [retval][out] */ long *pstyle);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderWidth )( 
            Idbjvideo * This,
            /* [in] */ long width);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderWidth )( 
            Idbjvideo * This,
            /* [retval][out] */ long *width);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Window )( 
            Idbjvideo * This,
            /* [retval][out] */ long *phwnd);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MousePointer )( 
            Idbjvideo * This,
            /* [in] */ long pointer);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MousePointer )( 
            Idbjvideo * This,
            /* [retval][out] */ long *ppointer);
        
        /* [id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_MouseIcon )( 
            Idbjvideo * This,
            /* [in] */ IPictureDisp *pMouseIcon);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MouseIcon )( 
            Idbjvideo * This,
            /* [in] */ IPictureDisp *pMouseIcon);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MouseIcon )( 
            Idbjvideo * This,
            /* [retval][out] */ IPictureDisp **ppMouseIcon);
        
        /* [id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Picture )( 
            Idbjvideo * This,
            /* [in] */ IPictureDisp *pPicture);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Picture )( 
            Idbjvideo * This,
            /* [in] */ IPictureDisp *pPicture);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Picture )( 
            Idbjvideo * This,
            /* [retval][out] */ IPictureDisp **ppPicture);
        
        END_INTERFACE
    } IdbjvideoVtbl;

    interface Idbjvideo
    {
        CONST_VTBL struct IdbjvideoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Idbjvideo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define Idbjvideo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define Idbjvideo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define Idbjvideo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define Idbjvideo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define Idbjvideo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define Idbjvideo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define Idbjvideo_put_BorderStyle(This,style)	\
    (This)->lpVtbl -> put_BorderStyle(This,style)

#define Idbjvideo_get_BorderStyle(This,pstyle)	\
    (This)->lpVtbl -> get_BorderStyle(This,pstyle)

#define Idbjvideo_put_BorderWidth(This,width)	\
    (This)->lpVtbl -> put_BorderWidth(This,width)

#define Idbjvideo_get_BorderWidth(This,width)	\
    (This)->lpVtbl -> get_BorderWidth(This,width)

#define Idbjvideo_get_Window(This,phwnd)	\
    (This)->lpVtbl -> get_Window(This,phwnd)

#define Idbjvideo_put_MousePointer(This,pointer)	\
    (This)->lpVtbl -> put_MousePointer(This,pointer)

#define Idbjvideo_get_MousePointer(This,ppointer)	\
    (This)->lpVtbl -> get_MousePointer(This,ppointer)

#define Idbjvideo_putref_MouseIcon(This,pMouseIcon)	\
    (This)->lpVtbl -> putref_MouseIcon(This,pMouseIcon)

#define Idbjvideo_put_MouseIcon(This,pMouseIcon)	\
    (This)->lpVtbl -> put_MouseIcon(This,pMouseIcon)

#define Idbjvideo_get_MouseIcon(This,ppMouseIcon)	\
    (This)->lpVtbl -> get_MouseIcon(This,ppMouseIcon)

#define Idbjvideo_putref_Picture(This,pPicture)	\
    (This)->lpVtbl -> putref_Picture(This,pPicture)

#define Idbjvideo_put_Picture(This,pPicture)	\
    (This)->lpVtbl -> put_Picture(This,pPicture)

#define Idbjvideo_get_Picture(This,ppPicture)	\
    (This)->lpVtbl -> get_Picture(This,ppPicture)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propput] */ HRESULT STDMETHODCALLTYPE Idbjvideo_put_BorderStyle_Proxy( 
    Idbjvideo * This,
    /* [in] */ long style);


void __RPC_STUB Idbjvideo_put_BorderStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE Idbjvideo_get_BorderStyle_Proxy( 
    Idbjvideo * This,
    /* [retval][out] */ long *pstyle);


void __RPC_STUB Idbjvideo_get_BorderStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE Idbjvideo_put_BorderWidth_Proxy( 
    Idbjvideo * This,
    /* [in] */ long width);


void __RPC_STUB Idbjvideo_put_BorderWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE Idbjvideo_get_BorderWidth_Proxy( 
    Idbjvideo * This,
    /* [retval][out] */ long *width);


void __RPC_STUB Idbjvideo_get_BorderWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE Idbjvideo_get_Window_Proxy( 
    Idbjvideo * This,
    /* [retval][out] */ long *phwnd);


void __RPC_STUB Idbjvideo_get_Window_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE Idbjvideo_put_MousePointer_Proxy( 
    Idbjvideo * This,
    /* [in] */ long pointer);


void __RPC_STUB Idbjvideo_put_MousePointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE Idbjvideo_get_MousePointer_Proxy( 
    Idbjvideo * This,
    /* [retval][out] */ long *ppointer);


void __RPC_STUB Idbjvideo_get_MousePointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propputref] */ HRESULT STDMETHODCALLTYPE Idbjvideo_putref_MouseIcon_Proxy( 
    Idbjvideo * This,
    /* [in] */ IPictureDisp *pMouseIcon);


void __RPC_STUB Idbjvideo_putref_MouseIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE Idbjvideo_put_MouseIcon_Proxy( 
    Idbjvideo * This,
    /* [in] */ IPictureDisp *pMouseIcon);


void __RPC_STUB Idbjvideo_put_MouseIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE Idbjvideo_get_MouseIcon_Proxy( 
    Idbjvideo * This,
    /* [retval][out] */ IPictureDisp **ppMouseIcon);


void __RPC_STUB Idbjvideo_get_MouseIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propputref] */ HRESULT STDMETHODCALLTYPE Idbjvideo_putref_Picture_Proxy( 
    Idbjvideo * This,
    /* [in] */ IPictureDisp *pPicture);


void __RPC_STUB Idbjvideo_putref_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE Idbjvideo_put_Picture_Proxy( 
    Idbjvideo * This,
    /* [in] */ IPictureDisp *pPicture);


void __RPC_STUB Idbjvideo_put_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE Idbjvideo_get_Picture_Proxy( 
    Idbjvideo * This,
    /* [retval][out] */ IPictureDisp **ppPicture);


void __RPC_STUB Idbjvideo_get_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __Idbjvideo_INTERFACE_DEFINED__ */



#ifndef __VIDEOCONTROLLib_LIBRARY_DEFINED__
#define __VIDEOCONTROLLib_LIBRARY_DEFINED__

/* library VIDEOCONTROLLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_VIDEOCONTROLLib;

#ifndef ___IdbjvideoEvents_DISPINTERFACE_DEFINED__
#define ___IdbjvideoEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IdbjvideoEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IdbjvideoEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0A626935-4594-4DF2-9898-6BC739D6821D")
    _IdbjvideoEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IdbjvideoEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IdbjvideoEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IdbjvideoEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IdbjvideoEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IdbjvideoEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IdbjvideoEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IdbjvideoEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IdbjvideoEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IdbjvideoEventsVtbl;

    interface _IdbjvideoEvents
    {
        CONST_VTBL struct _IdbjvideoEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IdbjvideoEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IdbjvideoEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IdbjvideoEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IdbjvideoEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IdbjvideoEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IdbjvideoEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IdbjvideoEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IdbjvideoEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_dbjvideo;

#ifdef __cplusplus

class DECLSPEC_UUID("A3014D0A-95BE-4440-8D05-BEBC1117EBC6")
dbjvideo;
#endif
#endif /* __VIDEOCONTROLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


