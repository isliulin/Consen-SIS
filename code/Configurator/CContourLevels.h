// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CContourLevels ��װ��

class CContourLevels : public COleDispatchDriver
{
public:
	CContourLevels(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CContourLevels(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CContourLevels(const CContourLevels& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IContourLevels ����
public:
	LPDISPATCH get_Items(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}
	long Clicked(long XCoord, long YCoord, long * SegmentIndex, long * PointIndex)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, XCoord, YCoord, SegmentIndex, PointIndex);
		return result;
	}
	long AddLevel(double LevelValue, unsigned long Color)
	{
		long result;
		static BYTE parms[] = VTS_R8 VTS_UI4 ;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_I4, (void*)&result, parms, LevelValue, Color);
		return result;
	}

	// IContourLevels ����
public:

};
