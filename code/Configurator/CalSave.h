#pragma once


// CCalSave �Ի���
class CDSC100Calibrate;
class CCalSave : public CPropertyPage
{
	DECLARE_DYNAMIC(CCalSave)

public:
	CCalSave();
	virtual ~CCalSave();

// �Ի�������
	enum { IDD = IDD_CAL_SAVE };

private:
	CFont m_boldFont;
	CFont m_norFont;
	CImage m_imgPassing;
	CImage m_imgPass;

	CDSC100Calibrate* m_pCalibrate;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	virtual BOOL OnWizardFinish();
	virtual BOOL OnSetActive();
};
