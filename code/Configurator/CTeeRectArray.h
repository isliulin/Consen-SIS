// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CTeeRectArray ��װ��

class CTeeRectArray : public COleDispatchDriver
{
public:
	CTeeRectArray(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CTeeRectArray(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTeeRectArray(const CTeeRectArray& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ITeeRectArray ����
public:
	long get_Count()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}

	// ITeeRectArray ����
public:

};
