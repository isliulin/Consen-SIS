// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CMedianFunction ��װ��

class CMedianFunction : public COleDispatchDriver
{
public:
	CMedianFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CMedianFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMedianFunction(const CMedianFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IMedianFunction ����
public:
	BOOL get_IncludeNulls()
	{
		BOOL result;
		InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IncludeNulls(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x12d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IMedianFunction ����
public:

};
