// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CCCIFunction ��װ��

class CCCIFunction : public COleDispatchDriver
{
public:
	CCCIFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCCIFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCCIFunction(const CCCIFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICCIFunction ����
public:
	double get_Constant()
	{
		double result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Constant(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// ICCIFunction ����
public:

};
