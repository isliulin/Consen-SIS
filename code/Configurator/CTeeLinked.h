// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "D:\\Registered Active X\\TeeChart8.ocx" no_namespace
// CTeeLinked ��װ��

class CTeeLinked : public COleDispatchDriver
{
public:
	CTeeLinked(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CTeeLinked(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTeeLinked(const CTeeLinked& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ITeeLinked ����
public:
	void put_Chart(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x2c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void put_ChartLink(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// ITeeLinked ����
public:

};
