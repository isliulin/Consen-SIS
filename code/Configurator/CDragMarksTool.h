// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CDragMarksTool ��װ��

class CDragMarksTool : public COleDispatchDriver
{
public:
	CDragMarksTool(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CDragMarksTool(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDragMarksTool(const CDragMarksTool& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IDragMarksTool ����
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

	// IDragMarksTool ����
public:

};
