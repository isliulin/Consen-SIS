// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CExpMovAvgFunction 包装类

class CExpMovAvgFunction : public COleDispatchDriver
{
public:
	CExpMovAvgFunction(){} // 调用 COleDispatchDriver 默认构造函数
	CExpMovAvgFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CExpMovAvgFunction(const CExpMovAvgFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IExpMovAvgFunction 方法
public:
	BOOL get_IgnoreNulls()
	{
		BOOL result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IgnoreNulls(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IExpMovAvgFunction 属性
public:

};
