// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CFibonacciLevels ��װ��

class CFibonacciLevels : public COleDispatchDriver
{
public:
	CFibonacciLevels(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CFibonacciLevels(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFibonacciLevels(const CFibonacciLevels& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IFibonacciLevels ����
public:
	LPDISPATCH get_Level(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}

	// IFibonacciLevels ����
public:

};
