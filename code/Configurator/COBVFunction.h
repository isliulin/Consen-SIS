// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// COBVFunction ��װ��

class COBVFunction : public COleDispatchDriver
{
public:
	COBVFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	COBVFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	COBVFunction(const COBVFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IOBVFunction ����
public:
	VARIANT get_Volume()
	{
		VARIANT result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Volume(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}

	// IOBVFunction ����
public:

};
