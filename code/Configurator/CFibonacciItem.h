// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CFibonacciItem ��װ��

class CFibonacciItem : public COleDispatchDriver
{
public:
	CFibonacciItem(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CFibonacciItem(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFibonacciItem(const CFibonacciItem& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IFibonacciItem ����
public:
	LPDISPATCH get_Pen()
	{
		LPDISPATCH result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	double get_Value()
	{
		double result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Value(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IFibonacciItem ����
public:

};
