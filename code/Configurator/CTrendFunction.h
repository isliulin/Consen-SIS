// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CTrendFunction 包装类

class CTrendFunction : public COleDispatchDriver
{
public:
	CTrendFunction(){} // 调用 COleDispatchDriver 默认构造函数
	CTrendFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTrendFunction(const CTrendFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// ITrendFunction 方法
public:
	long CalculateTrend(double * m, double * b, long SourceSeriesIndex, long FirstIndex, long LastIndex)
	{
		long result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, m, b, SourceSeriesIndex, FirstIndex, LastIndex);
		return result;
	}

	// ITrendFunction 属性
public:

};
