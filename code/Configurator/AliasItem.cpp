// -----------------------------------------------------------------------
// $Workfile: AliasItem.cpp $
// Author/Date  : WandDong 2010-12-06 11:20:00 (UTC-6:00)
// Description  : Alias item and map for the document
// -----------------------------------------------------------------------
//
//                         COPYRIGHT NOTICE
//                         ----------------
// Copyright (C) 2010, Tri-Sen Corporation, Webster, Texas
// Unauthorized possession, sale, transmission or reproduction
// is prohibited by law.
// -----------------------------------------------------------------------
// $Header: /Configurator/AliasItem.cpp  1     12/06/10 11:00a WangDong $
//                         REVISION HISTORY
//                         ----------------
//
//     Date         Who          Change
// ----------  ----------------  -----------------------------------------
// 2010-12-06  WangDong          Demo
// -----------------------------------------------------------------------

#include "stdafx.h"
#include "Configurator.h"
#include "AliasItem.h"

// -----------------------------------------------------------------------
#define V_BUF          V_I1REF               // Function,like V_I2
#define VT_BUF         (VT_BYREF|VT_I1)      // char*

// -----------------------------------------------------------------------
/// <summary>
///   Clears heap allocated buffer memory from a variant.</summary>
/// <param name="v">
///   Variant to clear.</param>
/// 释放数据类型为"String"数据使用的内存，并将其vt设置为VT_EMPTY
/// <created>
///   rjvs 2002-12-12 13:06:16 -06:00</created>
inline void VariantClearAliasBuffer(VARIANT &v)
{
    if( V_VT(&v) == VT_BUF )
    {
        ASSERT((V_I1REF(&v) == NULL) || CheckWritePtr(V_I1REF(&v), sizeof(char)));
        SAFE_DELETE_ARRAY( V_I1REF(&v));

        V_VT(&v) = VT_EMPTY;
    }
}


/// <summary>
///   Allocates a BYTE buffer for an alias and converts the existing data,
///   if present.</summary>
/// <param name="v">
///   Variant to convert.</param>
/// <param name="size">
///   Size of the buffer to be allocated.</param>
///  初始化 value 个字符为 0
/// <created>
///   rjvs 2002-12-12 13:47:54 -06:00</created>
void VariantAllocateBuffer(VARIANT& v, int size)
{
    char* scratch = new char[size + 1];
	int i = sizeof(*scratch);
    memset(scratch, 0, sizeof(char) * (size + 1));

    if( V_VT(&v) == VT_BSTR )
    {
		_bstr_t b( V_BSTR(&v));
		LPCTSTR pcStr = b;
		char* temp = CW2A( pcStr );       // const wchar_t* -> char*
        ::strncpy_s(scratch, (size+1), temp, size);
		SAFE_DELETE_ARRAY( temp );
    }
    else if( V_I1REF(&v) != NULL )
    {
        char* temp = V_I1REF(&v);
        ::strncpy_s(scratch, (size+1), temp, size);
        SAFE_DELETE_ARRAY( temp );
    }

    V_I8(&v) = 0;
    V_I1REF(&v) = scratch;  
}

//------------------------------------------------------------------------------------------
CAliasItem::CAliasItem()
	:m_strName(),
	 m_strDesc(),
	 m_nAlias( 0 ),
	 m_uItemAppType( 0 ),
	 m_eDataType( ALIAS_UNKNOWN ),
	 m_eProtectType( PROTECT_DEFAULT ),
	 m_bySize( 0 ),
	 m_bDirtyLocal( NULL ),
	 m_bDirtyRemote( NULL ),
	 m_bRecord( false ),
	 m_bActive( false )
{
	// VT_EMPTY
	::VariantInit( &m_avLocal );       
	::VariantInit( &m_avRemote ); 
	::VariantInit( &m_avCompareFile );
}

CAliasItem::~CAliasItem()
{
	// 释放数据类型为"String"数据使用的内存，并将其vt设置为VT_EMPTY
	VariantClearAliasBuffer( m_avLocal );            
    VariantClearAliasBuffer( m_avRemote );   
	VariantClearAliasBuffer( m_avCompareFile );

	// 如果不包含动态分配的内存，则实际上这两个函数不是必须调用的
	//          BString   /   Safe Array
	//      调用strFree   /   SafeArrayDestroy 函数，释放动态分配的内存 
	::VariantClear( &m_avLocal );
	::VariantClear( &m_avRemote );
	::VariantClear( &m_avCompareFile );
}

