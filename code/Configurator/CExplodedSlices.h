// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CExplodedSlices ��װ��

class CExplodedSlices : public COleDispatchDriver
{
public:
	CExplodedSlices(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CExplodedSlices(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CExplodedSlices(const CExplodedSlices& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IExplodedSlices ����
public:
	long get_Value(long Index)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, Index);
		return result;
	}
	void put_Value(long Index, long newValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, Index, newValue);
	}

	// IExplodedSlices ����
public:

};
