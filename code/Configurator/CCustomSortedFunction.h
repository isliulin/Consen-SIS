// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CCustomSortedFunction ��װ��

class CCustomSortedFunction : public COleDispatchDriver
{
public:
	CCustomSortedFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCustomSortedFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCustomSortedFunction(const CCustomSortedFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICustomSortedFunction ����
public:
	BOOL get_IncludeNulls()
	{
		BOOL result;
		InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IncludeNulls(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x12d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// ICustomSortedFunction ����
public:

};
