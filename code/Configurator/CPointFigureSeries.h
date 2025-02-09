// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CPointFigureSeries 包装类

class CPointFigureSeries : public COleDispatchDriver
{
public:
	CPointFigureSeries(){} // 调用 COleDispatchDriver 默认构造函数
	CPointFigureSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPointFigureSeries(const CPointFigureSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IPointFigureSeries 方法
public:
	LPDISPATCH get_CloseValues()
	{
		LPDISPATCH result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_DateValues()
	{
		LPDISPATCH result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_HighValues()
	{
		LPDISPATCH result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_LowValues()
	{
		LPDISPATCH result;
		InvokeHelper(0xcc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_OpenValues()
	{
		LPDISPATCH result;
		InvokeHelper(0xcd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long AddOHLC(double DateValue, double OpenValue, double HighValue, double LowValue, double CloseValue)
	{
		long result;
		static BYTE parms[] = VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_R8 ;
		InvokeHelper(0xce, DISPATCH_METHOD, VT_I4, (void*)&result, parms, DateValue, OpenValue, HighValue, LowValue, CloseValue);
		return result;
	}
	double get_BoxSize()
	{
		double result;
		InvokeHelper(0xcf, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_BoxSize(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xcf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_ReversalAmount()
	{
		double result;
		InvokeHelper(0xd0, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_ReversalAmount(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xd0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_DownSymbol()
	{
		LPDISPATCH result;
		InvokeHelper(0xd1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_UpSymbol()
	{
		LPDISPATCH result;
		InvokeHelper(0xd2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long GetInversionColumn(long Index)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd3, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Index);
		return result;
	}

	// IPointFigureSeries 属性
public:

};
