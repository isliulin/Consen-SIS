#pragma once

#include "mytchart.h"
#include "seriesxmlsource2.h"
#include "ConfiguratorView.h" 
#include "memory"

const size_t SERIES_COUNT = 8;
const size_t IDC_HISTIMER = 1001;

// CHistoryTrendView ��ͼ
class CViewHistoryCtrl;
class CHistoryTrendView : public CConfiguratorView
{
	DECLARE_DYNCREATE(CHistoryTrendView)

public:
	CHistoryTrendView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CHistoryTrendView();

private:
	CMytchart m_tChart;
	CSeriesxmlsource2 m_xmlSrcV[SERIES_COUNT];
	const CViewHistoryCtrl *m_pViewHisCtrl;
	UINT m_uHisTimer;
	UINT m_nLastRate;
	CCriticalSection m_cs;  // Locl series: FileName and SeriesNode
	std::auto_ptr<CEvent> m_pTimerUpdateEvent;

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

public:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

    DWORD WaitTimerUpdateFinish( DWORD dwMs = 10000 )
	{
		return WaitForSingleObject( m_pTimerUpdateEvent->m_hObject, dwMs );
	}

	void SetAxisTime( const double dStartTime );
	inline void KillHisTimer();
	void TimerUpdate();

private:
	inline void SetHisTimer( UINT nElapse );
	inline void SetAxisAutomatic( bool bAutomatic );

	void ClearView();          // �����ǰ��ͼ�е���ʷ����
	void InitUpdate();
	void DynUpdate();
	void UpdateCurHisData();   // �鿴��ǰ��ʷ����
	void UpdateFileData();     // �鿴ĳһָ����ʷ��¼�ļ�
	inline void UpdateAxisFormat();
	void UpdateSeries( bool bViewCurrent = false );

public:
	DECLARE_EVENTSINK_MAP()
	void Mytchart_OnScroll();
	void Mytchart_MouseDown(long Button, long Shift, long X, long Y);
};


