// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CCustomSeriesList ��װ��

class CCustomSeriesList : public COleDispatchDriver
{
public:
	CCustomSeriesList(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCustomSeriesList(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCustomSeriesList(const CCustomSeriesList& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICustomSeriesList ����
public:
	void ClearValues()
	{
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long First()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Last()
	{
		long result;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Items(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xcc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}

	// ICustomSeriesList ����
public:

};