// =======================================================================
// Function name  : SetDataType
// Description    : 仅解析xml文件时，调用此函数
//                  根据DateType属性子节点的值，
//                  设置m_avLocal 和 m_avRemote 的数据类型vt，
//                  并将其值初始化为0  - 此步骤是需要的，
//                  因为无论VariantInit 还是 VariantClear都不会初始化变量值
//                  此外，还会设置m_bySize(String 数据类型除外)
// Additional     ：String：
// Return type    : 
// Parameters     :
// Author         : WangDong 2010.12.06 16:40:00
// =======================================================================
void CAliasItem::SetDataType( DataType value )
{
	m_eDataType = value;

	VARTYPE vt = VT_EMPTY;
	switch( m_eDataType )
	{
	    case ALIAS_BOOLEAN:            // bool
			{
                vt = VT_BOOL;
				m_bySize = 1;
			}
		break;
		case ALIAS_INTEGER:            // short
			{
				vt = VT_I2;
                m_bySize = 1;
			}
		break;
		case ALIAS_UINTEGER:
			{
				vt = VT_UI2;           // unsigned short
				m_bySize = 1;
			}
		break;
		case ALIAS_LONG:
		case ALIAS_LONGSWAP:
			{
				vt = VT_I4;           // long
				m_bySize = 2;
			}
		break;
		case ALIAS_FLOAT:
		case ALIAS_FLOATSWAP:
			{
				vt = VT_R4;           // float
				m_bySize = 2;
			}
		break;
		case ALIAS_STRING:            // CHAR*
			{
                vt = VT_BUF;         
			}
		break;
		case ALIAS_UNKNOWN:
		default:
			ASSERT(m_eDataType == ALIAS_UNKNOWN);
            m_eDataType = ALIAS_UNKNOWN;
            vt = V_VT(&m_avLocal);
			return;
	}// switch

	// Set vt of m_avLocal, m_avRemote and m_avCompareFile, and Initialized 0
    V_VT(&m_avLocal) = vt;         // m_avLocal.vt = vt;
	V_UI8(&m_avLocal) = 0;

	V_VT(&m_avRemote) = vt;
	V_UI8(&m_avRemote) = 0;

	V_VT(&m_avCompareFile) = vt;
	V_UI8(&m_avCompareFile) = 0;

	/* 当m_avLocal的类型为BSTR时：
	//            如果入参数据类型为ALIAS_STRING时：将 BSTR -> CHAR*, 并设置数据类型为VT_BUF，初始化数据为0
	//            否则，采用VariantChangeType转换数据类型
	// 不为BSTR时：
	              同自己的流程
	// Convert existing BSTR value to new datatype
    HRESULT hr = S_OK;
    if (V_VT(&m_avLocal) == VT_BSTR)
    {
      // Manually convert string and array buffer
      if (vt == VT_BUF)
      {
        char* scratch = WideToAnsi( V_BSTR(&m_avLocal) );
        ::VariantClear(&m_avLocal);
        V_VT(&m_avLocal) = vt;
        V_UI8(&m_avLocal) = 0;
        V_I1REF(&m_avLocal) = scratch;
      }
      else
      {
        // Use automation to convert other types
        hr = ::VariantChangeType(&m_avLocal, &m_avLocal, 0, vt);
        ASSERT(hr == S_OK);
        if (hr != S_OK)
        {
          ::VariantClear(&m_avLocal);
        }
      }
    }
    else
    {
        // Force manual initialization
        hr = S_FALSE;
    }

    // Manually initialize the variant (either there is no BSTR value, or the
    // conversion failed).
    if (hr != S_OK)
    {
      // Initialize any big member variable
      V_VT(&m_avLocal) = vt;
      V_UI8(&m_avLocal) = 0;
    }

    // Always clear remote value
    V_VT(&m_avRemote) = vt;
    V_UI8(&m_avRemote) = 0; */
}

// =======================================================================
// Function name: SetStringSize
// Description  : 仅解析xml文件时，调用此函数
//                设定"String"数据类型含有字符的数目，
//                并初始化其值为0
// Return type  : void
// Parameters   : BYTE value: byte count of the string
// Author       : WangDong 2010.12.06 16:40:00
// =======================================================================
void CAliasItem::SetStringSize( BYTE value ) 
{
	if( ALIAS_STRING != m_eDataType )
	{
		return;
	}

	// 初始化 value 个字符为 0
	if((m_bySize != value) || (V_VT(&m_avLocal) != VT_BUF))
    {  
        VariantAllocateBuffer(m_avLocal, value);
    }

    if((m_bySize != value) || (V_VT(&m_avRemote) != VT_BUF))
    {
        VariantAllocateBuffer(m_avRemote, value);
    }

	if((m_bySize != value) || (V_VT(&m_avRemote) != VT_BUF))
    {
        VariantAllocateBuffer(m_avCompareFile, value);
    }

	m_bySize = value;
}

