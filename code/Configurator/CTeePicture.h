// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "D:\\Registered Active X\\TeeChart8.ocx" no_namespace
// CTeePicture ��װ��

class CTeePicture : public COleDispatchDriver
{
public:
	CTeePicture(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CTeePicture(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTeePicture(const CTeePicture& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ITeePicture ����
public:
	LPDISPATCH get_Filters()
	{
		LPDISPATCH result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void LoadImage(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}
	void AssignImage(long ImageHandle)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ImageHandle);
	}
	void ClearImage()
	{
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL ShowFiltersEditor()
	{
		BOOL result;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long get_Handle()
	{
		long result;
		InvokeHelper(0xce, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void SaveToFile(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xcf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}

	// ITeePicture ����
public:

};
