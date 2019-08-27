#include "StdAfx.h"
#include "HistoryRecordData.h"

#include "Configurator.h"
#include "AliasItem.h"

/******************************************************/
// �������캯����ǳ����
/******************************************************/
CHistoryRecordData::CHistoryRecordData(const CHistoryRecordData& orig)
		: m_pAliasItem( orig.m_pAliasItem )
		, m_LocalDataMap( orig.m_LocalDataMap.begin(), orig.m_LocalDataMap.end())
{
	ASSERT( m_pAliasItem != NULL );
}

/******************************************************/
// ��ֵ�����������ǳ����
/******************************************************/
CHistoryRecordData& CHistoryRecordData::operator=(const CHistoryRecordData& rhs)
{
	if( this == &rhs )
	{
		return *this;
	}

	m_pAliasItem = rhs.m_pAliasItem;
	m_LocalDataMap.clear();
	m_LocalDataMap.insert( rhs.m_LocalDataMap.begin(), rhs.m_LocalDataMap.end());

	return *this;
}

/******************************************************/
// ��������ڱ��ص�����
/******************************************************/
 void CHistoryRecordData::Clear()
{
	m_LocalDataMap.clear();
}

/******************************************************/
// ����ǰʱ���������ӵ��������ݼ�����
/******************************************************/
void CHistoryRecordData::Add( CString strTime )
{
	ASSERT( m_pAliasItem != NULL );
	if( m_pAliasItem != NULL )
	{
		CString strValue;
		VariantToRecordString( m_pAliasItem->remVar(), strValue );

		// Check how to add: replace or add
		CString strKeyTime;
		bool bAddFlag = true;
		StringMap::reverse_iterator it = m_LocalDataMap.rbegin();
		if( it != m_LocalDataMap.rend())
		{
			if( strValue.CompareNoCase( it->second ) == 0 )
			{
				strKeyTime = it->first;
				++it;

				if( it != m_LocalDataMap.rend())
				{
					if( strValue.CompareNoCase( it->second ) == 0 )
					{
						bAddFlag = false;		
					}
				}
			}
		}

		if( bAddFlag ) // Add new point
		{
			m_LocalDataMap.insert( std::make_pair( strTime, strValue ));
		}
		else // Replace the last point
		{
			m_LocalDataMap.erase( strKeyTime );
			m_LocalDataMap.insert( std::make_pair( strTime, strValue ));
		}
	}
}