// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CCLVFunction ��װ��

class CCLVFunction : public COleDispatchDriver
{
public:
	CCLVFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCLVFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCLVFunction(const CCLVFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICLVFunction ����
public:
	BOOL get_Accumulate()
	{
		BOOL result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Accumulate(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT get_Volume()
	{
		VARIANT result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Volume(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}

	// ICLVFunction ����
public:

};
