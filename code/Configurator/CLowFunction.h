// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CLowFunction ��װ��

class CLowFunction : public COleDispatchDriver
{
public:
	CLowFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CLowFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CLowFunction(const CLowFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ILowFunction ����
public:

	// ILowFunction ����
public:

};
