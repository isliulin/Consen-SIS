// -----------------------------------------------------------------------
// $Workfile: Modbus.cpp $
// Author/Date  : rjvs 2002-01-28 10:20:22 (UTC-6:00)
// Description  : Modbus message holds a buffer to the input and output
//              : data, and an array of the aliases referenced by the
//              : message.
// -----------------------------------------------------------------------
//
//                         COPYRIGHT NOTICE
//                         ----------------
// Copyright (C) 2009, Tri-Sen Corporation, Webster, Texas
// Unauthorized possession, sale, transmission or reproduction
// is prohibited by law.
// -----------------------------------------------------------------------
// $Header: /Cfg320/Modbus.cpp 1     2/03/03 1:38p Rvanslooten $
//                         REVISION HISTORY
//                         ----------------
//
//     Date         Who          Change
// ----------  ----------------  -----------------------------------------
// 2002-06-04  Ryan Van Slooten  Added Comment Block
// -----------------------------------------------------------------------

#include "stdafx.h"
#include "Modbus.h"

// --------------------------------------------------------------------------

namespace modbus
{

/// <summary>
///   </summary>
/// <param name="TODO">
///   </param>
/// <return>
///   </return>
/// <created>
///   rjvs 2002-01-28 13:23:08 (UTC-6:00)</created>
WORD AliasOffset(int AliasNum)
{
	if((AliasNum >= 1) && (AliasNum < 10001))
	{
		return 1;
	}
	else if((AliasNum >= 10001) && (AliasNum < 20001))
	{
		return 10001;
	}
	else if((AliasNum >= 30001) && (AliasNum < 40001))
	{
		return 30001;
	}
	else if((AliasNum >= 40001) && (AliasNum < 50001))
	{
		return 40001;
	}
	else
	{
		return 0;
	}
}

/// <summary>
///   </summary>
/// <param name="TODO">
///   </param>
/// <return>
///   </return>
/// <created>
///   rjvs 2002-01-28 13:23:23 (UTC-6:00)</created>
BYTE ReadFunctionCode(int AliasNum)
{
	if((AliasNum >= 1) && (AliasNum < 10001))
	{
		return mbfnReadCoilStatus;
	}
	else if((AliasNum >= 10001) && (AliasNum < 20001))
	{
		return mbfnReadInputStatus;
	}
	else if((AliasNum >= 30001) && (AliasNum < 40001))
	{
		return mbfnReadInputRegisters;
	}
	else if((AliasNum >= 40001) && (AliasNum < 50001))
	{
		return mbfnReadHoldingRegisters;
	}
	else
	{
		return mbfnUnknown;
	}
}

/// <summary>
///   </summary>
/// <param name="TODO">
///   </param>
/// <return>
///   </return>
/// <created>
///   rjvs 2002-01-28 13:23:33 (UTC-6:00)</created>
BYTE WriteFunctionCode(int AliasNum, bool bMultiple)
{
	if((AliasNum >= 1) && (AliasNum < 10001))
	{
		return bMultiple ? mbfnWriteMultipleCoils : mbfnWriteCoil;
	}
	else if((AliasNum >= 40001) && (AliasNum < 50001))
	{
		return bMultiple ? mbfnWriteMultipleRegisters : mbfnWriteRegister;
	}
	else
	{
		return mbfnUnknown;
	}
}

/// <summary>
///   </summary>
/// <param name="TODO">
///   </param>
/// <return>
///   </return>
/// <created>
///   rjvs 2002-01-30 15:45:15 (UTC-6:00)</created>
WORD RtuResponseLength(BYTE Code, BYTE DataBytes, bool bModbusTcp)
{
	int nExcept = 0;
	int nNormal = 0;

	if( !bModbusTcp )       // Modbus Serial 
	{
		nExcept = 5;
		nNormal = 8;
	}
	else                    // Modbus Tcp:
	{
		nExcept = 9;          // (5-2)+6
		nNormal = 12;         // (8-2)+6
	}

	// Exception
	if( Code & 0x80 )  
	{
		return nExcept;
	}

	WORD result = 0;
	switch (Code)
	{
		case mbfnReadCoilStatus:
		case mbfnReadInputStatus:
		case mbfnReadHoldingRegisters:
		case mbfnReadInputRegisters:
			result = DataBytes + nExcept;
		break;

		case mbfnWriteCoil:
		case mbfnWriteRegister:
			result = nNormal;
		break;

		case mbfnExceptionStatus:               
			result = nExcept;
		break;

		case mbfnDiagnostic:                     // Dialog
			result = nNormal;
		break;

		case mbfnWriteMultipleCoils:
		case mbfnWriteMultipleRegisters:
			result = nNormal;
		break;

		default:
			break;
	}

	return result;
}

// --------------------------------------------------------------------------

} // namespace modbus


