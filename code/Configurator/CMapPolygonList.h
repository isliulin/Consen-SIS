// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CMapPolygonList ��װ��

class CMapPolygonList : public COleDispatchDriver
{
public:
	CMapPolygonList(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CMapPolygonList(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMapPolygonList(const CMapPolygonList& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IMapPolygonList ����
public:
	long Add()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Polygon(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	// IMapPolygonList ����
public:

};
