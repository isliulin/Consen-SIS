#pragma once

#include "HistoryFileData.h"
#include <vector>

// ����ʾ����ʷ��ͼ�����ࣺ�鿴��ʷ����ʱ�����û�ָ�� ���� ������ͼ��̬���£�
// 
// ��;����¼�û�ָ�� ���� ��̬���µĽ����
class CHistoryViewData
{
public:
    CHistoryViewData(COLORREF nColor=RGB(0,0,0), UINT nWidth=2, int nIndex=-1, CHistoryFileData *pFileData=NULL)
		: m_nColor( nColor )
		, m_nWidth( nWidth )
		, m_nSeriesIndex( nIndex )
		, m_pFileData( pFileData )
	{
	}

private:
    COLORREF m_nColor;   // ����������ɫ��Ĭ�Ϻ�ɫ
    UINT m_nWidth;       // ���߿�ȣ�Ĭ��2����λ����
    int m_nSeriesIndex;  // ��/���е����

	CHistoryFileData *m_pFileData;

public:
    // ��ȡ������ǩ��
	CString GetTagName() const
	{
		if( m_pFileData != NULL )
		{
			return m_pFileData->m_strTagName;
		}

		return L"";
	}

    // ��ȡ����������Ϣ
    CString GetDesc() const
	{
		if( m_pFileData != NULL )
		{
			return m_pFileData->m_strDesc;
		}

		return L"";
	}

    // ��ȡ����Modbus����
	int GetAlias() const
	{
		if( m_pFileData != NULL )
		{
			return m_pFileData->m_nAlias;
		}

		return -1;
	}

	CString GetAlias_s() const
	{
		CString str( "-1" );
		if( m_pFileData != NULL )
		{
			str.Format( L"%d", m_pFileData->m_nAlias );
		}

		return str;
	}
   
	COLORREF GetColor()       const { return m_nColor; }              // ��ȡ������ɫ
	UINT GetWidth()           const { return m_nWidth; }              // ��ȡ���߿��
	int GetSeriesIndex()      const { return m_nSeriesIndex; }        // ��ȡ���к�
	CHistoryFileData* GetFileData() { return m_pFileData; }
	const CHistoryFileData* GetFileData() const { return m_pFileData; }

	void SetColor(COLORREF nColor)   { m_nColor = nColor; }       // ����������ɫ
	void SetWidth(UINT nWidth)       { m_nWidth = nWidth; }       // ���������߿�
	void SetSeriesIndex(int nIndex)  { m_nSeriesIndex = nIndex; } // �������к�/�����
	void SetFileData( CHistoryFileData* data )
	{
		if( m_pFileData != data )
		{
			m_pFileData = data;
		}
	}

	void Reset( COLORREF color )
	{
		m_nColor = color;      // ����������ɫ��Ĭ�Ϻ�ɫ
		m_nWidth = 2;          // ���߿�ȣ�Ĭ��2����λ����
		m_nSeriesIndex = -1;   // ��/���е����
		m_pFileData = NULL;
	}
};


// ����ʾ����ʷ��ͼ���ݼ�����
//
// ��;����History��/����ͼ��ʾ��
// ʹ��˵����
// 1.Doc�м��ϣ�vector����ʼ��8��Ԫ�أ���ΪNULL��
// 2.�˵�-�鿴 ���� ����ʷ����ͼ��̬����ʱ������ʵ��������£�
// 3.�½�/���ļ�ʱ������գ�
// 4.�л�Ӧ�ó������͡���Ʒ����ʱ�����ͷ���Դ�������������
// 5.�ر�Ӧ�ó���ʱ���ͷ���Դ�����.
class CHistoryViewDatas
{
public:
	CHistoryViewDatas();
	~CHistoryViewDatas();

private:
	CHistoryViewDatas(const CHistoryViewDatas&);
	CHistoryViewDatas& operator=(const CHistoryViewDatas&);

private:
	std::vector<CHistoryViewData*> m_vHisViewDatas;

public:
	size_t Size() const    { return m_vHisViewDatas.size(); }
	void Clear();
	const CHistoryViewData* GetHisViewData( const size_t index ) const;
	CHistoryViewData* GetHisViewData( const size_t index );
	void SetHisViewData( const size_t index, CHistoryViewData* data );

	void Reset();
};
