#pragma once


// CCalBasePage �Ի���

class CCalBasePage : public CPropertyPage
{
	DECLARE_DYNAMIC(CCalBasePage)

public:
	CCalBasePage();
	virtual ~CCalBasePage();

// �Ի�������
	enum { IDD = IDD_CALBASEPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
