// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CContrastFilter 包装类

class CContrastFilter : public COleDispatchDriver
{
public:
	CContrastFilter(){} // 调用 COleDispatchDriver 默认构造函数
	CContrastFilter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CContrastFilter(const CContrastFilter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IContrastFilter 方法
public:
	BOOL get_Percent()
	{
		BOOL result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Percent(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Amount()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Amount(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IContrastFilter 属性
public:

};
