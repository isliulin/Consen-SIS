// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "D:\\Registered Active X\\TeeChart8.ocx" no_namespace
// CTeeListBoxEvents ��װ��

class CTeeListBoxEvents : public COleDispatchDriver
{
public:
	CTeeListBoxEvents(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CTeeListBoxEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTeeListBoxEvents(const CTeeListBoxEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ITeeListBoxEvents ����
public:
	void OnDblClickSeries(long SeriesIndex)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SeriesIndex);
	}
	STDMETHOD(OnClick)()
	{
		HRESULT result;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	void OnChangeActive(long SeriesIndex)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SeriesIndex);
	}
	void OnMouseUp(long Button, long Shift, long X, long Y)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Button, Shift, X, Y);
	}
	void OnMouseDown(long Button, long Shift, long X, long Y)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Button, Shift, X, Y);
	}
	void OnMouseMove(long Shift, long X, long Y)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Shift, X, Y);
	}
	void OnChangeColor(long SeriesIndex)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xce, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SeriesIndex);
	}
	void OnChangeOrder(long SeriesIndex1, long SeriesIndex2)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xcf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SeriesIndex1, SeriesIndex2);
	}
	STDMETHOD(OnOtherItemsChange)()
	{
		HRESULT result;
		InvokeHelper(0xd0, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(OnRefresh)()
	{
		HRESULT result;
		InvokeHelper(0xd1, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	void OnRemovedSeries(long SeriesIndex)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SeriesIndex);
	}

	// ITeeListBoxEvents ����
public:

};
