#pragma once


// CCalInfoDlg �Ի���
class CDSC100Calibrate;
class CCalInfoDlg : public CPropertyPage
{
	DECLARE_DYNAMIC(CCalInfoDlg)

public:
	CCalInfoDlg();
	virtual ~CCalInfoDlg();

// �Ի�������
	enum { IDD = IDD_CAL_INTRO };

private:
	CFont m_boldFont;
	CFont m_norFont;
	CImage m_imgPassing;
	CImage m_imgUnPass;

	CDSC100Calibrate* m_pCalibrate;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

public:
	afx_msg void OnPaint();
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	virtual void OnCancel();
};
