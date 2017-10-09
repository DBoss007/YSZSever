﻿/*****************************************************************************
Copyright (C), 2013-2015, ***. Co., Ltd.
文 件 名:  SHA1.cpp
作    者:     
版    本:  1.0
完成日期:  2013-8-9
说明信息:  基于OpenSSL的SHA1算法
*****************************************************************************/
#include "SHA1.h"

SHA1::SHA1(void)
{
	SHA1_Init(&m_cSHA1);
}

SHA1::~SHA1(void)
{
}

//********************************************************************
//函数功能: 更新数据
//第一参数: [IN] 需要加密的字符串
//返回说明: 
//备注说明: 
//********************************************************************
void SHA1::Update(const String &strDate)
{
	SHA1_Update(&m_cSHA1, strDate.c_str(), strDate.length());
}

//********************************************************************
//函数功能: 更新数据
//第一参数: [IN] 需要加密的字符串
//第一参数: [IN] 需要加密的字符串长度 strlen(szDate)
//返回说明: 
//备注说明: 
//********************************************************************
void SHA1::Update2(const uint8 *szDate, uint32 nLen)
{
	if (szDate == NULL)
	{
		return;
	}

	SHA1_Update(&m_cSHA1, szDate, nLen);
}

//********************************************************************
//函数功能: 完成加密, 返回十六进制加密后的字符串
//第一参数: 
//返回说明: 
//备注说明: 
//********************************************************************
String SHA1::ToString(void)
{
	SHA1_Final(m_szData, &m_cSHA1);
	SHA1_Init(&m_cSHA1);
	String strData = CStringTools::BytesToHexString(m_szData, SHA_DIGEST_LENGTH);
	return strData;
}

//********************************************************************
//函数功能: 完成加密, 返回加密后的原始数据
//第一参数: 
//返回说明: 
//备注说明: 
//********************************************************************
String SHA1::GetFinalData(void)
{
	SHA1_Final(m_szData, &m_cSHA1);
	SHA1_Init(&m_cSHA1);
	String strData((char *)m_szData);
	return strData;
}