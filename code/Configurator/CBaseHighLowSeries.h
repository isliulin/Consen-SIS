// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CBaseHighLowSeries 包装类

class CBaseHighLowSeries : public COleDispatchDriver
{
public:
	CBaseHighLowSeries(){} // 调用 COleDispatchDriver 默认构造函数
	CBaseHighLowSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CBaseHighLowSeries(const CBaseHighLowSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IBaseHighLowSeries 方法
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

	// IBaseHighLowSeries 属性
public:

};
