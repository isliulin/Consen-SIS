// MyStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Configurator.h"
#include "MyStatic.h"


// CMyStatic

IMPLEMENT_DYNAMIC(CMyStatic, CStatic)

CMyStatic::CMyStatic()
{
	//m_BKBrush.CreateSolidBrush( GetSysColor( COLOR_BTNFACE ));
}

CMyStatic::~CMyStatic()
{
}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



// CMyStatic ��Ϣ�������

HBRUSH CMyStatic::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  �ڴ˸��� DC ���κ�����

	pDC->SetTextColor( RGB(255,255,255));       // Text
	pDC->SetBkColor( RGB(0,0,255 ));            // Text BKColor
	return (HBRUSH)m_BKBrush.GetSafeHandle();

	/*
	COLORREF crText = pDC->GetTextColor();
	COLORREF crBK = pDC->GetBkColor();

	COLORREF crWndText = GetSysColor( COLOR_WINDOWTEXT );
	COLORREF crBtnText = GetSysColor( COLOR_BTNTEXT  );

	COLORREF crMenuBK = GetSysColor( COLOR_MENU );
	COLORREF crWndBK = GetSysColor( COLOR_WINDOW );
	COLORREF crToolBK = GetSysColor( COLOR_INFOBK );
	COLORREF crDlgBK = GetSysColor( COLOR_3DFACE );

	//return (HBRUSH)m_BKBrush.GetSafeHandle();*/

	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
	//return NULL;
}
