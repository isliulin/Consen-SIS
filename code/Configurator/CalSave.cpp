// CalSave.cpp : 实现文件
//

#include "stdafx.h"
#include "Configurator.h"
#include "CalSave.h"
#include "afxdialogex.h"

#include "CalSheet.h"
#include "MainFrm.h"
#include "CalibrateBase.h"


// CCalSave 对话框

IMPLEMENT_DYNAMIC(CCalSave, CPropertyPage)

CCalSave::CCalSave()
	: CPropertyPage(CCalSave::IDD)
	, m_pCalibrate( NULL )
{
	
}

CCalSave::~CCalSave()
{
	m_boldFont.DeleteObject();
    m_norFont.DeleteObject();
	m_imgPassing.ReleaseGDIPlus();
	m_imgPass.ReleaseGDIPlus();
}

void CCalSave::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCalSave, CPropertyPage)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CCalSave 消息处理程序


BOOL CCalSave::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	/// String 
	// Use
	CString str;
	str.LoadString( IDS_SAVE_SETTINGS );
	if( GetDlgItem( IDC_STC_USE )->GetSafeHwnd())
	{
		GetDlgItem( IDC_STC_USE )->SetWindowText( str );
	}

	/// Font
	// Create Font
	CClientDC dc(this);
	LOGFONT boldlf;
	memset( &boldlf, 0, sizeof(LOGFONT));
	boldlf.lfHeight = ::MulDiv( 11,-dc.GetDeviceCaps( LOGPIXELSY ), 72 );
	boldlf.lfWeight = 700;     // bold                
	::StrCpyNW( boldlf.lfFaceName, L"Times New Roman", 32 );
    m_boldFont.CreateFontIndirectW( &boldlf );

	LOGFONT norlf;
	memset( &norlf, 0, sizeof(LOGFONT));
	norlf.lfHeight = ::MulDiv( 11,-dc.GetDeviceCaps( LOGPIXELSY ), 72 );
	norlf.lfWeight = 400;     // normal                
	::StrCpyNW( norlf.lfFaceName, L"Times New Roman", 32 );
    m_norFont.CreateFontIndirectW( &norlf );

	// Set Normal Font
	CWnd* pWnd = GetTopWindow();
	while( pWnd->GetSafeHwnd())
	{
		pWnd->SetFont( &m_norFont );
		pWnd = pWnd->GetNextWindow();
	}

	// Set Bold Font
	// Title
	if( GetDlgItem( IDC_CAL_TITLE )->GetSafeHwnd())
	{
		GetDlgItem( IDC_CAL_TITLE )->SetFont( &m_boldFont ); 
	}

	// Save 
	if( GetDlgItem( IDC_CAL_SAVE )->GetSafeHwnd())
	{
		GetDlgItem( IDC_CAL_SAVE )->SetFont( &m_boldFont ); 
	}

	/// Image
	if( S_OK == m_imgPassing.Load( L"res\\Calibrate\\Cal_Passing.bmp" ))
	{
	    m_imgPassing.SetTransparentColor( RGB(255,0,255));
	}

	if( S_OK == m_imgPass.Load( L"res\\Calibrate\\Cal_Pass.bmp" ))
	{
	    m_imgPass.SetTransparentColor( RGB(255,0,255));
	}

	CCalSheet* pCalSheet = (CCalSheet*)GetParent();
	if( pCalSheet->GetSafeHwnd())
	{
		m_pCalibrate = (CDSC100Calibrate*)pCalSheet->GetCalibrate();
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CCalSave::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CPropertyPage::OnPaint()

	// Check if bitmaps are currently loaded.
	if( m_imgPassing.IsNull() ||
		m_imgPassing.IsNull())
	{
		return;
	}

	// Introduction: Passed
	CRect rect;
	if( GetDlgItem( IDC_CAL_INTRO )->GetSafeHwnd())
	{
		GetDlgItem( IDC_CAL_INTRO )->GetWindowRect( rect );  // screen coordinates 
		ScreenToClient( &rect );
	}
	m_imgPass.Draw( dc.GetSafeHdc(), 10, rect.top );

	// Minimum: Passed
	if( GetDlgItem( IDC_CAL_MIN )->GetSafeHwnd())
	{
		GetDlgItem( IDC_CAL_MIN )->GetWindowRect( &rect ); 
		ScreenToClient( &rect );
	}
	m_imgPass.Draw( dc.GetSafeHdc(), 10, rect.top );

	// Maximum: Passed
	if( GetDlgItem( IDC_CAL_MAX )->GetSafeHwnd())
	{
		GetDlgItem( IDC_CAL_MAX )->GetWindowRect( &rect ); 
		ScreenToClient( &rect );
	}
	m_imgPass.Draw( dc.GetSafeHdc(), 10, rect.top );

	// Verification: Passed
	if( GetDlgItem( IDC_CAL_VER )->GetSafeHwnd())
	{
		GetDlgItem( IDC_CAL_VER )->GetWindowRect( &rect ); 
		ScreenToClient( &rect );
	}
	m_imgPass.Draw( dc.GetSafeHdc(), 10, rect.top );

	// Save: Passing
	if( GetDlgItem( IDC_CAL_SAVE )->GetSafeHwnd())
	{
		GetDlgItem( IDC_CAL_SAVE )->GetWindowRect( &rect ); 
		ScreenToClient( &rect );
	}
	m_imgPassing.Draw( dc.GetSafeHdc(), 10, rect.top );
}


BOOL CCalSave::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	CPropertySheet* pParent = (CPropertySheet*)GetParent();
	if( pParent->GetSafeHwnd())
	{
		pParent->SetWizardButtons( PSWIZB_FINISH );

		// Save button
		CString str;
		str.LoadString( IDS_CALBTN_SAVE );
		pParent->SetFinishText( str );
	}

	return CPropertyPage::OnSetActive();
}

BOOL CCalSave::OnWizardFinish()
{
	// TODO: 在此添加专用代码和/或调用基类
	if( m_pCalibrate != NULL )
	{
		// Stop Monitor if not monitor before calibrate
		if( !m_pCalibrate->IsOrigMonitoring())
		{
			CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
			if( pFrame->GetSafeHwnd())
			{
				::Sleep(500);
				pFrame->DoStopMonitor();
			}
		}

		m_pCalibrate->SetAliasFlag( false, false, false, false, true,
			                        true, false, false, false );
		m_pCalibrate->SendCalibrationFlags( true );
	}

	return CPropertyPage::OnWizardFinish();
}
