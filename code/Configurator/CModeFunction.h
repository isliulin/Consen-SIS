// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CModeFunction ��װ��

class CModeFunction : public COleDispatchDriver
{
public:
	CModeFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CModeFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CModeFunction(const CModeFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IModeFunction ����
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

	// IModeFunction ����
public:

};
