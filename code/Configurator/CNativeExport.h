// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CNativeExport ��װ��

class CNativeExport : public COleDispatchDriver
{
public:
	CNativeExport(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CNativeExport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CNativeExport(const CNativeExport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// INativeExport ����
public:
	void SaveToFile(LPCTSTR FileName, BOOL IncludeData)
	{
		static BYTE parms[] = VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName, IncludeData);
	}
	VARIANT SaveToStream(BOOL IncludeData)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, IncludeData);
		return result;
	}
	VARIANT SaveToBase64Stream(BOOL IncludeData)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, IncludeData);
		return result;
	}

	// INativeExport ����
public:

};
