// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CTransposeSeriesTool ��װ��

class CTransposeSeriesTool : public COleDispatchDriver
{
public:
	CTransposeSeriesTool(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CTransposeSeriesTool(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTransposeSeriesTool(const CTransposeSeriesTool& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ITransposeSeriesTool ����
public:
	void Transpose()
	{
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// ITransposeSeriesTool ����
public:

};
