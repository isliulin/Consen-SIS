// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CSmoothingFunction ��װ��

class CSmoothingFunction : public COleDispatchDriver
{
public:
	CSmoothingFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CSmoothingFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSmoothingFunction(const CSmoothingFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ISmoothingFunction ����
public:
	BOOL get_Interpolate()
	{
		BOOL result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Interpolate(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Factor()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Factor(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// ISmoothingFunction ����
public:

};
