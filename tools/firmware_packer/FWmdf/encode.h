//------------------------------------------------------------------------------------------------------------
//
//2009-04-18 16:02:07
//
//scott
//
//encode.h
//
// ����rc6�ļ����㷨ģ��
//
//------------------------------------------------------------------------------------------------------------

#ifndef __ENCODE___H__
#define __ENCODE___H__

//------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------

typedef unsigned int u32;
typedef unsigned char u8;

#define OK				0
#define NULL			0

#define ENCODE_LEN		16				//һ�μ���16���ֽ�

typedef void * HENCODE;

//------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------

HENCODE Initial(void * param0, void * param1);

#ifdef __RC_ENCODE__
u32     Encode(HENCODE hEncode, void * ibuf, void * obuf);
#endif //__RC_ENCODE__

#ifdef __RC_DECODE__
u32		Decode(HENCODE hEncode, void * ibuf, void * obuf);
#endif //__RC_DECODE__

u32		UnInitial(HENCODE hEncode);


//------------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------------
#endif //__ENCODE___H__

