// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CSubsetTeeFunction ��װ��

class CSubsetTeeFunction : public COleDispatchDriver
{
public:
	CSubsetTeeFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CSubsetTeeFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSubsetTeeFunction(const CSubsetTeeFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ISubsetTeeFunction ����
public:
	double get_StartValue()
	{
		double result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_StartValue(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_EndValue()
	{
		double result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_EndValue(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// ISubsetTeeFunction ����
public:

};
