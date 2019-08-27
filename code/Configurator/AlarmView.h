#pragma once

// Added by wangdong
#include "mygridn.h"                  // For FlexGrid ActiveX control
#include "ConfiguratorView.h"        // Derived from CConfiguratorView               

// CAlarmView ��ͼ

class CAlarmView : public CConfiguratorView          // CView -> CConfiguratorView
{
	DECLARE_DYNCREATE(CAlarmView)

protected:
	CAlarmView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CAlarmView();

public:
//	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

private:
	enum Columns{ COL_NAME, COL_VALUE, COL_LAST = COL_VALUE };

	CMygridn m_sGrid;

	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint );
	void UpdateRefresh( void );                          // ���� Name �У���һЩ�ж�
	void UpdateMonitor( bool bMonitor = false );         // ���� Value ��
	void ApplyFont( void );
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnDraw(CDC* /*pDC*/);
};