// =======================================================================
// Function name:
// Description  : 根据参数的数据类型，设置m_avLocal
//                如果标志位m_DirtyLocal为false，则更新此标志位；否则不更新
//                说明：标志为true时，表示参数被改变，保持不变，以表示本地数据是被改变了的
//                当数据类型非法(ALIAS_UNKOWN或其它)时，设置其数据类型为BSTR,并赋值，需要测试！
// Application  : 1. XML Parser: Set Default Value
// Return type  : void
// Parameters   : LPCTSTR szValue: value to be setted
// Author       : WangDong 2010.12.06 16:40:00
// =======================================================================
void CAliasItem::SetValue( const CString& strValue, bool bCompareFile )
{
	LPCTSTR szValue = (LPCTSTR)strValue;
	ASSERT( szValue );
	if( !szValue )
	{
		return;
	}

	int nSuccessFields = 0;
    switch( m_eDataType )
	{
	    case ALIAS_INTEGER:       // SHORT
			{
				ASSERT( VT_I2  == V_VT(&m_avLocal));                    
				int nValue = 0;
				nSuccessFields = ::swscanf_s( szValue, L"%d", &nValue ); 
				ASSERT( nSuccessFields );
				if( nSuccessFields )
				{
					if( !bCompareFile )
					{
						// Update m_bDirtyLocal
						if( !m_bDirtyLocal )
						{
							m_bDirtyLocal = (V_I2(&m_avLocal) != static_cast<short>(nValue));
						}

						// Set m_avLocal
						V_I2(&m_avLocal) = static_cast<short>(nValue); 
					}
					else
					{
                        // Compare file, set m_avCompareFile
						ASSERT( VT_I2  == V_VT(&m_avCompareFile));  
						V_I2(&m_avCompareFile) = static_cast<short>( nValue ); 
					}
				}
			}
		break;
		case ALIAS_UINTEGER:     // USHORT
			{
				ASSERT( VT_UI2 == V_VT(&m_avLocal));
	            UINT uValue = 0;
				nSuccessFields = ::swscanf_s( szValue, L"%u", &uValue );
				ASSERT( nSuccessFields );
				if( nSuccessFields )
				{
					if( !bCompareFile )
					{
						// Update m_bDirtyLocal
						if( !m_bDirtyLocal )
						{
							m_bDirtyLocal = (V_UI2(&m_avLocal) != static_cast<USHORT>(uValue));
						}

						// Set m_avLocal
						V_UI2(&m_avLocal) = static_cast<USHORT>( uValue );
					}
					else
					{
						// Compare file, set m_avCompareFile
						ASSERT( VT_UI2 == V_VT(&m_avCompareFile));
						V_UI2(&m_avCompareFile) = static_cast<short>( uValue ); 
					}
				}
			}
		break;
		case  ALIAS_FLOAT:
		case  ALIAS_FLOATSWAP:   // float
			{
				ASSERT( VT_R4 == V_VT(&m_avLocal));
				float fValue = 0.0f;
				nSuccessFields = ::swscanf_s( szValue, L"%f", &fValue );       
				ASSERT( nSuccessFields );
				if( nSuccessFields )
				{
					if( !bCompareFile )
					{
						// Update m_bDirtyLocal
						if( !m_bDirtyLocal )
						{
							m_bDirtyLocal = (fabs( V_R4(&m_avLocal)-fValue) > EPSILON_FLT);    //(V_R4(&m_avLocal) != fValue);
						}

						// Set m_avLocal
						V_R4(&m_avLocal) = fValue;	
					}
					else
					{
						// Compare file, set m_avCompareFile
						ASSERT( VT_R4 == V_VT(&m_avCompareFile));
						V_R4(&m_avCompareFile) = fValue; 
					}
				}
			}
		break;
		case ALIAS_LONG:
		case ALIAS_LONGSWAP:     // long
			{
                ASSERT( VT_I4 == V_VT(&m_avLocal));
				long lValue = 0;
				nSuccessFields = ::swscanf_s( szValue, L"%ld", &lValue );        //long 为32位时，没有问题
				ASSERT( nSuccessFields );
				if( nSuccessFields )
				{
					if( !bCompareFile )
					{
						// Update m_bDirtyLocal
						if( !m_bDirtyLocal )
						{
							m_bDirtyLocal = (V_I4(&m_avLocal) != lValue);
						}

						// Set m_avLocal
						V_I4(&m_avLocal) = lValue;
					}
					else
					{
						// Compare file, set m_avCompareFile
						ASSERT( VT_I4 == V_VT(&m_avCompareFile));
						V_I4(&m_avCompareFile) = lValue; 
					}
				}
			}
		break;
		case ALIAS_BOOLEAN:     // bool
			{
                ASSERT( VT_BOOL == V_VT(&m_avLocal));
                
				// 判断首字符是否是10进制数字，如果不是，则比较字符串"true"/"false"；
			    //                           如果是，则判断此数字是否非零
				VARIANT_BOOL bValue = VARIANT_FALSE;
				if( ::isdigit( szValue[0] ))   // true: the element tested is a numeric character
				{
					int nValue = 0;
					nSuccessFields = ::swscanf_s( szValue, L"%d", &nValue );
					ASSERT( nSuccessFields );
				    if( !nSuccessFields )
					{
                        break;
					}

					bValue = (nValue != 0);
				}
				else if( ::lstrcmpiW( szValue, L"True") == 0 )
				{
					bValue = TRUE;
				}
				else
				{
					bValue = FALSE;
				}

				if( !bCompareFile )
				{
					// Update m_bDirtyLocal
					if( !m_bDirtyLocal )
					{
						m_bDirtyLocal = (V_BOOL(&m_avLocal) != bValue);
					}

					// Set m_avLocal
					V_BOOL(&m_avLocal) = bValue;
				}
				else
				{
					// Compare file, set m_avCompareFile
					ASSERT( VT_BOOL == V_VT(&m_avCompareFile));
					V_BOOL(&m_avCompareFile) = bValue; 
				}
			}
		break;
		case ALIAS_STRING:    // char* 
			{
				ASSERT( VT_BUF == V_VT(&m_avLocal)); 

				if( !bCompareFile )
				{
					// Update m_bDirtyLocal
					if( !m_bDirtyLocal )
					{
						m_bDirtyLocal = (::strcmp(V_BUF(&m_avLocal), CW2A(szValue)) != 0);
					}

					// Set m_avLocal
					::strncpy_s( V_BUF(&m_avLocal), m_bySize+1, CW2A(szValue), m_bySize ); 
				}
				else
				{
					// Compare file, set m_avCompareFile
					ASSERT( VT_BUF == V_VT(&m_avCompareFile)); 
					::strncpy_s( V_BUF(&m_avCompareFile), m_bySize+1, CW2A(szValue), m_bySize ); 
				}
			}
		break;
		case ALIAS_UNKNOWN:
		default:
			{
				if( !bCompareFile )
				{
					V_VT(&m_avLocal) = VT_BSTR;
					V_BSTR(&m_avLocal) = _bstr_t(szValue);
				}
				else
				{
					V_VT(&m_avCompareFile) = VT_BSTR;
					V_BSTR(&m_avCompareFile) = _bstr_t(szValue);
				}
			}
	}// case
}

