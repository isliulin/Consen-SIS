// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CPerformanceFunction ��װ��

class CPerformanceFunction : public COleDispatchDriver
{
public:
	CPerformanceFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CPerformanceFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPerformanceFunction(const CPerformanceFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IPerformanceFunction ����
public:
	double Calculate(long SourceSeriesIndex, long FirstIndex, long LastIndex)
	{
		double result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_R8, (void*)&result, parms, SourceSeriesIndex, FirstIndex, LastIndex);
		return result;
	}

	// IPerformanceFunction ����
public:

};
