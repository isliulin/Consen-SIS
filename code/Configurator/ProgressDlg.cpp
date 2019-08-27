// ProgressDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Configurator.h"
#include "ProgressDlg.h"
#include "afxdialogex.h"

// Added by wangdong
#include "ModbusThread.h"     // extern ModbusThread    

//=======================================================
/// Globals
extern std::auto_ptr<modbus::CModbusThread> ModbusThread;

//=======================================================
// CProgressDlg �Ի���

IMPLEMENT_DYNAMIC(CProgressDlg, CDialogEx)

CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProgressDlg::IDD, pParent)
{

}

CProgressDlg::~CProgressDlg()
{
}

void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STC_MSG, m_ctlMessage);
	DDX_Control(pDX, IDC_PROGRESS_COMM, m_ctlProgress);
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialogEx)
END_MESSAGE_MAP()


// CProgressDlg ��Ϣ�������

// ================================================
// Function name: OnInitDialog
// Description  : Initialize dialog controls
// Return type  : void
// Parameters   : 
// Author       : WangDong 2011.03.09 13:00:00
// =================================================
BOOL CProgressDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_ctlMessage.SetWindowText( L"" );

	// Range: 0 - 100
	m_ctlProgress.SetRange( 0, 100 );
	m_ctlProgress.SetPos( 0 );

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CProgressDlg::OnCancel()
{
	ModbusThread->Close();
	ModbusThread->ClearMessages();
	ModbusThread->ResetThreadFlags();

	DestroyWindow();  // Modaless
}