// =======================================================================
// Function name: IsReadOnly / IsWriteable / IsTuning
// Description  : 
// Return type  : void
// Parameters   : 
// Author       : WangDong 2011.01.06 10:40:00
// =======================================================================
bool CAliasItem::IsReadOnly()  const
{
	if(((m_nAlias >= 10001) && (m_nAlias <= 20000)) ||
	   ((m_nAlias >= 30001) && (m_nAlias <= 40000)))
	{
		return true;
	}

	return false;
}

//------------------------------------------------------------------------
bool CAliasItem::IsWriteable()  const
{
    return !IsReadOnly();
}

//------------------------------------------------------------------------
bool CAliasItem::IsTuning()     const
{
	return (GetProtectType() == PROTECT_TUNE);
}

// =======================================================================
// Function name: valBOOL / valI2 / valUI2  / valI4  / valR4 / valString
// Description  : Set m_avLocal and m_bDirtyLocal flag except valString
// Return type  : void
// Parameters   : 
// Author       : WangDong 2011.01.10 19:40:00
// =======================================================================
void CAliasItem::valBool( BOOL value )
{
    ASSERT( V_VT(&m_avLocal) == VT_BOOL );
	if( V_BOOL(&m_avLocal) != value )
	{
		m_bDirtyLocal = true;
		V_BOOL(&m_avLocal) = value;
	}
}

void CAliasItem::valI2( short value )
{
    ASSERT( V_VT(&m_avLocal) == VT_I2 );
	if( V_I2(&m_avLocal) != value )
	{
		m_bDirtyLocal = true;
		V_I2(&m_avLocal) = value;
	}
}

void  CAliasItem::valUI2( USHORT value )
{
	ASSERT( V_VT(&m_avLocal) == VT_UI2 );
	if( V_UI2(&m_avLocal) != value )
	{
		m_bDirtyLocal = true;
		V_UI2(&m_avLocal) = value;
	}
}

void  CAliasItem::valI4( long value )
{
	ASSERT( V_VT(&m_avLocal) == VT_I4 );
	if( V_I4(&m_avLocal) != value )
	{
		m_bDirtyLocal = true;
		V_I4(&m_avLocal) = value;
	}
}

void  CAliasItem::valR4( float value )
{
	ASSERT( V_VT(&m_avLocal) == VT_R4 );
	if( fabs(V_R4(&m_avLocal)-value) > EPSILON_FLT )  //if( V_R4(&m_avLocal) != value )
	{
		m_bDirtyLocal = true;
		V_R4(&m_avLocal) = value;
	}
}

void CAliasItem::valString( const char* value )
{
	ASSERT( VT_BUF == V_VT(&m_avLocal)); 
	if( ::strcmp( V_BUF(&m_avLocal), value) != 0 )
	{
		//m_bDirtyLocal = true;    // Don't need to set, only set it when user change local value
		::strncpy_s( V_BUF(&m_avLocal), m_bySize+1, value, m_bySize );  // Set mvLocal
	}
}

//======================================================================
// Function name: remBool / remI2  / remUI2  / remI4 / remR4
// Description  : Set m_avRemote, and update m_bDirtyRemote flag
// Return type  : void
// Parameters   : 
// Author       : WangDong 2011.02.24 18:40:00
// =======================================================================
void CAliasItem::remBool( BOOL value )
{
	ASSERT( V_VT(&m_avRemote) == VT_BOOL );
    if( remBool() != value )
	{
        V_BOOL( &m_avRemote ) = value;
	}

	m_bDirtyRemote = ( V_BOOL(&m_avRemote) != V_BOOL(&m_avLocal));
}

void CAliasItem::remI2( short value )
{
	ASSERT( V_VT(&m_avRemote) == VT_I2 );
    if( value != remI2())
	{
        V_I2( &m_avRemote ) = value;
	}

	m_bDirtyRemote = ( V_I2(&m_avRemote) != V_I2(&m_avLocal));
}

