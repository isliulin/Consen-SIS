// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "D:\\Registered Active X\\TeeChart8.ocx" no_namespace
// CTeePanelsList ��װ��

class CTeePanelsList : public COleDispatchDriver
{
public:
	CTeePanelsList(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CTeePanelsList(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTeePanelsList(const CTeePanelsList& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ITeePanelsList ����
public:
	void Delete(long Index)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Index);
	}
	void Clear()
	{
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	// ITeePanelsList ����
public:

};
