// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CPyramidSeries ��װ��

class CPyramidSeries : public COleDispatchDriver
{
public:
	CPyramidSeries(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CPyramidSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPyramidSeries(const CPyramidSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IPyramidSeries ����
public:
	long get_SizePercent()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_SizePercent(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IPyramidSeries ����
public:

};