void CAliasItem::remUI2( USHORT value )
{
    ASSERT( V_VT(&m_avRemote) == VT_UI2 );
    if( value != remUI2())
	{
        V_UI2( &m_avRemote ) = value;
	}

	m_bDirtyRemote = ( V_UI2(&m_avRemote) != V_UI2(&m_avLocal));
}

void CAliasItem::remI4( long value )
{
	ASSERT( V_VT(&m_avRemote) == VT_I4 );
    if( value != remI4())
	{
        V_I4( &m_avRemote ) = value;
	}

	m_bDirtyRemote = ( V_I4(&m_avRemote) != V_I4(&m_avLocal));
}

void  CAliasItem::remR4( float value )
{
	ASSERT( V_VT(&m_avRemote) == VT_R4 );
    if( fabs(value-remR4()) > EPSILON_FLT )    //if( value != remR4())
	{
        V_R4( &m_avRemote ) = value;
	}

	m_bDirtyRemote = ( V_R4(&m_avRemote) != V_R4(&m_avLocal));
}

void CAliasItem::remString( const char* value )
{
	ASSERT( VT_BUF == V_VT(&m_avRemote)); 
	if( ::strcmp( V_BUF(&m_avRemote), value) != 0 )
	{
		::strncpy_s( V_BUF(&m_avRemote), m_bySize+1, value, m_bySize );  // Set mvRemote
	}

	m_bDirtyRemote = (::_stricmp( V_BUF(&m_avRemote), V_BUF(&m_avLocal)) != 0); 
}

//=======================================================================
// Function name: SetDataDump
// Description  : When read, set m_avRemote, and update m_bDirtyRemote flag
// Return type  : void
// Parameters   : 
// Author       : WangDong 2011.02.24 18:40:00
// =======================================================================
HRESULT CAliasItem::SetDataDump( const BYTE* aDump )
{
	HRESULT hr = S_OK;

    ASSERT( m_bySize > 0 );
	ASSERT( aDump != NULL );

	if( m_bySize == 0 )
	{
		hr = E_FAIL;        // Unspecified error
	}
	else if( !CheckReadPtr( aDump, m_bySize*sizeof(BYTE)))
	{
		hr = E_INVALIDARG;  // One or more arguments are invalid
	}

	if( hr == S_OK )
	{
        DWORD dwValue = 0;
		float fValue = 0.0;
	   
        switch( m_eDataType )
	    {
		    case ALIAS_INTEGER:
				ASSERT( V_VT(&m_avRemote) == VT_I2 );

		        dwValue = (aDump[0]<<8) | aDump[1];
			    if( V_I2(&m_avRemote) != static_cast<SHORT>(dwValue))
			    {
			        V_I2(&m_avRemote) = static_cast<SHORT>(dwValue);  
			    }
				m_bDirtyRemote = (V_I2(&m_avRemote) != V_I2(&m_avLocal));
		        break;

			case ALIAS_UINTEGER:
			    ASSERT( V_VT(&m_avRemote) == VT_UI2 );

		        dwValue = (aDump[0]<<8) | aDump[1];
			    if( V_UI2(&m_avRemote) != static_cast<USHORT>(dwValue))
			    {
			        V_UI2(&m_avRemote) = static_cast<USHORT>(dwValue);  
			    }
				m_bDirtyRemote = (V_UI2(&m_avRemote) != V_UI2(&m_avLocal));
		        break;

		    case ALIAS_LONG:
			case ALIAS_LONGSWAP:
			    ASSERT( V_VT(&m_avRemote) == VT_I4 );

				if( m_eDataType == ALIAS_LONG )
				{
				    dwValue = (((aDump[2] << 8) | aDump[3]) << 16) |
                              (((aDump[0] << 8) | aDump[1]));
				}
				else
				{
					dwValue = (((aDump[0] << 8) | aDump[1]) << 16) |
                              (((aDump[2] << 8) | aDump[3]));
				}

				if( V_I4(&m_avRemote) != static_cast<LONG>(dwValue))
				{
                    V_I4(&m_avRemote) = (int) dwValue;
				}
                m_bDirtyRemote = (V_I4(&m_avLocal) != V_I4(&m_avRemote));
                break;

		    case ALIAS_FLOAT:     //@fallthrough@
            case ALIAS_FLOATSWAP:
				ASSERT( V_VT(&m_avRemote) == VT_R4 );

                if( m_eDataType == ALIAS_FLOAT )
                {
                    dwValue = (((aDump[2] << 8) | aDump[3]) << 16) |
                              (((aDump[0] << 8) | aDump[1]));
                }
                else
                {
                    dwValue = (((aDump[0] << 8) | aDump[1]) << 16) |
                              (((aDump[2] << 8) | aDump[3]));
                }

                fValue = *(float*)&dwValue;

                if( _isnan( fValue ) || ((fValue > 0.0) && (fValue < FLT_EPSILON)))
                {
					/*
                    if (GLogCheck(TLogMessage::lmWarning))
                    {
                        AnsiString s;
                        s.printf("SetDataDump - %s - Invalid float: %08x",
                                m_strName.c_str(), fValue);
                        GLogWarning(ALIAS_CAT, s);
                    }*/

                    fValue = 0.0;
                }
				
				if( fabs(V_R4(&m_avRemote)-fValue) > EPSILON_FLT )    //if( V_R4(&m_avRemote) != fValue )
				{
                    V_R4(&m_avRemote) = fValue;
				}
                m_bDirtyRemote = (V_R4(&m_avLocal) != V_R4(&m_avRemote));
                break;

			case ALIAS_STRING:
            {
                ASSERT(V_VT(&m_avLocal) == VT_BUF);
                ASSERT(V_VT(&m_avRemote) == VT_BUF);

                if((V_VT(&m_avRemote) != VT_BUF)  ||
                   (V_I1REF(&m_avRemote) == NULL))
                {
                    VariantAllocateBuffer(m_avRemote, m_bySize);
                }

                // Compare strings
                const char* src = reinterpret_cast<const char*>( aDump );
                char* dest = V_I1REF( &m_avRemote );
                if( ::strcmp( src, dest ) != 0 )
                {
					::strncpy_s( dest, m_bySize, src, m_bySize );
                }

				m_bDirtyRemote = (::strcmp( V_I1REF(&m_avRemote), V_I1REF(&m_avRemote)) != 0);
                break;
            }

			case ALIAS_UNKNOWN:
			default:
				hr = S_FALSE;
        }//switch( m_eDataType )
	}//if( hr == S_OK )

    return hr;
}

