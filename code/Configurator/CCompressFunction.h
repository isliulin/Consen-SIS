// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CCompressFunction ��װ��

class CCompressFunction : public COleDispatchDriver
{
public:
	CCompressFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCompressFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCompressFunction(const CCompressFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICompressFunction ����
public:
	long get_Compress()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Compress(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// ICompressFunction ����
public:

};
