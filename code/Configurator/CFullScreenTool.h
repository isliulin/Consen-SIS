// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CFullScreenTool ��װ��

class CFullScreenTool : public COleDispatchDriver
{
public:
	CFullScreenTool(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CFullScreenTool(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFullScreenTool(const CFullScreenTool& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IFullScreenTool ����
public:
	long get_ReleaseKey()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ReleaseKey(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IFullScreenTool ����
public:

};
