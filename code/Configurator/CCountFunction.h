// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CCountFunction ��װ��

class CCountFunction : public COleDispatchDriver
{
public:
	CCountFunction(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCountFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCountFunction(const CCountFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICountFunction ����
public:

	// ICountFunction ����
public:

};
