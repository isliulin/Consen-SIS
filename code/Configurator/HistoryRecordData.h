#pragma once

// ����¼��Modbus�����ࣺ�û�������ʷ��¼ʱ����̬���ɲ����뼯��;
// ��;����¼һ����Ŀ�ı������ݡ�
#include <map>
#include "AliasItem.h"

typedef std::map<CString,CString> StringMap;
class CHistoryRecordData
{
public:
    CHistoryRecordData(CAliasItem* pAlias )
		: m_pAliasItem( pAlias )
		, m_LocalDataMap()
	{
		ASSERT( m_pAliasItem );
	}

    // �������캯�� ��ֵ���������ǳ��������
    CHistoryRecordData(const CHistoryRecordData& orig);
	CHistoryRecordData& operator=(const CHistoryRecordData& rhs);

    // ��������ڱ��ص���������
    ~CHistoryRecordData()
	{
		Clear();
	}

private:
	CAliasItem* m_pAliasItem;
    StringMap m_LocalDataMap;    // �����¼�������ݣ�ʱ��-��ֵ�ԣ����;�ΪCString

public:
    void Clear();                 // ��������ڱ��ص�����
    void Add( CString strTime );  // ����ǰʱ���������ӵ��������ݼ�����
	bool HasLocalDatas() const
	{
		return (m_LocalDataMap.size() != 0);
	}

	int GetAlias() const
	{
		int nAlias = -1;
		if( m_pAliasItem != NULL )
		{
			nAlias = m_pAliasItem->GetAlias();
		}

		return nAlias;
	}
	
	const CAliasItem* GetAliasItem() const
	{
		return m_pAliasItem;
	}

	CAliasItem* GetAliasItem() 
	{
		return m_pAliasItem;
	}

	const StringMap& GetLocalDataMap() const
	{
		return m_LocalDataMap;
	}
};

