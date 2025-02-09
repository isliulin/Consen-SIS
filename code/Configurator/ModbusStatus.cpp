// -----------------------------------------------------------------------
// File         : ModbusStatus.cpp
// Author/Date  : rjvs 2002-06-04 14:50:30 (UTC-6:00)
// Description  : Thread-safe status class which holds percent complete,
//              : status message, and error message information.
// -----------------------------------------------------------------------
//
//                         COPYRIGHT NOTICE
//                         ----------------
// Copyright (C) 2011, Tri-Sen Corporation, Webster, Texas
// Unauthorized possession, sale, transmission or reproduction
// is prohibited by law.
// -----------------------------------------------------------------------
// $Header: /Software/Cfg310SV/ModbusStatus.cpp 4     10/31/02 4:01p Rvanslooten $
//                         REVISION HISTORY
//                         ----------------
//
//     Date         Who          Change
// ----------  ----------------  -----------------------------------------
// 2011-02-28  Wang Dong         BCB5 to Visual Studio 2011
// 2002-06-04  Ryan Van Slooten  Added Comment Block
// -----------------------------------------------------------------------

#include "StdAfx.h"
#include "ModbusStatus.h"

#include "Configurator.h"

//---------------------------------------------------------------------------

namespace modbus
{

//---------------------------------------------------------------------------
// { CModbusStatus }

/// <summary>
///   </summary>
/// <created>
///   rjvs 2002-02-01 11:48:11 (UTC-6:00)</created>
CModbusStatus::CModbusStatus(void)
	          :m_hr( S_OK ),
			   m_nCount( 0 ),
			   m_nTotalCount( 0 ),
			   m_nProgress( 100 )
{
}


CModbusStatus::~CModbusStatus(void)
{
}

/// <summary>
///   </summary>
/// <return>
///   </return>
/// <created>
///   rjvs 2002-02-01 10:00:52 (UTC-6:00)</created>
LPCTSTR CModbusStatus::GetMessage()
{
	CSingleLock sl( &m_cirsec );
	sl.Lock();
	ASSERT( sl.IsLocked());
	
	return (LPCTSTR)m_strMessage;
}


/// <summary>
///   </summary>
/// <param name="Message">
///   </param>
/// <created>
///   rjvs 2002-02-01 10:01:01 (UTC-6:00)</created>
void CModbusStatus::SetMessage( const CString& Message )
{
	CSingleLock sl( &m_cirsec );
	sl.Lock();
	if( sl.IsLocked())
	{
		m_strMessage = Message;

		sl.Unlock();
	}
}

void  CModbusStatus::SetMessage( UINT uID )
{
	CSingleLock sl( &m_cirsec );
	sl.Lock();
	if( sl.IsLocked())
	{
		CString str;
		str.LoadStringW( uID );
		m_strMessage = str;

		sl.Unlock();
	}
}


CString CModbusStatus::GetErrorMsg()
{
	CSingleLock sl( &m_cirsec );
	sl.Lock();
	ASSERT( sl.IsLocked());
	
	return m_strError;
}


/// <summary>
///   </summary>
/// <param name="Value">
///   </param>
/// <created>
///   rjvs 2002-03-05 11:09:54 (UTC-6:00)</created>
void  CModbusStatus::SetError( HRESULT hr, const CString& strError )
{
	CSingleLock sl( &m_cirsec );
	sl.Lock();
	if( sl.IsLocked())
	{
		m_hr = hr;

		/*
		if( strError.IsEmpty())
		{
			m_strError = HrGetMessage( m_hr );
		}
		else if( hr != S_OK )
		{
		   m_strError = strError;
		}
		else
		{
		   m_strError = L"";
		}*/

		m_strError = strError;
		m_strMessage = m_strError;

		if( m_hr != S_OK )
		{
			theApp.LogInfo( m_strMessage );
		}

		sl.Unlock();
	}
}

/// <summary>
///   </summary>
/// <param name="Value">
///   </param>
/// <created>
///   rjvs 2002-02-19 15:58:46 (UTC-6:00)</created>
void CModbusStatus::SetCount( int Value )
{
    m_nCount = Value;
    Update();
}

/// <summary>
///   </summary>
/// <param name="Value">
///   </param>
/// <created>
///   rjvs 2002-02-19 15:54:23 (UTC-6:00)</created>
void CModbusStatus::IncrementCount( int Value )
{
    // Atomic operation
    m_nCount += Value;
    Update();
}

/// <summary>
///   </summary>
/// <param name="Value">
///   </param>
/// <created>
///   rjvs 2002-02-19 16:00:53 (UTC-6:00)</created>
void
CModbusStatus::TotalCount( int Value )
{
    m_nCount = 0;
    if( m_nTotalCount == 0 )
	{
        m_nTotalCount = 100;
	}
    else
	{
        m_nTotalCount = Value;
	}

    Update();
}

/// <summary>
///   </summary>
/// <created>
///   rjvs 2002-02-19 16:14:52 (UTC-6:00)</created>
void CModbusStatus::Update()
{
    if( m_nTotalCount == 0 )
	{
        m_nProgress = m_nCount;
	}
    else
	{
        m_nProgress = 100 * m_nCount / m_nTotalCount;
	}

    if( m_nProgress < 0 ) 
	{
		m_nProgress = 0;
	}

    if( m_nProgress > 100 ) 
	{
		m_nProgress = 100;
	}
}

//---------------------------------------------------------------------------
} // namespace modbus
