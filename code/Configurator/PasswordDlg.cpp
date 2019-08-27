// PasswordDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Configurator.h"
#include "PasswordDlg.h"
#include "afxdialogex.h"


// CPasswordDlg �Ի���

IMPLEMENT_DYNAMIC(CPasswordDlg, CDialogEx)

CPasswordDlg::CPasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPasswordDlg::IDD, pParent)
{

}

CPasswordDlg::~CPasswordDlg()
{
}

void CPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_CURRENT, m_edtCurrent);
	DDX_Control(pDX, IDC_EDT_PASSWORD, m_edtPassword);
}


BEGIN_MESSAGE_MAP(CPasswordDlg, CDialogEx)
END_MESSAGE_MAP()


// CPasswordDlg ��Ϣ�������


BOOL CPasswordDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowContextHelpId( HIDR_PASSWORD );    // Help ID

	m_edtCurrent.SetWindowText( global::Security.GetName());

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CPasswordDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	CString strPassword;
	m_edtPassword.GetWindowText( strPassword );
	if( !global::Security.Login( strPassword ))
	{
        AfxMessageBox( IDS_INVALID_PASSWORD, MB_OK | MB_ICONERROR );
		return;
	}

	CDialogEx::OnOK();
}