//======================================================================
// Function name: GetDataDump
// Description  : When write multiple analog, make databytes
// Return type  : HRESULT
// Parameters   : aDump: Point to the first data byte
// Author       : WangDong 2011.02.28 09:30:00
// =======================================================================
HRESULT CAliasItem::GetDataDump( BYTE* aDump ) const
{
	ASSERT( m_bySize > 0 );
    ASSERT( aDump != NULL );

	if( m_bySize == 0 )
	{
		return S_FALSE;
	}

    if( aDump == NULL )
	{
		return E_POINTER;
	}

	switch( m_eDataType )
	{
	    case ALIAS_INTEGER:
			aDump[0] = HIBYTE( V_I2(&m_avLocal));
			aDump[1] = LOBYTE( V_I2(&m_avLocal));
		break;

		case ALIAS_UINTEGER:
			aDump[0] = HIBYTE( V_UI2(&m_avLocal));
			aDump[1] = LOBYTE( V_UI2(&m_avLocal));
		break;

		case ALIAS_FLOAT:
		case ALIAS_LONG:
			aDump[0] = static_cast<BYTE>((V_UI4(&m_avLocal) >> 8)  & 0xff);
			aDump[1] = static_cast<BYTE>((V_UI4(&m_avLocal)     )  & 0xff); 
			aDump[2] = static_cast<BYTE>((V_UI4(&m_avLocal) >> 24) & 0xff);
			aDump[3] = static_cast<BYTE>((V_UI4(&m_avLocal) >> 16) & 0xff);
		break;

		case ALIAS_FLOATSWAP:
		case ALIAS_LONGSWAP:
			aDump[0] = static_cast<BYTE>((V_I4(&m_avLocal) >> 24)  & 0xff);
			aDump[1] = static_cast<BYTE>((V_I4(&m_avLocal) >> 16)  & 0xff); 
			aDump[2] = static_cast<BYTE>((V_I4(&m_avLocal) >> 8 )  & 0xff);
			aDump[3] = static_cast<BYTE>((V_I4(&m_avLocal)      )  & 0xff);
		break;

		case ALIAS_STRING:
			if( V_I1REF(&m_avLocal) != NULL )
			{
				memcpy( aDump, V_I1REF(&m_avLocal), m_bySize*sizeof(BYTE));
			}
		break;

		case ALIAS_UNKNOWN:
		default:
		  return S_FALSE;
	}//switch

	return S_OK;
}

//======================================================================
// Function name: CopyRemoteToLocal / CopyRemoteToLocal
// Description  : Copy VARIANT, and Set m_bDirtyRemote Flag false
// Return type  : void
// Parameters   : 
// Author       : WangDong 2011.02.24 18:40:00
// =======================================================================
void CAliasItem::CopyRemoteToLocal( void )
{
	ASSERT( V_VT(&m_avLocal) == V_VT(&m_avRemote));
	if( V_VT(&m_avLocal) == V_VT(&m_avRemote) )
	{
		m_avLocal = m_avRemote;
		m_bDirtyRemote = false;
	}
}

void CAliasItem::CopyLocalToRemote( void )
{
	ASSERT( V_VT(&m_avRemote) == V_VT(&m_avLocal));
	if( V_VT(&m_avRemote) == V_VT(&m_avLocal) )
	{
		m_avRemote = m_avLocal;
		m_bDirtyRemote = false;
	}
}

//======================================================================
// Function name: UpdateRemoteFlags
// Description  : Update m_bDirtyRemote flags
// Return type  : void
// Parameters   : 
// Author       : WangDong 2011.03.18 11:15:00
// =====================================================================
void CAliasItem::UpdateRemoteFlags( void )
{
    ASSERT( V_VT(&m_avRemote) == V_VT(&m_avLocal));
	if( V_VT(&m_avRemote) == V_VT(&m_avLocal) )
	{
		if( m_eDataType == ALIAS_UNKNOWN )
		{
			return;
		}

		if( m_eDataType != ALIAS_STRING )
		{
			_variant_t Remote_t( &m_avRemote );
		    _variant_t Local_t( &m_avLocal );
            m_bDirtyRemote = (Remote_t != Local_t);
		}	
	}
}

