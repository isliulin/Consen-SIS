// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CChartGridEvents 包装类

class CChartGridEvents : public COleDispatchDriver
{
public:
	CChartGridEvents(){} // 调用 COleDispatchDriver 默认构造函数
	CChartGridEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CChartGridEvents(const CChartGridEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IChartGridEvents 方法
public:
	STDMETHOD(OnClick)()
	{
		HRESULT result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}

	// IChartGridEvents 属性
public:

};
