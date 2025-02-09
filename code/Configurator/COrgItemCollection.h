// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// COrgItemCollection 包装类

class COrgItemCollection : public COleDispatchDriver
{
public:
	COrgItemCollection(){} // 调用 COleDispatchDriver 默认构造函数
	COrgItemCollection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	COrgItemCollection(const COrgItemCollection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IOrgItemCollection 方法
public:
	LPDISPATCH get_Items(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}

	// IOrgItemCollection 属性
public:

};
