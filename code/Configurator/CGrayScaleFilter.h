// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CGrayScaleFilter ��װ��

class CGrayScaleFilter : public COleDispatchDriver
{
public:
	CGrayScaleFilter(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CGrayScaleFilter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CGrayScaleFilter(const CGrayScaleFilter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IGrayScaleFilter ����
public:
	long get_Method()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Method(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IGrayScaleFilter ����
public:

};
