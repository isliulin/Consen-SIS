// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CTeePreviewPanelEvents ��װ��

class CTeePreviewPanelEvents : public COleDispatchDriver
{
public:
	CTeePreviewPanelEvents(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CTeePreviewPanelEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTeePreviewPanelEvents(const CTeePreviewPanelEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ITeePreviewPanelEvents ����
public:
	STDMETHOD(OnChangeMargins)(BOOL DisableProportional, long Left, long Top, long Right, long Bottom)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BOOL VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, DisableProportional, Left, Top, Right, Bottom);
		return result;
	}
	STDMETHOD(OnAfterDraw)()
	{
		HRESULT result;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}

	// ITeePreviewPanelEvents ����
public:

};
