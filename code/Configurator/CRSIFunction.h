// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CRSIFunction ��װ��

class CRSIFunction : public COleDispatchDriver
{
public:
	CRSIFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CRSIFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRSIFunction(const CRSIFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IRSIFunction ����
public:
	long get_Style()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Style(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IRSIFunction ����
public:

};