//======================================================================
// Function name: GetLocalValueString
// Description  : 
// Return type  : void
// Parameters   : 
// Author       : WangDong 2011.03.23 13:41:00
// =====================================================================
void CAliasItem::GetLocalValueString( CString& strValue ) const
{
	VariantToString( m_avLocal, strValue );
}

// =======================================================================
/// CAliasMap
// 构造函数 与 析构函数
/// <summary>
///   </summary>
/// <created>
///   rjvs 2002-01-23 17:15:09 (UTC-6:00)</created>
CAliasMap::CAliasMap()
          : inherited(),
		    m_AliasNameMap()
{
	m_AliasNameMap.clear();
}

/// <summary>
///   Destructor</summary>
/// <created>
///   rjvs 2002-01-23 17:15:25 (UTC-6:00)</created>
CAliasMap::~CAliasMap()
{
	clear();
}

/// <summary>
///   Clears all alias items and names in the map.</summary>
/// <created>
///   rjvs 2003-01-14 13:14:55 -06:00</created>
void CAliasMap::clear()
{
	CSingleLock sl( &m_cirsec );
	sl.Lock();
	if( sl.IsLocked())
	{
	    m_AliasNameMap.clear();
	    erase( begin(), end()); 

		sl.Unlock();
	}
}

// =======================================================================
// Function name: find_name, find_num 
// Description  :                              
// Application  : 1.XML Parser: avoid duplicate
// Return type  : NULL: Not Found
//                CAliasItem*: If found, return its second
// Parameters   : LPCTSTR szValue: Name Attribute
//                int nNumber:     Alias Attribute
// Author       : WangDong 2010.12.09 11:20:00
// =======================================================================
CAliasItem* CAliasMap::find_name(LPCTSTR szName)
{
	NameMap::iterator it = m_AliasNameMap.find( szName );
	if( it == m_AliasNameMap.end())        // not found, return NULL
	{
        return NULL;
	}

	return it->second;
}
//----------------------------------------------------------------------

const CAliasItem* 
CAliasMap::find_name(LPCTSTR szName) const
{
	//AnsiString f = AnsiString(szName).UpperCase();
	NameMap::const_iterator it = m_AliasNameMap.find( szName );
	if( it == m_AliasNameMap.end())
	{
		return NULL;
	}

	return it->second; 
}

// =======================================================================
CAliasItem* 
CAliasMap::find_num(int nNumber)
{
	iterator it = find( nNumber );
	if( it == end())
	{
		return NULL;
	}

	return it->second;
}
//----------------------------------------------------------------------

const CAliasItem* 
CAliasMap::find_num(int nNumber) const
{
	const_iterator it = find( nNumber );
	if( it == end())
	{
		return NULL;
	}

	return it->second;
}

//--------------------------------------------------------------------------------------
/// <summary>
///   Adds an alias to the map and checks for duplicate alias numbers.</summary>
/// <param name="pAlias">
///   The alias to add to the map.</param>
/// <created>
///   rjvs 2002-10-04 11:44:15 (UTC-6:00)</created>
void
CAliasMap::Add( CAliasItem* pAlias )
{
	if( CheckReadPtr( pAlias, sizeof( CAliasItem )))
	{
	    int nAlias = pAlias->GetAlias();

		// Check if alias already exists in map
		iterator it = find( nAlias );
		if( it != end() )                 // found 
		{
			if( it->second != pAlias )   
			{
				CString strErr;
				strErr.Format( L"CAliasMap::Add: Deleting duplicate alias number: %d", nAlias );
		        theApp.LogInfo( strErr );

                ASSERT(it == end());
                SAFE_DELETE( pAlias );    
			}
			else  
			{
				CString strErr;
				strErr.Format( L"CAliasMap::Add: Duplicate alias number found: %d", nAlias );
		        theApp.LogInfo( strErr );
			}
		}
		else                           // not found
		{
			insert( value_type( nAlias, pAlias ));
			
			// Add to name map for fast name lookup
			NameMap::iterator name_it = m_AliasNameMap.find( pAlias->GetName());
			if( name_it !=  m_AliasNameMap.end())     // already exists
			{
				CString strErr;
				strErr.Format( L"CAliasMap::Add: Duplicate alias name found: %s", pAlias->GetName());
		        theApp.LogInfo( strErr );
			}
			else                                      
			{
				m_AliasNameMap.insert( NameMap::value_type( pAlias->GetName(), pAlias ));
			}
		}   
	}	        
}

// =======================================================================
// Function name: SetDirtyLocal / SetDirtyRemote
// Description  : Set all Alias Item's dirty information                             
// Return type  : void
// Parameters   : 
// Author       : WangDong 2011.01.04 18:50:00
// =======================================================================
void CAliasMap::SetDirtyLocal( bool bDirty )
{
	for( iterator it = begin(); it != end(); it++ )
	{
		if( it->second != NULL )
		{
		    it->second->SetDirtyLocal( bDirty );
		}
	}
}

