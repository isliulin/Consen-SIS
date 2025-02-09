// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CAxisGridPen 包装类

class CAxisGridPen : public COleDispatchDriver
{
public:
	CAxisGridPen(){} // 调用 COleDispatchDriver 默认构造函数
	CAxisGridPen(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAxisGridPen(const CAxisGridPen& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IAxisGridPen 方法
public:
	long get_DrawEvery()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_DrawEvery(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_ZPosition()
	{
		double result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_ZPosition(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IAxisGridPen 属性
public:

};
