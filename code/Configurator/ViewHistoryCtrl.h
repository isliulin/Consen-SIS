#pragma once

// �����࣬���ڼ�¼�û����õĲ鿴���ܲ�����
// 
// �÷���ȫ�֣�
// 
// ��;��
// �����û��趨�Ĳ鿴���ܲ�����
// ��History��/����ͼ��ʼ����ˢ����ʾ��

#include "RecordHistoryCtrl.h"
class CViewHistoryCtrl
{
public:
	CViewHistoryCtrl( CRecordHistoryCtrl *record )
		: m_nViewType( VIEW_NONE )
		, m_nUpdateRate( 60 )
		, m_nTimeRange( 1800 )
		, m_strTimeFormat( L"HH:NN:SS" )
		, m_strFilePathName( L"" )
		, m_pRecordCtrl( record )
	{
		ASSERT( m_pRecordCtrl != NULL );
	}

private:
	CViewHistoryCtrl(const CViewHistoryCtrl&);
	CViewHistoryCtrl& operator=(const CViewHistoryCtrl&);

private:
    // �鿴���ͣ�
	// 0��δ�鿴��
    // 1���鿴���ڱ���¼�����ݣ��趨ʱˢ����ͼ��ʾ��
    // 2���鿴ָ�������ļ��е����ݣ�
    int m_nViewType;
    UINT m_nUpdateRate;       // ��ʷ����ˢ�����ʣ�Сʱ/��/�룬��λs��Ĭ��60��
    UINT m_nTimeRange;        // ʱ���ȣ���/Сʱ/��/�룬��λs��Ĭ��30���ӣ���1800��
    CString m_strTimeFormat;  // ʱ��̶ȸ�ʽ��MM:DD:YY HH:MM:SS Ĭ��HH:MM:SS

	// �ļ�·�����������鿴����ʷ�����ļ�·��+�ļ�����
	// �鿴����Ϊ0ʱ, �գ�
    // �鿴����Ϊ1ʱ���ļ��Ǽ�¼��ʷ����ʱָ�����ļ�(�ڼ����󣬻ᱻ����)��
    // �鿴����Ϊ2ʱ���ļ����û�ָ���鿴����ʷ�����ļ���
    CString m_strFilePathName;
	CRecordHistoryCtrl* m_pRecordCtrl;

public:
	enum { VIEW_NONE, VIEW_CURRENT, VIEW_FILE };

public:
	int  GetViewType()                 const { return m_nViewType; }           // ��ȡ�鿴����
	UINT GetUpdateRate()               const { return m_nUpdateRate; }         // ��ȡ��ʷ����ˢ������
	UINT GetTimeRange()                const { return m_nTimeRange; }          // ��ȡʱ����
	CString GetTimeFormat()            const { return m_strTimeFormat; }       // ��ȡʱ��̶ȸ�ʽ
	CString GetRecordingFilePathName() const { return m_pRecordCtrl->GetFilePathName(); }
	CString GetFilePathName() const 
	{ 
		if( VIEW_CURRENT == m_nViewType)
		{
			ASSERT( m_pRecordCtrl != NULL );
			return m_pRecordCtrl->GetFilePathName();
		}
		else
		{
			return m_strFilePathName;
		}
	}

	// ���ò鿴����
    void SetViewType(int nViewType )
	{
		if( m_nViewType != nViewType ) 
		{
			m_nViewType = nViewType;
		}
	}

    // ������ʷ����ˢ������
    void SetUpdateRate(UINT nUpdateRate = 60)
	{
		if( m_nUpdateRate != nUpdateRate )
		{
			m_nUpdateRate = nUpdateRate;
		}
	}

    // ����ʱ����
    void SetTimeRange(UINT nTimeRange = 30*60)
	{
		if( m_nTimeRange != nTimeRange )
		{
			m_nTimeRange = nTimeRange;
		}
	}

    // ����ʱ��̶ȸ�ʽ
    void SetTimeFormat(CString strFormat)
	{
		if( m_strTimeFormat != strFormat )
		{
			m_strTimeFormat = strFormat;
		}
	}

    // ���������ļ�·��������������ʷ�ļ����ò鿴����
    void SetFilePathName( CString strPathName )
	{
		if( m_nViewType != VIEW_CURRENT )
		{
			if( m_strFilePathName != strPathName )
			{
				m_strFilePathName = strPathName;
			}
		}
	}

	// Reset ctrl
	void Reset()
	{
		m_nViewType = VIEW_NONE;
		m_nUpdateRate = 60;
		m_nTimeRange = 1800;
		m_strTimeFormat = L"HH:NN:SS";
		m_strFilePathName = L"";
	}
};
