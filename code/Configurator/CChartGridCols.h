// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CChartGridCols ��װ��

class CChartGridCols : public COleDispatchDriver
{
public:
	CChartGridCols(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CChartGridCols(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CChartGridCols(const CChartGridCols& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IChartGridCols ����
public:
	long get_Col()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Col(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_Widths(long Index)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, Index);
		return result;
	}
	void put_Widths(long Index, long newValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, Index, newValue);
	}

	// IChartGridCols ����
public:

};
