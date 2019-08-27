#pragma once

#include "ConfiguratorView.h"                              // Added by wangdong                                   

// CTuneView ��ͼ
class CSettingItem; 
class CTuneFraView;
class CNonTuningFra;
typedef std::vector<CTuneFraView*> TuneFrameVector;

class CTuneView : public CConfiguratorView                 // CView
{
	DECLARE_DYNCREATE(CTuneView)

protected:
	CTuneView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CTuneView();

public:
	CSettingItem* m_pTuningBase;
	TuneFrameVector m_FraVector;
	CNonTuningFra* m_pNonTuningFra;

private:
	DWORD m_dwViewHelpID;

	void CreateFrames( void );
	void DestoryFrames( void );

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
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnVScroll( UINT nSBCode , UINT nPos , CScrollBar * pScrollBar ); 

	virtual void OnInitialUpdate();
};


