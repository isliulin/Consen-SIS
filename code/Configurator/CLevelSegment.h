// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CLevelSegment ��װ��

class CLevelSegment : public COleDispatchDriver
{
public:
	CLevelSegment(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CLevelSegment(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CLevelSegment(const CLevelSegment& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ILevelSegment ����
public:
	long get_NumPoints()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Points(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Index);
		return result;
	}

	// ILevelSegment ����
public:

};
