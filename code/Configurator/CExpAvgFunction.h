// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CExpAvgFunction ��װ��

class CExpAvgFunction : public COleDispatchDriver
{
public:
	CExpAvgFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CExpAvgFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CExpAvgFunction(const CExpAvgFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IExpAvgFunction ����
public:
	double get_Weight()
	{
		double result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Weight(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IExpAvgFunction ����
public:

};
