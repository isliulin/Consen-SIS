#pragma once
#include "afxcmn.h"


// CSelAppTypeDlg �Ի���

class CSelAppTypeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelAppTypeDlg)

public:
	CSelAppTypeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelAppTypeDlg();

// �Ի�������
	enum { IDD = IDD_SEL_APPTYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_ListCtrl;
	CImageList *m_pImageList;

public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	int m_nIndex;
};
