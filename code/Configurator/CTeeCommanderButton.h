// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "D:\\Registered Active X\\TeeChart8.ocx" no_namespace
// CTeeCommanderButton ��װ��

class CTeeCommanderButton : public COleDispatchDriver
{
public:
	CTeeCommanderButton(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CTeeCommanderButton(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTeeCommanderButton(const CTeeCommanderButton& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ITeeCommanderButton ����
public:
	void Hide()
	{
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// ITeeCommanderButton ����
public:

};
