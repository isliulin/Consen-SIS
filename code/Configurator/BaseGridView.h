#pragma once

#include "ConfiguratorView.h"                       // Derived from CConfiguratorView
#include "mygridn.h"

class CSettingItem;
class CSettingVector;
class CAliasMap;

// CBaseGridView ��ͼ

class CBaseGridView : public CConfiguratorView      // CView
{
	DECLARE_DYNCREATE(CBaseGridView)

protected:
	CBaseGridView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CBaseGridView();

	virtual CSettingItem* GetRowSetting( long lRow );
	CAliasMap* GetSelectionSettings();

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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

public:
	CMygridn m_sGrid;

	void ApplyFont( void );

	virtual HRESULT GotoSetting(const CSettingItem* pSetting);
	virtual void RefreshColumnSizes() { };

	CMygridn& GetViewGrid()           { return m_sGrid; }

	void SetStringSettings( int nBegin, int nEnd, int nString, bool bLocal = false );
	void SplitStringSettings( int nBegin, int nEnd, int nString );
};