void CAliasMap::SetDirtyRemote( bool bDirty )
{
    for( iterator it = begin(); it != end(); it++ )
	{
		if( it->second != NULL )
		{
		    it->second->SetDirtyRemote( bDirty );
		}
	}
}

// =======================================================================
// Function name: SetActive
// Description  : Set Alias Item's Active Flag                             
// Return type  : void
// Parameters   : 
// Author       : WangDong 2011.01.07 10:30:00
// =======================================================================
void CAliasMap::SetActive( bool bActive )
{
	for( iterator it = begin(); it != end(); it++ )
	{
		it->second->SetActive( bActive );
	}
}

// =======================================================================
// Function name: IsTuning
// Description  :                             
// Return type  : 
// Parameters   : 
// Author       : WangDong 2011.03.13 13:45:00
// =======================================================================
bool CAliasMap::IsTuning()
{
	bool bResult = true;
    for( iterator it = begin(); it != end(); it++ )
	{
		CAliasItem* pAlias = it->second;
		if( CheckReadPtr( pAlias, sizeof( CAliasItem)))
		{
			if( !pAlias->IsTuning())
			{
                bResult = false;
				break;
			}
		}
	}

	return bResult;
}

// =======================================================================
// Function name: UpdateRemoteFlags
// Description  : Update m_bDirtyRemote flags                  
// Return type  : 
// Parameters   : 
// Author       : WangDong 2011.03.18 11:00:00
// =======================================================================
void CAliasMap::UpdateRemoteFlags( int nBeginAlias, int nEndAlias )
{
	iterator it = lower_bound( nBeginAlias );
	iterator eit = upper_bound( nEndAlias );

	while( it != eit )
	{
		CAliasItem* pAlias = it->second;
		if( CheckWritePtr( pAlias, sizeof(CAliasItem)))
		{
			pAlias->UpdateRemoteFlags();
		}

		++it;
	}
}

// =======================================================================
// Function name: RangeInclude
// Description  : PROTECT_CONFIGURE and/or PROTECT_TUNE                  
// Return type  : 
// Parameters   : 
// Author       : WangDong 2011.03.18 16:20:00
// =======================================================================
void CAliasMap::RangeInclude( CAliasMap* pMap, int nBegin, int nEnd,
                              AliasProtectSet& P, bool bDirtyOnly )
{
    const_iterator it =  lower_bound( nBegin );
	const_iterator eit = upper_bound( nEnd );

	bool bAdd = false;
	for( ;it != eit; it++ )
	{
		CAliasItem* pAlias = it->second;
		if( CheckReadPtr( pAlias, sizeof(CAliasItem)))
		{
			AliasProtectSet::iterator it = P.find( pAlias->GetProtectType());
			if( it != P.end())  // found
			{
				bAdd = true;

                if( bDirtyOnly )
				{
					bAdd = (pAlias->IsDirtyLocal() || pAlias->IsDirtyRemote());
				}

				if( bAdd )
				{
					pMap->Add( pAlias ); 
				}
			}//found
		}//if pAlias
	}//for
}

// -----------------------------------------------------------------------
// Function name: RangeExclude
// Description  : PROTECT_CALIBRATE: must exclude                 
// Return type  : 
// Parameters   : 
// Author       : WangDong 2011.03.18 16:20:00
// -----------------------------------------------------------------------
void CAliasMap::RangeExclude( CAliasMap* pMap, int nBegin, int nEnd,
                              AliasProtectSet& P, bool bDirtyOnly )
{
	const_iterator it =  lower_bound( nBegin );
	const_iterator eit = upper_bound( nEnd );

	bool bAdd = false;
	for( ;it != eit; it++ )
	{
		CAliasItem* pAlias = it->second;
		if( CheckReadPtr( pAlias, sizeof(CAliasItem)))
		{
			AliasProtectSet::iterator it = P.find( pAlias->GetProtectType());
			if( it == P.end())  // not found
			{
				bAdd = true;

                if( bDirtyOnly )
				{
					bAdd = (pAlias->IsDirtyLocal() || pAlias->IsDirtyRemote());
				}

				if( bAdd )
				{
					pMap->Add( pAlias ); 
				}
			}//not found
		}//if pAlias
	}//for
}

//==================================================================================
/// <summary>
///   Destructor for alias map that 'owns' the aliases and deletes them. </summary>
/// <created>
///   rjvs 2002-01-23 17:15:25 (UTC-6:00)</created>
COwnedAliasMap::~COwnedAliasMap()
{
    for( iterator it = begin(); it != end(); ++it )
    {
        SAFE_DELETE(it->second);
    }

    erase(begin(), end());
}

/// <summary>
///   Clears and deletes all alias items in the map.</summary>
/// <created>
///   rjvs 2003-01-14 13:14:55 -06:00</created>
void
COwnedAliasMap::clear()
{
	CSingleLock sl( &m_cirsec );
	sl.Lock();
	if( sl.IsLocked())
	{
		m_AliasNameMap.clear();

		iterator  it = begin();
		iterator eit = end();

		while (it != eit)
		{
			SAFE_DELETE(it->second);
			++it;
		}

		erase(begin(), end());

		sl.Unlock();
	}
}
//----------------------------------------------------------------------------------