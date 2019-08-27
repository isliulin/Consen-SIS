#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CSelectTNDlg �Ի���
class CHistoryFileDatas;
class CSelectTNDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectTNDlg)

public:
	CSelectTNDlg(CHistoryFileDatas* pHisFileDatas, CString strTagname, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelectTNDlg();

// �Ի�������
	enum { IDD = IDD_DLG_SELTN };
	enum { FILTER_ALL, FILTER_COIL, FILTER_IN, FILTER_HOLDREG, FILTER_INREG };
	enum { COL_ALIAS, COL_TAGNAME, COL_DESC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

private:
	CHistoryFileDatas *m_pHisFileDatas;
	CString m_strSelTagname;
	CComboBox m_cboFilter;
	CListCtrl m_listTag;

private:
	void AddFilterItems( int nFilterType );
	
public:
	CString GetSelTagName() const  { return m_strSelTagname; }

public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeCboTnf();
};
