// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "D:\\ActiveX\\TeeChart8.oc" no_namespace
// CClipSeriesTool ��װ��

class CClipSeriesTool : public COleDispatchDriver
{
public:
	CClipSeriesTool(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CClipSeriesTool(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CClipSeriesTool(const CClipSeriesTool& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IClipSeriesTool ����
public:
	VARIANT get_Series()
	{
		VARIANT result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Series(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}

	// IClipSeriesTool ����
public:

};
