// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "D:\\Registered Active X\\TeeChart8.ocx" no_namespace
// CTeeCommanderEvents ��װ��

class CTeeCommanderEvents : public COleDispatchDriver
{
public:
	CTeeCommanderEvents(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CTeeCommanderEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTeeCommanderEvents(const CTeeCommanderEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ITeeCommanderEvents ����
public:
	void OnEditedChart()
	{
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// ITeeCommanderEvents ����
public:

};
