// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CExtraLegendTool ��װ��

class CExtraLegendTool : public COleDispatchDriver
{
public:
	CExtraLegendTool(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CExtraLegendTool(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CExtraLegendTool(const CExtraLegendTool& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IExtraLegendTool ����
public:
	VARIANT get_Series()
	{
		VARIANT result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Series(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	LPDISPATCH get_Legend()
	{
		LPDISPATCH result;
		InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// IExtraLegendTool ����
public:

};
