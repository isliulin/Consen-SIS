// TuneFraForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Configurator.h"
#include "TuneFraForm.h"


// CTuneFraForm

IMPLEMENT_DYNCREATE(CTuneFraForm, CFormView)

CTuneFraForm::CTuneFraForm()
	: CFormView(CTuneFraForm::IDD)
{

}

CTuneFraForm::~CTuneFraForm()
{
}

void CTuneFraForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTuneFraForm, CFormView)
	ON_EN_CHANGE(IDC_EDIT1, &CTuneFraForm::OnEnChangeEdit1)
	ON_WM_CHAR()
END_MESSAGE_MAP()


// CTuneFraForm ���

#ifdef _DEBUG
void CTuneFraForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CTuneFraForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CTuneFraForm ��Ϣ�������


void CTuneFraForm::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTuneFraForm::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CFormView::OnChar(nChar, nRepCnt, nFlags);
}
