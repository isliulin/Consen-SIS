// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CXAMLExport ��װ��

class CXAMLExport : public COleDispatchDriver
{
public:
	CXAMLExport(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CXAMLExport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CXAMLExport(const CXAMLExport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IXAMLExport ����
public:
	long get_Width()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Width(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Height()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Height(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void SaveToFile(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}
	VARIANT SaveToStream()
	{
		VARIANT result;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	// IXAMLExport ����
public:

};
