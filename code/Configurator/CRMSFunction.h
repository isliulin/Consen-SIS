// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CRMSFunction ��װ��

class CRMSFunction : public COleDispatchDriver
{
public:
	CRMSFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CRMSFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRMSFunction(const CRMSFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IRMSFunction ����
public:
	BOOL get_Complete()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Complete(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IRMSFunction ����
public:

};
