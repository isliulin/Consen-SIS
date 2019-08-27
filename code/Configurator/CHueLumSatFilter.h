// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CHueLumSatFilter ��װ��

class CHueLumSatFilter : public COleDispatchDriver
{
public:
	CHueLumSatFilter(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CHueLumSatFilter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CHueLumSatFilter(const CHueLumSatFilter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IHueLumSatFilter ����
public:
	long get_Hue()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Hue(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Luminance()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Luminance(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Saturation()
	{
		long result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Saturation(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xcb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IHueLumSatFilter ����
public:

};
