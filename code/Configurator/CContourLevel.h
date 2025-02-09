// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CContourLevel 包装类

class CContourLevel : public COleDispatchDriver
{
public:
	CContourLevel(){} // 调用 COleDispatchDriver 默认构造函数
	CContourLevel(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CContourLevel(const CContourLevel& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IContourLevel 方法
public:
	unsigned long get_Color()
	{
		unsigned long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_Color(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_UpToValue()
	{
		double result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_UpToValue(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_Segments(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}
	long get_NumSegments()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Pen()
	{
		LPDISPATCH result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void ClearSegments()
	{
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL Clicked(long XCoord, long YCoord, long * SegmentIndex, long * PointIndex)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, XCoord, YCoord, SegmentIndex, PointIndex);
		return result;
	}
	BOOL ClickedSegment(long XCoord, long YCoord, long SegmentIndex, long * PointIndex)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0xce, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, XCoord, YCoord, SegmentIndex, PointIndex);
		return result;
	}
	BOOL get_DefaultPen()
	{
		BOOL result;
		InvokeHelper(0xcf, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	// IContourLevel 属性
public:

};
