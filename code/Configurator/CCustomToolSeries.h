// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CCustomToolSeries ��װ��

class CCustomToolSeries : public COleDispatchDriver
{
public:
	CCustomToolSeries(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCustomToolSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCustomToolSeries(const CCustomToolSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICustomToolSeries ����
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

	// ICustomToolSeries ����
public:

};
