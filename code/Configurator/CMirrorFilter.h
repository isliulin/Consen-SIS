// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CMirrorFilter ��װ��

class CMirrorFilter : public COleDispatchDriver
{
public:
	CMirrorFilter(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CMirrorFilter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMirrorFilter(const CMirrorFilter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IMirrorFilter ����
public:
	long get_Direction()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Direction(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IMirrorFilter ����
public:

};
