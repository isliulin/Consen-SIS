// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CHighLowLineSeries ��װ��

class CHighLowLineSeries : public COleDispatchDriver
{
public:
	CHighLowLineSeries(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CHighLowLineSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CHighLowLineSeries(const CHighLowLineSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IHighLowLineSeries ����
public:
	long AddHighLow(double AX, double AHigh, double ALow, LPCTSTR AXLabel, unsigned long AColor)
	{
		long result;
		static BYTE parms[] = VTS_R8 VTS_R8 VTS_R8 VTS_BSTR VTS_UI4 ;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AX, AHigh, ALow, AXLabel, AColor);
		return result;
	}
	LPDISPATCH get_HighValues()
	{
		LPDISPATCH result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_LowValues()
	{
		LPDISPATCH result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	double MaxYValue()
	{
		double result;
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
		return result;
	}
	double MinYValue()
	{
		double result;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_HighPointer()
	{
		LPDISPATCH result;
		InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_LowPointer()
	{
		LPDISPATCH result;
		InvokeHelper(0x12e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long Clicked(long X, long Y)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x12f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, X, Y);
		return result;
	}

	// IHighLowLineSeries ����
public:

};
