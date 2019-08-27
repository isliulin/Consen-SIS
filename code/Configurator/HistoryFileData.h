#pragma once

#include <map>

// ��ʷ�ļ������ࣺ����Ŀ����ʷ�����ļ����ض���
// 
// ��;�����û�ѡ���Ѽ�¼�ı�ǩ��
 
class CHistoryViewData;
class CHistoryFileData
{
public:
    CHistoryFileData( CString strTagName, CString strDesc, int nAlias )
		: m_strTagName( strTagName )
		, m_strDesc( strDesc )
		, m_nAlias( nAlias )
	{
		m_strAlias.Format( L"%d", nAlias );
	}

private:
    CString m_strTagName;   // ��ǩ��
    CString m_strDesc;      // ����������Ϣ
    int m_nAlias;           // ����������Modbus��ַ��
	CString m_strAlias;

public:
	CString GetTagname() const { return m_strTagName; }

friend class CHistoryViewData;
friend class CSelectTNDlg;
};




// ��ʷ�ļ����ݼ�����
// ʹ��˵����
// 1.Doc�м��ϣ�map����ʼ��Ϊ�գ�
// 2.�û��״�ѡ���ǩ��ʱ�����ݲ鿴���ͣ�����Ŀ����ʷ��¼�ļ���
// 3.ȷ���鿴ʱ������ļ���֮ǰ��ͬ������ռ��ϣ�
// 4.�л�Ӧ�ó������͡���Ʒ����ʱ����գ�
// 5.�½�/���ļ�ʱ������ա�
typedef std::map<int, CHistoryFileData*> HFileDatas;
class CHistoryFileDatas
{
public:
	CHistoryFileDatas()
		:m_vHFileDatas()
	{
	}

	~CHistoryFileDatas();

	CHistoryFileDatas( const CHistoryFileDatas& );
	CHistoryFileDatas& operator=( const CHistoryFileDatas& );
	
private:
	HFileDatas m_vHFileDatas;

public:
	const HFileDatas& GetHFileDatas()    const { return m_vHFileDatas; }
	
	void Clear();
	void Add( int nAlias, CHistoryFileData* data );
	const CHistoryFileData* find_num( int nAlias ) const;
	const CHistoryFileData* find_name( const CString strTagName ) const;
	CHistoryFileData* CHistoryFileDatas::find_name( const CString strTagName );
};
