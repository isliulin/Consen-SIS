// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CLegendItem ��װ��

class CLegendItem : public COleDispatchDriver
{
public:
	CLegendItem(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CLegendItem(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CLegendItem(const CLegendItem& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ILegendItem ����
public:
	TeeRect get_SymbolRect()
	{
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_EMPTY, NULL, NULL);
	}
	void put_SymbolRect(TeeRect newValue)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Align()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_Left()
	{
		long result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString get_Text()
	{
		CString result;
		InvokeHelper(0xcc, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Text(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xcc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Top()
	{
		long result;
		InvokeHelper(0xcd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	// ILegendItem ����
public:

};
