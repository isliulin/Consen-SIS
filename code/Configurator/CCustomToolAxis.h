// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CCustomToolAxis ��װ��

class CCustomToolAxis : public COleDispatchDriver
{
public:
	CCustomToolAxis(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCustomToolAxis(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCustomToolAxis(const CCustomToolAxis& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICustomToolAxis ����
public:
	VARIANT get_Axis()
	{
		VARIANT result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Axis(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}

	// ICustomToolAxis ����
public:

};
