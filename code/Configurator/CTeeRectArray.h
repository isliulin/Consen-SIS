// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CTeeRectArray 包装类

class CTeeRectArray : public COleDispatchDriver
{
public:
	CTeeRectArray(){} // 调用 COleDispatchDriver 默认构造函数
	CTeeRectArray(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTeeRectArray(const CTeeRectArray& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// ITeeRectArray 方法
public:
	long get_Count()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}

	// ITeeRectArray 属性
public:

};
