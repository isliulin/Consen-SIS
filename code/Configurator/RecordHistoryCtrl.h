#pragma once

// �����࣬���ڼ�¼�û����õ���ʷ��¼���ܲ�������Щ��������������ʱ�����޸ġ�
// 
// �÷�:
// 
// ��;��
// �����û��趨�ļ�¼���ܲ�����
// ����ʷ��¼�̺߳���ʹ��
// 
const UINT MAX_FILE_SIZE = 2*1024*1024;     // 2M
class CRecordHistoryCtrl
{
public:
    CRecordHistoryCtrl( int nSamplingRate=1, UINT nMaxsize=MAX_FILE_SIZE )
		: m_nSamplingRate( nSamplingRate )  // Default 1s
		, m_nInterval( 500 )                // Fixed 500s
		, m_nMaxSize( nMaxsize )            // Default 2M
		, m_strFilePathName( L"" )
		, m_bFileModified( false )
	{
	}

private:
	CRecordHistoryCtrl(const CRecordHistoryCtrl&);
	CRecordHistoryCtrl& operator=(const CRecordHistoryCtrl&);

private:
    UINT m_nSamplingRate;        // ���ݲ������ʣ�Data Sampling Rate��:Сʱ/��/��/���룻��sΪ��λ��Ĭ��1s
    UINT m_nInterval;            // д�ļ������Write File Interval�����̶�500s
    UINT m_nMaxSize;             // �����ļ������ߴ磺�̶�500M; ��λ�ֽ�
    CString m_strFilePathName;   // ��ʷ�����ļ�·��+�ļ���
	bool m_bFileModified;        // new datas was added to file or create new record file after maximum size
	
	CCriticalSection m_cs;       // ��ʷ��¼�߳�д���ļ��������ߴ�ʱ����д���ļ�·������
	                             // ���̶߳����鿴��ǰ����ʱ����ȡ���ļ�·������

public:
	UINT GetSamplingRate()     const  { return m_nSamplingRate; }   // ��ȡ�û��趨�����ݲ�������
	UINT GetInterval()         const  { return m_nInterval; }       // ��ȡд�ļ����
	UINT GetMaxSize()          const  { return m_nMaxSize; }        // ��ȡ��������ļ��ߴ�
	bool IsFileModified()          const  { return m_bFileModified; }

	// ��ȡ�����ļ��Ĵ洢λ�ú��ļ���
	// �鿴��ǰ����ʱ����ȡ���ļ�·����
	CString GetFilePathName()  
	{ 
		CSingleLock sl( &m_cs );
		sl.Lock();
		
		return m_strFilePathName;
	}

	

    void SetSamplingRate( UINT nSamplingRate )   { m_nSamplingRate = nSamplingRate; }  //s
	void SetMaxSize( UINT value )                { m_nMaxSize = value; }
	void SetFileModified( bool bModified )       { m_bFileModified = bModified; }                      

	// ������ʷ�����ļ�·������·��+�ļ���
	// ��ʷ��¼�̻߳��д���ļ�������ǰ�ļ��ﵽ�趨�����ߴ�󣬸�д
    void SetFilePathName( CString strFilePathName )  
	{
		CSingleLock sl( &m_cs );
		sl.Lock();
		if( sl.IsLocked())
		{
			m_strFilePathName = strFilePathName;
			sl.Unlock();
		}
	}

	void Reset()
	{
	    m_nSamplingRate = 1;          // Default 1s
		m_nInterval = 500;            // Fixed 500s
		m_nMaxSize = MAX_FILE_SIZE;   // Default 2M
		m_strFilePathName = L""; 
		m_bFileModified = false;
	}
};
