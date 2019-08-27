#pragma once

#include "ConfiguratorView.h"
#include "mygridn.h"

// CHistoryValueView ��ͼ

class CHistoryValueView : public CConfiguratorView
{
	DECLARE_DYNCREATE(CHistoryValueView)

public:
	CHistoryValueView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CHistoryValueView();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

private:
	CMygridn m_sGrid;
	enum { COL_DESC, COL_TAGNAME, COL_ALIAS, COL_SERIES };

private:
	void ApplyFont( void );
	void RefreshColumnSizes();
	void UpdateHisViewDatas();
	void SetColorPicture( long Row, size_t index );

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

	// Grid Event
	DECLARE_EVENTSINK_MAP()
	void Mygridn_AfterUserResize(long Row, long Col);
};


