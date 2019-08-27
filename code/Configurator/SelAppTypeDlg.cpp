// SelAppTypedLG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Configurator.h"
#include "SelAppTypeDlg.h"
#include "afxdialogex.h"


// CSelAppTypeDlg �Ի���

IMPLEMENT_DYNAMIC(CSelAppTypeDlg, CDialogEx)

CSelAppTypeDlg::CSelAppTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelAppTypeDlg::IDD, pParent),
	  m_nIndex( -1 )
{
    m_pImageList = new CImageList();
	ASSERT( m_pImageList != NULL );
}

CSelAppTypeDlg::~CSelAppTypeDlg()
{
	SAFE_DELETE( m_pImageList );
}

void CSelAppTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_APPTYPE, m_ListCtrl);
}


BEGIN_MESSAGE_MAP(CSelAppTypeDlg, CDialogEx)
END_MESSAGE_MAP()


// CSelAppTypeDlg ��Ϣ�������

// ====================================================================
// Function name: OnInitDialog
// Description  : 
// Return type  : 
// Parameters   : 
// Author       : WangDong 2011.11.02 16:24:00
// =====================================================================
BOOL CSelAppTypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if( m_pImageList && (m_pImageList->Create( 32, 32, ILC_COLOR24 | ILC_MASK, 2, 2 )))
	{
		m_pImageList->Add( theApp.LoadIconW( IDI_GEN ));
		m_pImageList->Add( theApp.LoadIconW( IDI_MECH ));

		m_ListCtrl.SetImageList( m_pImageList, LVSIL_NORMAL );
		ASSERT(m_ListCtrl.GetImageList(LVSIL_NORMAL) == m_pImageList);
	
		m_ListCtrl.InsertItem( 0, L"Generator", 0 );
		m_ListCtrl.InsertItem( 1, L"Mechanical Drive", 1 );
		
		// Default: Generator
		if( 1  == theApp.GetAppType())
		{
		    m_ListCtrl.SetItemState( 0, LVIS_SELECTED, LVIS_SELECTED );
		}
		else
		{
			m_ListCtrl.SetItemState( 1, LVIS_SELECTED, LVIS_SELECTED );
		}

		m_nIndex = m_ListCtrl.GetNextItem( -1, LVIS_SELECTED );
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

// ====================================================================
// Function name: OnOK
// Description  : 
// Return type  : 
// Parameters   : 
// Author       : WangDong 2011.11.03 13:54:00
// =====================================================================
void CSelAppTypeDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	// Get Selected Item 
	m_nIndex = m_ListCtrl.GetNextItem( -1, LVIS_SELECTED );

	CDialogEx::OnOK();
}
