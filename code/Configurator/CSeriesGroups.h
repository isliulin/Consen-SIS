// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CSeriesGroups ��װ��

class CSeriesGroups : public COleDispatchDriver
{
public:
	CSeriesGroups(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CSeriesGroups(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSeriesGroups(const CSeriesGroups& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ISeriesGroups ����
public:
	LPDISPATCH get_Items(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void Delete(long Index)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Index);
	}
	long Contains(long SeriesIndex)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_I4, (void*)&result, parms, SeriesIndex);
		return result;
	}
	long FindByName(LPCTSTR Name, BOOL CaseSensitive)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL ;
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Name, CaseSensitive);
		return result;
	}

	// ISeriesGroups ����
public:

};
