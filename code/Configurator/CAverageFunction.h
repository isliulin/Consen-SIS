// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CAverageFunction ��װ��

class CAverageFunction : public COleDispatchDriver
{
public:
	CAverageFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CAverageFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAverageFunction(const CAverageFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IAverageFunction ����
public:
	BOOL get_IncludeNulls()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IncludeNulls(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IAverageFunction ����
public:

};
