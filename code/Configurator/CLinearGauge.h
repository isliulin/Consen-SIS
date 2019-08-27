// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CLinearGauge ��װ��

class CLinearGauge : public COleDispatchDriver
{
public:
	CLinearGauge(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CLinearGauge(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CLinearGauge(const CLinearGauge& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ILinearGauge ����
public:
	LPDISPATCH get_Face()
	{
		LPDISPATCH result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Frame()
	{
		LPDISPATCH result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	double get_Value()
	{
		double result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Value(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xcb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_GreenLine()
	{
		LPDISPATCH result;
		InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL get_Horizontal()
	{
		BOOL result;
		InvokeHelper(0x12f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Horizontal(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x12f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_Maximum()
	{
		double result;
		InvokeHelper(0x130, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Maximum(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x130, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_Minimum()
	{
		double result;
		InvokeHelper(0x131, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Minimum(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x131, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_MinorTickDistance()
	{
		long result;
		InvokeHelper(0x132, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MinorTickDistance(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x132, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_MinorTicks()
	{
		LPDISPATCH result;
		InvokeHelper(0x133, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_RedLine()
	{
		LPDISPATCH result;
		InvokeHelper(0x134, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Ticks()
	{
		LPDISPATCH result;
		InvokeHelper(0x135, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_MaxValueIndicator()
	{
		LPDISPATCH result;
		InvokeHelper(0x191, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL get_UseValueColorPalette()
	{
		BOOL result;
		InvokeHelper(0x192, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UseValueColorPalette(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x192, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_ValueArea()
	{
		LPDISPATCH result;
		InvokeHelper(0x193, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// ILinearGauge ����
public:

};
