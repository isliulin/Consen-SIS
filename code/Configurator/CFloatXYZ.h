// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CFloatXYZ ��װ��

class CFloatXYZ : public COleDispatchDriver
{
public:
	CFloatXYZ(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CFloatXYZ(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFloatXYZ(const CFloatXYZ& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IFloatXYZ ����
public:
	double get_X()
	{
		double result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_X(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_Y()
	{
		double result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Y(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_Z()
	{
		double result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Z(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xcb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IFloatXYZ ����
public:

};
