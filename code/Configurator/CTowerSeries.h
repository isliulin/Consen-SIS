// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CTowerSeries 包装类

class CTowerSeries : public COleDispatchDriver
{
public:
	CTowerSeries(){} // 调用 COleDispatchDriver 默认构造函数
	CTowerSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTowerSeries(const CTowerSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// ITowerSeries 方法
public:
	long AddXYZ(double AX, double AY, double AZ, LPCTSTR AXLabel, unsigned long Value)
	{
		long result;
		static BYTE parms[] = VTS_R8 VTS_R8 VTS_R8 VTS_BSTR VTS_UI4 ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AX, AY, AZ, AXLabel, Value);
		return result;
	}
	double MaxZValue()
	{
		double result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
		return result;
	}
	double MinZValue()
	{
		double result;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
		return result;
	}
	long get_TimesZOrder()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_TimesZOrder(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_ZValues()
	{
		LPDISPATCH result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	double get_ZValue(long Index)
	{
		double result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, parms, Index);
		return result;
	}
	void put_ZValue(long Index, double newValue)
	{
		static BYTE parms[] = VTS_I4 VTS_R8 ;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, Index, newValue);
	}
	LPDISPATCH get_Brush()
	{
		LPDISPATCH result;
		InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Pen()
	{
		LPDISPATCH result;
		InvokeHelper(0x86, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void AddArrayXYZ(VARIANT& XArray, VARIANT& YArray, VARIANT& ZArray)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x87, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &XArray, &YArray, &ZArray);
	}
	void AddArrayGrid(long NumX, long NumZ, VARIANT& XZArray)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_VARIANT ;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, NumX, NumZ, &XZArray);
	}
	long CalcZPos(long ValueIndex)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ValueIndex);
		return result;
	}
	long AddPalette(double Value, unsigned long Color)
	{
		long result;
		static BYTE parms[] = VTS_R8 VTS_UI4 ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Value, Color);
		return result;
	}
	unsigned long get_StartColor()
	{
		unsigned long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_StartColor(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	unsigned long get_EndColor()
	{
		unsigned long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_EndColor(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_PaletteSteps()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_PaletteSteps(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_UsePalette()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UsePalette(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_UseColorRange()
	{
		BOOL result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UseColorRange(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void ClearPalette()
	{
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void CreateDefaultPalette(long NumSteps)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, NULL, parms, NumSteps);
	}
	unsigned long GetSurfacePaletteColor(double Y)
	{
		unsigned long result;
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_UI4, (void*)&result, parms, Y);
		return result;
	}
	unsigned long get_MidColor()
	{
		unsigned long result;
		InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_MidColor(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x21, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void CreateRangePalette()
	{
		InvokeHelper(0x22, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_PaletteStyle()
	{
		long result;
		InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_PaletteStyle(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x23, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_UsePaletteMin()
	{
		BOOL result;
		InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UsePaletteMin(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x12d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_PaletteMin()
	{
		double result;
		InvokeHelper(0x12e, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_PaletteMin(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x12e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_PaletteStep()
	{
		double result;
		InvokeHelper(0x12f, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_PaletteStep(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x12f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void InvertPalette()
	{
		InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void AddCustomPalette(VARIANT& colorArray)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x131, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &colorArray);
	}
	long get_NumXValues()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_NumXValues(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_NumZValues()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_NumZValues(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double GetXZValue(long X, long Z)
	{
		double result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_R8, (void*)&result, parms, X, Z);
		return result;
	}
	BOOL get_IrregularGrid()
	{
		BOOL result;
		InvokeHelper(0x139, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IrregularGrid(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x139, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void SmoothGrid3D()
	{
		InvokeHelper(0x191, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL get_ReuseGridIndex()
	{
		BOOL result;
		InvokeHelper(0x192, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_ReuseGridIndex(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x192, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void FillGridIndex(long StartIndex)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x193, DISPATCH_METHOD, VT_EMPTY, NULL, parms, StartIndex);
	}
	long Clicked(long X, long Y)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x1f5, DISPATCH_METHOD, VT_I4, (void*)&result, parms, X, Y);
		return result;
	}
	BOOL get_Dark3D()
	{
		BOOL result;
		InvokeHelper(0x1fa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Dark3D(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1fa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_PercentDepth()
	{
		long result;
		InvokeHelper(0x1fb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_PercentDepth(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1fb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_Origin()
	{
		double result;
		InvokeHelper(0x1fc, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Origin(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x1fc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_TowerStyle()
	{
		long result;
		InvokeHelper(0x1fd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_TowerStyle(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1fd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Transparency()
	{
		long result;
		InvokeHelper(0x1fe, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Transparency(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1fe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_PercentWidth()
	{
		long result;
		InvokeHelper(0x1ff, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_PercentWidth(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1ff, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_UseOrigin()
	{
		BOOL result;
		InvokeHelper(0x200, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UseOrigin(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x200, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double MinXValueTower()
	{
		double result;
		InvokeHelper(0x1f6, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
		return result;
	}
	double MaxXValueTower()
	{
		double result;
		InvokeHelper(0x1f7, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
		return result;
	}
	double MinZValueTower()
	{
		double result;
		InvokeHelper(0x1f8, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
		return result;
	}
	double MaxZValueTower()
	{
		double result;
		InvokeHelper(0x1f9, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
		return result;
	}

	// ITowerSeries 属性
public:

};
