// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CReverseFilter ��װ��

class CReverseFilter : public COleDispatchDriver
{
public:
	CReverseFilter(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CReverseFilter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CReverseFilter(const CReverseFilter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IReverseFilter ����
public:

	// IReverseFilter ����
public:

};
