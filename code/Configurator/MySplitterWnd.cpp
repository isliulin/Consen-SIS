// MySplitterWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Configurator.h"            // Added by wangdong

#include "MySplitterWnd.h"


// CMySplitterWnd

CMySplitterWnd::CMySplitterWnd(void)
	           :m_cx( -1 ),
			    m_cy( -1 ),
				m_cxSplitterBorder( -1 ),
				m_cySplitterBorder( -1 )
{
}


CMySplitterWnd::~CMySplitterWnd(void)
{
}

// ���طָ���
// m_cxSplitterGap��m_cySplitterGap���ָ����Ŀ��
// m_cxBorder��m_cyBorder���ָ����ı߿�
void CMySplitterWnd::HideSplitter()
{
	// Save previous size
	m_cx = m_cxSplitterGap;   
	m_cy = m_cySplitterGap;   

	m_cxSplitterBorder = m_cxBorder;
	m_cySplitterBorder = m_cyBorder;

	m_cxSplitterGap = 1;      // Must > 0
	m_cySplitterGap = 1;

	m_cxBorder = 0;
	m_cyBorder = 0;
}

// ��ʾ�ָ���
void CMySplitterWnd::ShowSplitter()
{
    m_cxSplitterGap = m_cx;             
	m_cySplitterGap = m_cy;

    m_cxBorder = m_cxSplitterBorder;
	m_cyBorder = m_cySplitterBorder;
}

BEGIN_MESSAGE_MAP(CMySplitterWnd, CSplitterWnd)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


/// ����ƶ����κ�һ���ָ���ʱ�����ܴ���WM_MOUSEMOVE��Ϣ
void CMySplitterWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	// ע�͵����У��ָ������̶��������ƶ���
	// ��ע�ͣ���ָ����ܱ��ƶ�
	//CSplitterWnd::OnMouseMove(nFlags, point);

	// �����з������˶���Χ
	if( AfxGetMainWnd() )
	{
		CRect rect;
		AfxGetMainWnd()->GetClientRect( &rect );       // ��ȡ�ͻ����ߴ�

		int nColCount = this->GetColumnCount();
	    if((nColCount != 1) && (nColCount != 2))
	    {
		    return;
	    }

	    if( 2 == nColCount )      // ���У���ֱ�ָ���
	    {
			if((point.x < 200) || (point.x > rect.Width()/2))
            {
                CWnd::OnMouseMove(nFlags, point);    // �޶��ƶ���Χ����һ�п�ȣ�200 �� ����ܿͻ������/2
            }
            else
            {  
                CSplitterWnd::OnMouseMove(nFlags, point);
            }
	    }
	    else //if( 1 == nColCount )  // 1�У�ˮƽ�ָ���
	    {
			if((point.y < rect.Height()/2) || (point.y > rect.Height() - 100))
		    {
			    CWnd::OnMouseMove(nFlags, point);    // �޶��ƶ���Χ����һ�У�����ܿͻ����߶�/2 �� ����ܿͻ����߶�-200
		    }
		    else
		    {
                CSplitterWnd::OnMouseMove(nFlags, point);
		    }
	    }
	} //if( AfxGetMainWnd() )	
}
