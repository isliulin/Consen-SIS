// -----------------------------------------------------------------------
// File         : ModbusStatus.hpp
// Author/Date  : rjvs 2002-06-04 14:50:30 (UTC-6:00)
// Description  : Thread-safe status class which holds percent complete,
//              : status message, and error message information.
// -----------------------------------------------------------------------
//
//                         COPYRIGHT NOTICE
//                         ----------------
// Copyright (C) 2001, Triconex Corporation, Webster, Texas
// Unauthorized possession, sale, transmission or reproduction
// is prohibited by law.
// -----------------------------------------------------------------------
// $Header: /Cfg310SV_V1.00/ModbusStatus.hpp 4     2/24/03 11:14a Rvanslooten $
//                         REVISION HISTORY
//                         ----------------
//
//     Date         Who          Change
// ----------  ----------------  -----------------------------------------
// 2011-02-28  Wang Dong         BCB5 to Visual Studio 2011
// 2002-06-04  Ryan Van Slooten  Added Comment Block
// -----------------------------------------------------------------------

#pragma once

//---------------------------------------------------------------------------

namespace modbus
{

//---------------------------------------------------------------------------

class CModbusStatus
{
public:
    CModbusStatus();
    ~CModbusStatus();

private:
	CCriticalSection m_cirsec;
    CString m_strMessage;
    CString m_strError;
    HRESULT m_hr;
    int m_nCount;
    int m_nTotalCount;
    int m_nProgress;

    void Update();

public:
    HRESULT GetError()              const { return m_hr; }
	void  ClearError()              { m_hr = S_OK; }

	int GetProgress()               const { return m_nProgress; }
	void SetProgress( int Value )   { m_nProgress = Value; } 

	LPCTSTR GetMessage();
    CString GetErrorMsg();

    void  SetMessage( const CString& Message );
	void  SetMessage( UINT uID );
	void  SetError( HRESULT hr, const CString& strError );

    void  SetCount( int Value );
    void  IncrementCount( int Value );
    void  TotalCount( int Value );  
};

//---------------------------------------------------------------------------

} // namespace modbus

