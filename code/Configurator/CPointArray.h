// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CPointArray ��װ��

class CPointArray : public COleDispatchDriver
{
public:
	CPointArray(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CPointArray(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPointArray(const CPointArray& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IPointArray ����
public:
	long get_Count()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}

	// IPointArray ����
public:

};
