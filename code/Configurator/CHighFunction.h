// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CHighFunction ��װ��

class CHighFunction : public COleDispatchDriver
{
public:
	CHighFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CHighFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CHighFunction(const CHighFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IHighFunction ����
public:

	// IHighFunction ����
public:

};
